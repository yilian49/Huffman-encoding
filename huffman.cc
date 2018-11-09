#include "huffman.hh"
#include "hforest.hh"
#include "htree.hh"

#include <cassert>

///////////////////////////////////////////////////////////////////////////////////////

Huffman::~Huffman(){}

///////////////////////////////////////////////////////////////////////////////////////

Huffman::Huffman(){
    table_ = std::vector<int>(257, 0);
}
///////////////////////////////////////////////////////////////////////////////////////

HTree::tree_ptr_t
Huffman::create_huffman_tree(){
    
    HForest forest;

    for(long unsigned int i=0 ; i < table_.size(); i++){
        forest.add_tree(HTree::tree_ptr_t(new HTree(i, table_[i])));
    }

    while(forest.size() > 1){

        auto node1 = forest.pop_top();
        auto node2 = forest.pop_top();

        auto total = node1 -> get_value() + node2 -> get_value();
        forest.add_tree(HTree::tree_ptr_t(new HTree(-1, total, node1, node2)));
    }

    assert(forest.size() == 1);
    return forest.pop_top(); 
}

///////////////////////////////////////////////////////////////////////////////////////

Huffman::bits_t
Huffman::encode(int symbol){

    std::vector<bool> bits;

    hufftree_ = create_huffman_tree();
    auto path = hufftree_ -> path_to(symbol);

    for(auto dir : path){
        if(dir == HTree::Direction::LEFT){
            bits.push_back(false);
        }
        else{
            bits.push_back(true);
        }
    }

    ++table_[symbol];
    return bits;
}

///////////////////////////////////////////////////////////////////////////////////////

int
Huffman::decode(bool bit){

    if(hufftree_ == nullptr){
        hufftree_ = Huffman::create_huffman_tree();
    }

    if(bit){
        hufftree_ = hufftree_ -> get_child(HTree::Direction::RIGHT);
    }
    else{
        hufftree_ = hufftree_ -> get_child(HTree::Direction::LEFT);
    }

    auto key = hufftree_ -> get_key();

    if(key > -1){
        ++table_[key];
        hufftree_ = create_huffman_tree();
        return key;
    }

    return -1;
}


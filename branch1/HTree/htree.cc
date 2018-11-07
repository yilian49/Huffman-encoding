#include "htree.hh"
#include <cassert>

/////////////////////////////////////////////////////////////////////////////////////

HTree::HTree(int key,
        uint64_t value,
        tree_ptr_t left = nullptr,
        tree_ptr_t right = nullptr)
    
    :   key_(key), value_(value), left_(left), right_(right)
    {
    }

/////////////////////////////////////////////////////////////////////////////////////

int
HTree::get_key() const{
    return key_;
}

/////////////////////////////////////////////////////////////////////////////////////

uint64_t
HTree::get_value() const{
    return value_;
}

/////////////////////////////////////////////////////////////////////////////////////

tree_ptr_t 
HTree::get_child(Direction dir) const{

    
        if(c == 1 && left_){
            return left_;
        }
        else if(c == 2 && right_){
            return right_;
        }
        else{
            return nullptr;
        }
}

/////////////////////////////////////////////////////////////////////////////////////

bool 
HTree::isKeyInTree(key_t key){

    if(key_ == key){
        return true;
    }
    if(left_ && left_ -> isKeyInTree(key) || right_ && right_ -> isKeyInTree(key)){
        return true;
    }
    return false;
}

/////////////////////////////////////////////////////////////////////////////////////

path_t
HTree::path_to(int key) const{

    if(!isKeyInTree(key)){
        assert(false);
    }

    if (tree->key_ == key) {
        return [];
    } 

    else if (tree->left_ && isKeyInTree(tree->left_, key)) {
        return [Direction.LEFT] + left_ -> path_to(key);
    } 

    else { 
        return [Direction.RIGHT] + right_ -> path_to(key);
  }
}
#include "hforest.hh"
#include <algorithm>

//////////////////////////////////////////////////////////////////////////////////////

HForest::HForest(Htree htree){
    collection.push_back(htree)
    }

//////////////////////////////////////////////////////////////////////////////////////

int
HForest::size(){
    return collection.size();
}

//////////////////////////////////////////////////////////////////////////////////////

void
HForest::add_tree(HTree htree){
    collection.push_back(htree);
}

//////////////////////////////////////////////////////////////////////////////////////

HTree
HForest::pop_tree(){
    
    std::make_heap(collection.begin(), collection.end());
    std::pop_heap (collection.begin(), collection.end()); 
    return collection.pop_back();
    
}
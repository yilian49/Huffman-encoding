#include "htree.cc"
#include <iostream>

using namespace std;

tree_ptr_t create_tree_helper(){

    HTree leaf1 = new HTree(1, 10, nullptr, nullptr);
    HTree leaf2 = new HTree(2, 20, nullptr, nullptr);

    HTree branch1 = new HTree(3, 30, leaf1);
    HTree branch2 = new HTree(4, 40, nullptr, leaf2);

    HTree htree = new HTree(5, 50, branch2, branch1);

    return htree;
}

int main(){

    HTree htree = create_tree_helper();                             

    path_t s = htree -> path_to(2);                                          
    cout << s << endl;


    tree_ptr_t result = htree -> get_child(Direction.LEFT);                       
    
    if(result == nullptr){
        cout << "NULLPTR" << endl;
    }    
    else{
        cout << result -> key_ << endl;
    }                    

    return 0;
}
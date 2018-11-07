#include "hforest.cc"
#include <iostream>

using namespace std;

HForest create_forest(){

    HTree oak = new HTree(1, 10, nullptr, nullptr);

    HForest forest = new HForest(oak);

    HTree banyan = new HTree(2, 20, nullptr, nullptr);
    forest -> add_tree(banyan);
    HTree palm = new HTree(3, 30, leaf1);
    forest -> add_tree(palm);
    HTree birch = new HTree(4, 40, nullptr, leaf2);
    forest -> add_tree(birch);
    HTree sequoia = new HTree(5, 50, branch2, branch1);
    forest -> add_tree(sequoia);

    return forest;
}

int main(){

    HForest forest = create_forest();                             
                                          
    cout << "Size: " << forest -> size() << endl;


    HTree largest = forest -> pop_tree();

    cout << "Largest value: " << largest -> value_ << endl;                                  

    return 0;
}
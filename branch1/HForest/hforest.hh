#pragma once

#include <memory>
#include "htree.cc"


class HForest{

    private:
        std::vector<HTree> collection;

    public:
        HForest(HTree htree);
        ~HTree();

        int size() const;
        void add_tree(HTree htree);
        HTree pop_tree() const;
}


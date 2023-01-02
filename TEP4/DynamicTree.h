#ifndef TEP3_DYNAMICTREE_H
#define TEP3_DYNAMICTREE_H

#include <iostream>
#include <vector>
#include "DynamicNode.h"

template <typename T>
class DynamicTree {
public:
    DynamicTree();
    DynamicTree(DynamicNode<T>* root);
    ~DynamicTree();
    DynamicNode<T> *getRoot() {return root;}
    void printTree();
    bool moveSubtree(DynamicNode<T> *parentNode, DynamicNode<T> *newChildNode);
private:
    DynamicNode<T> *root;
};

template <typename T>
DynamicTree<T>::DynamicTree() {
    root = new DynamicNode<T>;
}

template <typename T>
DynamicTree<T>::~DynamicTree() {
    delete root;
}

template <typename T>
void DynamicTree<T>::printTree() {
    root->printAllBelow();
}

template <typename T>
DynamicTree<T>::DynamicTree(DynamicNode<T>* root) {
    this->root = root;
}

template <typename T>
bool DynamicTree<T>::moveSubtree(DynamicNode<T> *parentNode, DynamicNode<T> *newChildNode) {
    newChildNode->getParent()->removeChild(newChildNode);
    parentNode->addNewChild(newChildNode);
}

template <typename T>
class DynamicTree<DynamicTree<T>>;

#endif

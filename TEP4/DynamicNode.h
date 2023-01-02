//
// Created by Dawid on 04.12.2022.
//

#ifndef TEP_DYNAMICNODE_H
#define TEP_DYNAMICNODE_H

#include <iostream>
#include <vector>

template <typename T> class DynamicNode {
public:
    DynamicNode() {value; parentNode = nullptr;};
    DynamicNode(T value) {this->value = value; parentNode = nullptr;};
    DynamicNode(DynamicNode& other);
    ~DynamicNode();
    void setValue(T iNewVal) { value = iNewVal;};
    int iGetChildrenNumber() {return children.size();};
    void addNewChild();
    void addNewChild(T value);
    DynamicNode* getChild(int childOffset);
    void print() {std::cout << " " << value;};
    void printAllBelow();
    T getValue();
    DynamicNode* getParent() { return parentNode;}
    DynamicNode* operator=(DynamicNode* node);
    void addNewChild(DynamicNode *node);
    void removeChild(DynamicNode *node);

private:
    std::vector<DynamicNode *> children;
    DynamicNode *parentNode;
    T value;

    std::vector<DynamicNode *> copyChildren(DynamicNode * node, DynamicNode* current);
};

template <typename T>
DynamicNode<T>::~DynamicNode() {
    for (DynamicNode* i : children) {
        delete i;
    }
    std::cout << "Deleting " << value << std::endl;
}

template <typename T>
void DynamicNode<T>::addNewChild() {
    DynamicNode* temp = new DynamicNode();
    temp->parentNode = this;
    children.push_back(temp);
}

template <typename T>
DynamicNode<T>* DynamicNode<T>::getChild(int childOffset) {
    return children[childOffset];
}

template <typename T>
void DynamicNode<T>::printAllBelow() {
    print();
    for (int i = 0; i < children.size(); ++i) {
        children[i]->printAllBelow();
    }
}

template <typename T>
T DynamicNode<T>::getValue() {
    return value;
}

template <typename T>
DynamicNode<T>::DynamicNode(DynamicNode& other) {
    parentNode = other.parentNode;
    value = other.value;
    children = copyChildren(&other, this);
}

template <typename T>
std::vector<DynamicNode<T> *> DynamicNode<T>::copyChildren(DynamicNode* node, DynamicNode* current) {
    std::vector<DynamicNode*> newChildren;
    for (int i = 0; i < node->children.size(); ++i) {
        DynamicNode* temp = new DynamicNode(*node->children[i]);
        temp->parentNode = current;
        newChildren.push_back(temp);
    }
    return newChildren;
}

template <typename T>
DynamicNode<T> *DynamicNode<T>::operator=(DynamicNode* node) {
    return new DynamicNode(*node);
}

template <typename T>
void DynamicNode<T>::addNewChild(DynamicNode<T> *node) {
    node->parentNode = this;
    children.push_back(node);
}

template <typename T>
void DynamicNode<T>::removeChild(DynamicNode<T> *node) {
    for (int i = 0; i < children.size(); ++i) {
        if (children[i] == node) children.erase(children.begin() + i);
    }
}

template <typename T>
void DynamicNode<T>::addNewChild(T value) {
    DynamicNode* temp = new DynamicNode(value);
    temp->parentNode = this;
    children.push_back(temp);
}


#endif //TEP_DYNAMICNODE_H

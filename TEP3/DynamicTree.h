#ifndef TEP3_DYNAMICTREE_H
#define TEP3_DYNAMICTREE_H

#include <iostream>
#include <vector>

class DynamicNode;

class DynamicTree {
public:
    DynamicTree();
    DynamicTree(DynamicNode* root);
    ~DynamicTree();
    DynamicNode *getRoot() {return root;}
    void printTree();
    bool moveSubtree(DynamicNode *parentNode, DynamicNode *newChildNode);
private:
    DynamicNode *root;
};

class DynamicNode {
public:
    DynamicNode() {value = 0; parentNode = nullptr;};
    DynamicNode(int value) {this->value = value; parentNode = nullptr;};
    DynamicNode(DynamicNode& other);
    ~DynamicNode();
    void setValue(int iNewVal) { value = iNewVal;};
    int iGetChildrenNumber() {return children.size();};
    void addNewChild();
    void addNewChild(int value);
    DynamicNode* getChild(int childOffset);
    void print() {std::cout << " " << value;};
    void printAllBelow();
    int getValue();
    DynamicNode* getParent() { return parentNode;}
    DynamicNode* operator=(DynamicNode* node);
    void addNewChild(DynamicNode *node);
    void removeChild(DynamicNode *node);

private:
    std::vector<DynamicNode *> children;
    DynamicNode *parentNode;
    int value;

    std::vector<DynamicNode *> copyChildren(DynamicNode * node, DynamicNode* current);
};

#endif

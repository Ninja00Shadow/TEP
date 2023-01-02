//
// Created by Dawid on 13.11.2022.
//

#include "DynamicTree.h"

DynamicNode::~DynamicNode() {
    for (DynamicNode* i : children) {
        delete i;
    }
    std::cout << "Deleting " << value << std::endl;
}

void DynamicNode::addNewChild() {
    DynamicNode* temp = new DynamicNode();
    temp->parentNode = this;
    children.push_back(temp);
}

DynamicNode* DynamicNode::getChild(int childOffset) {
    return children[childOffset];
}

void DynamicNode::printAllBelow() {
    print();
    for (int i = 0; i < children.size(); ++i) {
        children[i]->printAllBelow();
    }
}

int DynamicNode::getValue() {
    return value;
}

DynamicTree::DynamicTree() {
    root = new DynamicNode;
}

DynamicTree::~DynamicTree() {
    delete root;
}

void DynamicTree::printTree() {
    root->printAllBelow();
}

DynamicTree::DynamicTree(DynamicNode* root) {
    this->root = root;
}

bool DynamicTree::moveSubtree(DynamicNode *parentNode, DynamicNode *newChildNode) {
    newChildNode->getParent()->removeChild(newChildNode);
    parentNode->addNewChild(newChildNode);
}


DynamicNode::DynamicNode(DynamicNode& other) {
    parentNode = other.parentNode;
    value = other.value;
    children = copyChildren(&other, this);
}


std::vector<DynamicNode *> DynamicNode::copyChildren(DynamicNode* node, DynamicNode* current) {
    std::vector<DynamicNode*> newChildren;
    for (int i = 0; i < node->children.size(); ++i) {
        DynamicNode* temp = new DynamicNode(*node->children[i]);
        temp->parentNode = current;
        newChildren.push_back(temp);
    }
    return newChildren;
}

DynamicNode *DynamicNode::operator=(DynamicNode* node) {
    return new DynamicNode(*node);
}

void DynamicNode::addNewChild(DynamicNode *node) {
    node->parentNode = this;
    children.push_back(node);
}

void DynamicNode::removeChild(DynamicNode *node) {
    for (int i = 0; i < children.size(); ++i) {
        if (children[i] == node) children.erase(children.begin() + i);
    }
}

void DynamicNode::addNewChild(int value) {
    DynamicNode* temp = new DynamicNode(value);
    temp->parentNode = this;
    children.push_back(temp);
}

#include <vector>
#include <iostream>
#include "StaticNode.h"

StaticNode::StaticNode() {
    parentNode = nullptr;
    value = 0;
    children = std::vector<StaticNode>();

}

StaticNode::~StaticNode() {
    std::cout << "Deleting " << value << std::endl;
}

void StaticNode::addNewChild() {
    StaticNode node;
    node.parentNode = this;
    children.push_back(node);
}

StaticNode *StaticNode::getChild(int childIndex) {
    if (childIndex > children.size() || children.empty()) return nullptr;
    return &(children[childIndex]);
}

void StaticNode::printAllBelow() {
    print();
    for (StaticNode& i : children) {
        i.printAllBelow();
    }
}

void StaticNode::printUp() {
    print();
    if (parentNode != nullptr) parentNode->printUp();
}

void StaticNode::removeChild(StaticNode* node) {
    for (int i = 0; i < children.size(); ++i) {
        if (children[i] == *node) {
            children.erase(children.begin() + i);
            return;
        }
    }
}

bool StaticNode::operator==(const StaticNode& node) const{
    if (value == node.value){
        if (children == node.children) return true;
    }
    return false;
}

void StaticNode::setValue(int newValue) {
    value = newValue;
}

int StaticNode::getNumberOfChildren() {
    return children.size();
}

void StaticNode::print() {
    std::cout << value << " ";
}

StaticNode *StaticNode::getParent() {
    return parentNode;
}

int StaticNode::getValue() {
    return value;
}

StaticNode::StaticNode(int value) {
    parentNode = nullptr;
    this->value = value;
    children = std::vector<StaticNode>();

}

void StaticNode::addNewChild(int value) {
    StaticNode node(value);
    node.parentNode = this;
    children.push_back(node);
}

StaticNode::StaticNode(const StaticNode& other) {
    parentNode = other.parentNode;
    value = other.value;
    children = other.children;

    for (int i = 0; i < children.size(); ++i) {
        children[i].parentNode = this;
    }
}

bool StaticNode::isConsistent() const {
    if (children.empty()) return true;
    else {
        for (int i = 0; i < children.size(); ++i) {
            if (children[i].parentNode != this) return false;
            if (!children[i].isConsistent()) return false;
        }
    }
    return true;
}


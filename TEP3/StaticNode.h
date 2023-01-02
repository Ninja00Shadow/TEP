#include <vector>
#include <iostream>

#ifndef TEP3_STATICNODE_H
#define TEP3_STATICNODE_H

#endif //TEP3_STATICNODE_H

class StaticNode {
public:
    StaticNode();
    StaticNode(int value);
    StaticNode(const StaticNode& other);
    ~StaticNode();
    void setValue(int newValue);
    int getNumberOfChildren();
    void addNewChild();
    void addNewChild(int value);
    StaticNode *getChild(int childIndex);
    void print();
    void printAllBelow();
    void printUp();
    void removeChild(StaticNode* node);
    bool operator==(const StaticNode& node) const;
    StaticNode* getParent();
    int getValue();
    bool isConsistent() const;

private:
    std::vector<StaticNode> children;
    StaticNode *parentNode;
    int value;

};

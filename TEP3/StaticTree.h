//
// Created by Dawid on 13.11.2022.
//

#ifndef TEP3_STATICTREE_H
#define TEP3_STATICTREE_H

#endif //TEP3_STATICTREE_H

#include "StaticNode.h"

class StaticTree
{
public:
    StaticTree();
    StaticTree(StaticNode& root);
    ~StaticTree();
    StaticNode *getRoot() {return &root;}
    void printTree();
    bool moveSubtree(StaticNode *parentNode, StaticNode *newChildNode);
    void vCopySubtree(StaticNode *pcDestination, StaticNode *pcSource);
    bool isConsistent() const;

private:
    StaticNode root;
};


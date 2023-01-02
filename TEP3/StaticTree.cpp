#include "StaticTree.h"

StaticTree::StaticTree() {
    root = StaticNode();
}

StaticTree::~StaticTree() {

}

void StaticTree::printTree() {
    root.printAllBelow();
}

bool StaticTree::moveSubtree(StaticNode *parentNode, StaticNode *newChildNode) {
    if (!parentNode || !newChildNode) return false;

    vCopySubtree(parentNode, newChildNode);

    if (newChildNode->getParent()) {
        newChildNode->getParent()->removeChild(newChildNode);
    }
    return true;
}

void StaticTree::vCopySubtree(StaticNode *pcDestination, StaticNode *pcSource) {
    pcDestination->addNewChild(pcSource->getValue());

    for (int i = 0; i < pcSource->getNumberOfChildren(); i++) {
        vCopySubtree(pcDestination->getChild(pcDestination->getNumberOfChildren() - 1), pcSource->getChild(i));
    }
}

bool StaticTree::isConsistent() const {
    return root.isConsistent();
}

StaticTree::StaticTree(StaticNode &root) : root(root) {
}



#include <iostream>
#include "StaticTree.h"
#include "DynamicTree.h"

void staticTreeTest() {
    StaticNode root;
    root.addNewChild();
    root.addNewChild();
    root.getChild(0)->setValue(1);
    root.getChild(1)->setValue(2);
    root.getChild(0)->addNewChild();
    root.getChild(0)->addNewChild();
    root.getChild(0)->getChild(0)->setValue(11);
    root.getChild(0)->getChild(1)->setValue(12);
    root.getChild(1)->addNewChild();
    root.getChild(1)->addNewChild();
    root.getChild(1)->getChild(0)->setValue(21);
    root.getChild(1)->getChild(1)->setValue(22);

    root.printAllBelow();
    std::cout << std::endl;

    std::cout << root.getNumberOfChildren() << std::endl;
    std::cout << root.getChild(0)->getNumberOfChildren() << std::endl;

    root.getChild(0)->getChild(1)->printUp();
    std::cout << std::endl;

    StaticTree tree(root);
    tree.printTree();
    std::cout << std::endl;
}

void dynamicTreeTest1() {
    DynamicNode *root = new DynamicNode();
    root->addNewChild();
    root->addNewChild();
    root->getChild(0)->setValue(1);
    root->getChild(1)->setValue(2);

    root->getChild(0)->addNewChild();
    root->getChild(0)->addNewChild();
    root->getChild(0)->getChild(0)->setValue(11);
    root->getChild(0)->getChild(1)->setValue(12);
    root->getChild(1)->addNewChild();
    root->getChild(1)->addNewChild();
    root->getChild(1)->getChild(0)->setValue(21);
    root->getChild(1)->getChild(1)->setValue(22);

    root->printAllBelow();
    std::cout << std::endl;

    DynamicTree *tree = new DynamicTree(root);
    tree->printTree();

    std::cout << std::endl;

    delete tree;
}

void staticReatachmentTest() {
    StaticTree tree1, tree2;

    tree1.getRoot()->addNewChild(1);
    tree1.getRoot()->addNewChild(2);
    tree1.getRoot()->addNewChild(3);
    tree1.getRoot()->getChild(2)->addNewChild(4);

    tree2.getRoot()->setValue(50);
    tree2.getRoot()->addNewChild(54);
    tree2.getRoot()->addNewChild(55);
    tree2.getRoot()->getChild(0)->addNewChild(56);
    tree2.getRoot()->getChild(0)->addNewChild(57);
    tree2.getRoot()->getChild(0)->getChild(0)->addNewChild(58);

    tree1.getRoot()->printAllBelow();
    std::cout << std::endl;

    tree2.getRoot()->printAllBelow();
    std::cout << std::endl;

    tree1.moveSubtree(tree1.getRoot()->getChild(2), tree2.getRoot()->getChild(0));

    std::cout << std::endl;
    tree1.printTree();
    std::cout << std::endl;
    tree2.printTree();
    std::cout << std::endl;
}

void staticReatachmentTest2() {
//    StaticTree tree1, tree2;
    StaticNode root1, root2;

    root1.addNewChild(1);
    root1.addNewChild(2);
    root1.addNewChild(3);
    root1.getChild(2)->addNewChild(4);

    root2.setValue(50);
    root2.addNewChild(54);

    root1.printAllBelow();
    std::cout << std::endl;

    root2.printAllBelow();
    std::cout << std::endl;

    StaticTree tree1(root1), tree2(root2);

    tree1.moveSubtree(tree1.getRoot()->getChild(2), tree2.getRoot()->getChild(0));

    std::cout << std::endl;
    tree1.printTree();
    std::cout << std::endl;
    tree2.printTree();
    std::cout << std::endl;
}

void dynamicReatachmentTest1() {
    DynamicNode *root1 = new DynamicNode;
    root1->addNewChild(1);
    root1->addNewChild(2);
    root1->addNewChild(3);
    root1->getChild(2)->addNewChild(4);

    DynamicNode *root2 = new DynamicNode;
    root2->setValue(50);
    root2->addNewChild(54);
    root2->addNewChild(55);
    root2->getChild(0)->addNewChild(56);
    root2->getChild(0)->addNewChild(57);
    root2->getChild(0)->getChild(0)->addNewChild(58);

    root1->printAllBelow();
    std::cout << std::endl;

    root2->printAllBelow();
    std::cout << std::endl;

    DynamicTree *tree1 = new DynamicTree(root1);
    DynamicTree *tree2 = new DynamicTree(root2);

    tree1->moveSubtree(tree1->getRoot()->getChild(2), tree2->getRoot()->getChild(0));

    std::cout << std::endl;
    tree1->printTree();
    std::cout << std::endl;
    tree2->printTree();
    std::cout << std::endl;

    delete tree1;
    delete tree2;
}

void consistencyTest1() {
    StaticNode root;
    root.addNewChild(1);
    root.addNewChild(2);
    root.getChild(0)->addNewChild(11);
    root.getChild(0)->addNewChild(12);
    root.getChild(1)->addNewChild(21);
    root.getChild(1)->addNewChild(22);

    StaticTree tree(root);
    tree.printTree();

    std::cout << std::endl;
    std::cout << "Is consistent: " << tree.isConsistent() << std::endl;
}

void consistencyTest2() {
    StaticTree tree1;

    tree1.getRoot()->addNewChild(1);
    tree1.getRoot()->addNewChild(2);
    tree1.getRoot()->addNewChild(3);
    tree1.getRoot()->getChild(1)->addNewChild(-4);
    tree1.getRoot()->getChild(2)->addNewChild(-5);
    tree1.getRoot()->getChild(2)->addNewChild(4);
    tree1.getRoot()->getChild(2)->addNewChild(5);
    tree1.getRoot()->getChild(2)->addNewChild(6);
    tree1.getRoot()->getChild(2)->getChild(1)->addNewChild(7);

    tree1.printTree();
    std::cout << std::endl;

    std::cout << "Is consistent: " << tree1.isConsistent() << std::endl;
}

void consistencyTest3() {
    StaticTree tree1;

    tree1.getRoot()->setValue(1);

    tree1.printTree();
    std::cout << std::endl;

    std::cout << "Is consistent: " << tree1.isConsistent() << std::endl;
}

int main() {
    std::cout << "Basic Test of static tree" << std::endl;
    staticTreeTest();

    std::cout << "--------------------------------------------------------------------------------------" << std::endl;

    std::cout << "Basic Test of dynamic tree" << std::endl;
    dynamicTreeTest1();

    std::cout << "--------------------------------------------------------------------------------------" << std::endl;

    std::cout << "Test of reattaching a static node to different tree" << std::endl;
    staticReatachmentTest();

    std::cout << "--------------------------------------------------------------------------------------" << std::endl;

    std::cout << "Test of reattaching a static node from empty tree to different tree" << std::endl;
    staticReatachmentTest2();

    std::cout << "--------------------------------------------------------------------------------------" << std::endl;

    std::cout << "Test of reattaching a dynamic node to different tree" << std::endl;
    dynamicReatachmentTest1();

    std::cout << "--------------------------------------------------------------------------------------" << std::endl;

    std::cout << "Test of consistency of static tree number 1" << std::endl;
    consistencyTest1();

    std::cout << "--------------------------------------------------------------------------------------" << std::endl;

    std::cout << "Test of consistency of static tree number 2" << std::endl;
    consistencyTest2();

    std::cout << "--------------------------------------------------------------------------------------" << std::endl;

    std::cout << "Test of consistency of static tree number 3" << std::endl;
    consistencyTest3();
}


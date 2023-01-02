#include <iostream>
#include <vector>
#include "DynamicNode.h"
#include "DynamicTree.h"


void dynamicTreeTest1() {
    DynamicNode<int> *root = new DynamicNode<int>();
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

    DynamicTree<int> *tree = new DynamicTree<int>(root);
    std::cout << "Printing tree:" << std::endl;
    tree->printTree();

    std::cout << std::endl;

    delete tree;
}

void dynamicTreeTest2(){
    DynamicNode<char> *root = new DynamicNode<char>();
    root->setValue('a');
    root->addNewChild('b');
    root->addNewChild('c');
    root->getChild(0)->addNewChild('d');
    root->getChild(0)->addNewChild('e');
    root->getChild(1)->addNewChild('f');
    root->getChild(1)->addNewChild('g');

    DynamicTree<char> *tree = new DynamicTree<char>(root);
    std::cout << "Printing tree:" << std::endl;
    tree->printTree();

    std::cout << std::endl;

    delete tree;
}

void dynamicReatachmentTest1() {
    DynamicNode<int> *root1 = new DynamicNode<int>;
    root1->setValue(0);
    root1->addNewChild(1);
    root1->addNewChild(2);
    root1->addNewChild(3);
    root1->getChild(2)->addNewChild(4);

    DynamicNode<int> *root2 = new DynamicNode<int>;
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

    DynamicTree<int> *tree1 = new DynamicTree<int>(root1);
    DynamicTree<int> *tree2 = new DynamicTree<int>(root2);

    tree1->moveSubtree(tree1->getRoot()->getChild(2), tree2->getRoot()->getChild(0));

    std::cout << std::endl;
    tree1->printTree();
    std::cout << std::endl;
    tree2->printTree();
    std::cout << std::endl;

    delete tree1;
    delete tree2;
}

void dynamicReatachmentTest2() {
    DynamicNode<char> *root1 = new DynamicNode<char>;
    root1->setValue('a');
    root1->addNewChild('b');
    root1->addNewChild('c');
    root1->addNewChild('d');
    root1->getChild(2)->addNewChild('e');

    DynamicNode<char> *root2 = new DynamicNode<char>;
    root2->setValue('g');
    root2->addNewChild('h');
    root2->addNewChild('i');
    root2->getChild(0)->addNewChild('j');
    root2->getChild(0)->addNewChild('k');
    root2->getChild(0)->getChild(0)->addNewChild('l');

    root1->printAllBelow();
    std::cout << std::endl;

    root2->printAllBelow();
    std::cout << std::endl;

    DynamicTree<char> *tree1 = new DynamicTree<char>(root1);
    DynamicTree<char> *tree2 = new DynamicTree<char>(root2);

    tree1->moveSubtree(tree1->getRoot()->getChild(2), tree2->getRoot()->getChild(0));

    std::cout << std::endl;
    tree1->printTree();
    std::cout << std::endl;
    tree2->printTree();
    std::cout << std::endl;

    delete tree1;
    delete tree2;
}

void dynamicTreeTest3() {
    DynamicNode<std::string> *root = new DynamicNode<std::string>();
    root->setValue("a");
    root->addNewChild("b");
    root->addNewChild("c");
    root->getChild(0)->addNewChild("d");
    root->getChild(0)->addNewChild("e");
    root->getChild(1)->addNewChild("f");
    root->getChild(1)->addNewChild("g");
    root->getChild(0)->getChild(0)->addNewChild("h");

    DynamicTree<std::string> *tree = new DynamicTree<std::string>(root);
    std::cout << "Printing tree:" << std::endl;
    tree->printTree();

    std::cout << std::endl;

    delete tree;
}

void testSelfCast(){
    DynamicTree<DynamicNode<int>> *tree = new DynamicTree<DynamicTree<int>>;
}

int main() {

    std::cout << "Test of dynamic tree with ints" << std::endl;
    dynamicTreeTest1();

    std::cout << "--------------------------------------------------------------------------------------" << std::endl;

    std::cout << "Test of dynamic tree with chars" << std::endl;
    dynamicTreeTest2();

    std::cout << "--------------------------------------------------------------------------------------" << std::endl;

    std::cout << "Test of reattaching a dynamic node with ints" << std::endl;
    dynamicReatachmentTest1();

    std::cout << "--------------------------------------------------------------------------------------" << std::endl;

    std::cout << "Test of reattaching a dynamic node with chars" << std::endl;
    dynamicReatachmentTest2();

    std::cout << "--------------------------------------------------------------------------------------" << std::endl;

    std::cout << "Test of dynamic tree with strings" << std::endl;
    dynamicTreeTest3();
}


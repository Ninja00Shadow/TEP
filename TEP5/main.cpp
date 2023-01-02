//
// Created by Dawid on 17.12.2022.
//

#include <iostream>
#include "MySmartPointer.h"
#include "Table.h"

void testSmartPointer(){
    int* i = new int(5);
    MySmartPointer<int> smartPointer(i);
    std::cout << *smartPointer << " " << std::endl;
    MySmartPointer<int> smartPointer2(smartPointer);
    std::cout << *smartPointer2 << std::endl;
    MySmartPointer<int> smartPointer3 = smartPointer2;
    std::cout << *smartPointer3 << std::endl;

    std::cout << smartPointer.getCounter() << std::endl;

    *smartPointer3 = 10;
    std::cout << *smartPointer3 << std::endl;
    std::cout << *smartPointer2 << std::endl;
    std::cout << *smartPointer << std::endl;

    std::cout << "Deleting Smart Pointers" << std::endl;
}

void testSmartPointer2(){
    std::string *s = new std::string("Hello");
    MySmartPointer<std::string> smartPointer(s);
    std::cout << *smartPointer << std::endl;
    smartPointer->append(" World");
    std::cout << *smartPointer << std::endl;

    std::cout << "Deleting Smart Pointers" << std::endl;
}

void testSmartPointer3(){
    MySmartPointer<int> smartPointer(new int(5));
    MySmartPointer<int> smartPointer2(new int(10));
    MySmartPointer<int> smartPointer3 = smartPointer;

    std::cout << *smartPointer << " ref: " << smartPointer.getCounter() << std::endl;
    std::cout << *smartPointer2 << " ref: " << smartPointer2.getCounter() << std::endl;
    std::cout << *smartPointer3 << " ref: " << smartPointer3.getCounter() << std::endl;

    smartPointer = smartPointer2;

    std::cout << "After assignment" << std::endl;

    std::cout << *smartPointer << " ref: " << smartPointer.getCounter() << std::endl;
    std::cout << *smartPointer2 << " ref: " << smartPointer2.getCounter() << std::endl;
    std::cout << *smartPointer3 << " ref: " << smartPointer3.getCounter() << std::endl;

    std::cout << "Deleting Smart Pointers" << std::endl;

}

void testMoveOperator() {
    Table table;
    Table otherTable;

    table.setValue(0, 5);
    table.setValue(1, 10);

    std::cout << table << std::endl;
    std::cout << otherTable << std::endl;

    otherTable = std::move(table);

    std::cout << table << std::endl;
    std::cout << otherTable << std::endl;

}

void testMoveOperators(){
    Table table;
    Table otherTable;

    for (int i = 0; i < table.getLength(); ++i) {
        table[i] = 0;
        otherTable[i] = 0;
    }

    table.setValue(0, 5);
    table.setValue(1, 10);
    table[2] = 15;

    otherTable.setValue(0, 15);
    otherTable.setValue(1, 20);

    std::cout << table;
    std::cout << otherTable << std::endl;

    Table thirdTable = table + otherTable;

    std::cout << table << std::endl;
    std::cout << otherTable << std::endl;
    std::cout << thirdTable << std::endl;
}

int main() {
    std::cout << "Test 1" << std::endl;
    testSmartPointer();

    std::cout << "--------------------------------------------------------------------------------------" << std::endl;

    std::cout << "Test 2" << std::endl;
    testSmartPointer2();

    std::cout << "--------------------------------------------------------------------------------------" << std::endl;

    std::cout << "Test 3" << std::endl;
    testSmartPointer3();

    std::cout << "--------------------------------------------------------------------------------------" << std::endl;

    std::cout << "Test 4" << std::endl;
    testMoveOperator();

    std::cout << "--------------------------------------------------------------------------------------" << std::endl;

    std::cout << "Test 5" << std::endl;
    testMoveOperators();

    return 0;
}

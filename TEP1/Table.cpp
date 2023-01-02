#include <iostream>
#include "Table.h"

Table::Table() {
    name = DEFAULT_NAME;
    length = DEFAULT_ARRAY_LENGTH;

    std::cout << "Without parameters: " << name << std::endl;

    array = new int[DEFAULT_ARRAY_LENGTH];
}

Table::Table(std::string name, int tableLength) {
    if (!validSize(tableLength)) return;

    this->name = name;
    length = tableLength;

    std::cout << "With parameters: " << name << std::endl;

    array = new int[tableLength];
}

Table::Table(Table &pcOther) {
    name = pcOther.name + "_copy";
    length = pcOther.length;
    array = copyArray(pcOther.array, pcOther.length);

    std::cout << "Copying: " << name << std::endl;

}

void Table::setName(std::string name) {
    this->name = name;
}

bool Table::setNewSize(int tableLength) {
    if (!validSize(tableLength)) return false;

    int *new_Array = new int[tableLength];

    for (int i = 0; i < length; ++i) {
        new_Array[i] = array[i];
    }

    length = tableLength;
    delete array;
    array = new_Array;
    return true;
}

Table *Table::pcClone() {
    return new Table(*this);
}

void Table::modifyArray(Table *table, int newSize) {
    if (!validSize(newSize)) return;

    int *new_Array = copyArray(table->array, table->length, newSize);

    table->length = newSize;
    delete array;
    table->array = new_Array;
}

void Table::modifyArray(Table table, int newSize) {
    if (!validSize(newSize)) return;

    int *new_Array = copyArray(table.array, table.length, newSize);

    table.length = newSize;
    delete array;
    table.array = new_Array;
}

int *Table::copyArray(int *array, int length) {
    int *new_Array = new int[length];

    for (int i = 0; i < length; ++i) {
        new_Array[i] = array[i];
    }
    return new_Array;
}

int *Table::copyArray(int *array, int originalLength, int newLength) {
    int *new_Array = new int[newLength];

    for (int i = 0; i < originalLength; ++i) {
        new_Array[i] = array[i];
    }

    return new_Array;
}

void Table::setValue(int index, int value) {
    array[index] = value;
}

Table::~Table() {
    std::cout << "Destroying: " << name << std::endl;

    delete this->array;
}

bool Table::validSize(int size) {
    if (size <= 0) {
        std::cout << DEFAULT_ERROR_MESSAGE << std::endl;
        return false;
    }
    return true;
}

void Table::printArray() {
    std::cout << "Printing array from " << name << std::endl;
    for (int i = 0; i < length; ++i) {
        std::cout << array[i] <<" ";
    }
    std::cout << std::endl;
}

std::string Table::getName() {
    return name;
}


int main() {
    std::cout << "Constructors: " << std::endl;

    Table *table = new Table();
    Table *table1 = new Table("Bigger table", 25);
    Table *table2 = new Table(*table1);

    std::cout << std::endl;

    std::cout << "Checking names of the tables: " << std::endl;
    std::cout << table->getName() << std::endl;
    std::cout << table1->getName() << std::endl;
    std::cout << table2->getName() << std::endl;

    std::cout << std::endl;

    std::cout << "Testing setName function on second table: " << std::endl;

    std::cout << "Before: " << table1->getName() << std::endl;
    table1->setName("New Name");
    std::cout << "After: " <<table1->getName() << std::endl;

    std::cout << std::endl;

    std::cout << "Setting first four elements in first table: " << std::endl;
    table->setValue(0, 24);
    table->setValue(1, -3);
    table->setValue(2, 56);
    table->setValue(3, -5);

    table->printArray();

    std::cout << std::endl;

    std::cout << "Changing size of the array in first table: " << std::endl;
    table->setNewSize(30);

    table->printArray();

    std::cout << std::endl;

    std::cout << "Making fourth table with cloning method " << std::endl;
    Table *table3 = table->pcClone();
    std::cout << "Table: " << table->getName() << std::endl;
    std::cout << "Table3: " << table3->getName() << std::endl;

    std::cout << std::endl;

    table3->printArray();

    //modifying arrays

    std::cout << std::endl;
    table2->modifyArray(table2, 20);                  //void modifyArray(Table *table, int newSize); works
    table2->printArray();
    std::cout << std::endl;


    table2->modifyArray(*table2, 35);                 //void modifyArray(Table table, int newSize); doesn't work
    table2->printArray();
    std::cout << std::endl;

    std::cout << "Testing destructors: " << std::endl;
    delete table;
    delete table1;
    delete table2;
    delete table3;
}

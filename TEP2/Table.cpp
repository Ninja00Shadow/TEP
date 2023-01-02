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

    for (int i = 0; i < tableLength; ++i) {
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
    array = new_Array;
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

bool Table::validSize(int size) {
    if (size <= 0) {
        std::cout << DEFAULT_ERROR_MESSAGE << std::endl;
        return false;
    }
    return true;
}

Table::~Table() {
    std::cout << "Destroying: " << name << std::endl;

    delete array;
}

std::string Table::getName() {
    return name;
}

void Table::operator=(const Table &pcOther) {
    name = pcOther.name;
    delete[] array;
    array = copyArray(pcOther.array, pcOther.length);
    length = pcOther.length;
}

Table Table::operator+(const Table &pcOther) const {
    Table newTable("concat", length + pcOther.length);

    int j = 0;
    for (int i = 0; i < length; i++) {
        newTable.setValue(j++, array[i]);
    }
    for (int i = 0; i < pcOther.length; i++) {
        newTable.setValue(j++, pcOther.array[i]);

    }

    return newTable;
}

std::ostream& operator<<(std::ostream& stream, const Table& table){
    if (table.length == 0) stream << "Empty array";
    for (int i = 0; i < table.length; ++i) {
        stream << table.array[i] << " ";
    }
    stream << std::endl;
    return stream;
}

void test1() {
    Table table1, table2;
    table1.setNewSize(6);
    table2.setNewSize(4);

    std::cout << "Before" << std::endl;

    std::cout << "Printing table1" << std::endl;
    std::cout << table1;
    std::cout << "Printing table2" << std::endl;
    std::cout << table2;

    table1 = table2;

    std::cout << "After" << std::endl;

    std::cout << "Printing table1" << std::endl;
    std::cout << table1;
    std::cout << "Printing table2" << std::endl;
    std::cout << table2;

    std::cout << "There should be a bug" << std::endl;

    std::cout << "-------------------------------------------------------------------------" << std::endl;
}

void test2() {
    Table table1, table2;
    table1.setNewSize(6);
    table2.setNewSize(4);

    std::cout << "Before" << std::endl;

    std::cout << "Printing table1" << std::endl;
    std::cout << table1;
    std::cout << "Printing table2" << std::endl;
    std::cout << table2;

    table1 = table2;

    std::cout << "After" << std::endl;

    std::cout << "Printing table1" << std::endl;
    std::cout << table1;
    std::cout << "Printing table2" << std::endl;
    std::cout << table2;


    std::cout << "-------------------------------------------------------------------------" << std::endl;
}

void test3() {
    Table table1, table2;
    table1.setNewSize(6);
    table2.setNewSize(4);

    table1.setValue(0, 1);
    table1.setValue(1, 2);
    table1.setValue(2, 3);
    table1.setValue(3, 4);
    table1.setValue(4, 5);
    table1.setValue(5, 6);

    table2.setValue(0, 51);
    table2.setValue(1, 52);
    table2.setValue(2, 53);
    table2.setValue(3, 54);

    std::cout << "Printing table1" << std::endl;
    std::cout << table1;
    std::cout << "Printing table2" << std::endl;
    std::cout << table2;

    table1 = table2;

    table2.setValue(2, 123);
    std::cout << "Printing table1" << std::endl;
    std::cout << table1;
    std::cout << "Printing table2" << std::endl;
    std::cout << table2;

    std::cout << "-------------------------------------------------------------------------" << std::endl;

}


void test4() {
    Table table1, table2;

    table1.setNewSize(6);
    table2.setNewSize(4);

    table1.setValue(0, 1);
    table1.setValue(1, 2);
    table1.setValue(2, 3);
    table1.setValue(3, 4);
    table1.setValue(4, 5);
    table1.setValue(5, 6);

    table2.setValue(0, 51);
    table2.setValue(1, 52);
    table2.setValue(2, 53);
    table2.setValue(3, 54);

    std::cout << "Printing table1" << std::endl;
    std::cout << table1;
    std::cout << "Printing table2" << std::endl;
    std::cout << table2;

    Table concatenatedArray;
    concatenatedArray = table1 + table2;

    std::cout << "Printing concatenated array" << std::endl;
    std::cout << concatenatedArray;;
}

void test5() {
    Table table1;
    Table* table2 = new Table("LL", 0);

    table1.setNewSize(6);

    table1.setValue(0, 1);
    table1.setValue(1, 2);
    table1.setValue(2, 3);
    table1.setValue(3, 4);
    table1.setValue(4, 5);
    table1.setValue(5, 6);

    std::cout << "Printing table1" << std::endl;
    std::cout << table1;
    std::cout << "Printing table2" << std::endl;
    std::cout << table2 << std::endl;

    Table concatenatedArray;
    concatenatedArray = table1 + *table2;

    std::cout << "Printing concatenated array" << std::endl;
    std::cout << concatenatedArray;;

    delete table2;
}

int main() {
    std::cout << "Test 1" << std::endl;
    test1();

    std::cout << std::endl;

    std::cout << "Test 2" << std::endl;
    test2();

    std::cout << std::endl;

    std::cout << "Test 3" << std::endl;
    test3();

    std::cout << std::endl;

    std::cout << "Test 4" << std::endl;
    test4();

    std::cout << std::endl;

    std::cout << "Test 5" << std::endl;
    test5();

    std::cout << std::endl;
}

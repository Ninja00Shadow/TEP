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


std::ostream& operator<<(std::ostream& stream, const Table& table){
    if (table.length == 0) stream << "Empty array";
    for (int i = 0; i < table.length; ++i) {
        stream << table.array[i] << " ";
    }
    stream << std::endl;
    return stream;
}

int& Table::operator[](int index) {
    return array[index];
}

int Table::getLength() const{
    return length;
}

Table::Table(Table &&other) noexcept {
    move(std::move(other));

}

Table& Table::operator=(const Table &pcOther) {
    if (this == &pcOther) return *this;

    name = pcOther.name + "_copy";
    length = pcOther.length;
    array = copyArray(pcOther.array, pcOther.length);

    return *this;
}

Table Table::operator=(Table &&other) {
    if (this == &other) return *this;

    delete[] array;

    move(std::move(other));

    return *this;
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

    return std::move(newTable);
}

void Table::move(Table &&other) {
    name = other.name + "_move";
    length = other.length;
    array = other.array;

    other.array = nullptr;
    other.name = "empty";
    other.length = 0;

    std::cout << "Moving: " << name << std::endl;
}

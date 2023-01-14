//
// Created by Dawid on 17.12.2022.
//

#ifndef TEP_MYSMARTPOINTER_H
#define TEP_MYSMARTPOINTER_H

#endif //TEP_MYSMARTPOINTER_H

class ReferenceCounter {
public:
    ReferenceCounter() {counter = 0;};
    void add() {counter++;};
    void remove() {counter--;};
    int get() {return counter;};
private:
    int counter;
};

template <typename T> class MySmartPointer {
public:
    MySmartPointer() {
        pointer = nullptr;
        referenceCounter = new ReferenceCounter();
    }
    MySmartPointer(T* pointer) {
        this->pointer = pointer;
        referenceCounter = new ReferenceCounter();
        referenceCounter->add();
    }
    MySmartPointer(MySmartPointer<T> const &other) {
        this->pointer = other.pointer;
        referenceCounter = other.referenceCounter;
        referenceCounter->add();
    }
    ~MySmartPointer() {
        referenceCounter->remove();
//        std::cout << "Reference counter: " << referenceCounter->get() << std::endl;
        if (referenceCounter->get() == 0) {
            delete pointer;
            delete referenceCounter;
//            std::cout << "Deleting pointer" << std::endl;
        }
    }
    T* operator->() {
        return pointer;
    }
    T& operator*() {
        return *pointer;
    }
    MySmartPointer<T>& operator=(MySmartPointer<T> const &other) {
        if (this == &other) {
            return *this;
        }
        referenceCounter->remove();
        if (referenceCounter->get() == 0) {
            delete pointer;
            delete referenceCounter;
        }
        this->pointer = other.pointer;
        referenceCounter = other.referenceCounter;
        referenceCounter->add();
        return *this;
    }

    MySmartPointer<T>& operator=(MySmartPointer<T> &other) {
        if (this == &other) {
            return *this;
        }
        referenceCounter->remove();
        if (referenceCounter->get() == 0) {
            delete pointer;
            delete referenceCounter;
        }
        this->pointer = other.pointer;
        referenceCounter = other.referenceCounter;
        referenceCounter->add();
        return *this;
    }
    int getCounter() {
        return referenceCounter->get();
    }

    bool operator==(MySmartPointer<T> const &other) {
        return pointer == other.pointer;
    }

    bool operator==(T* other) {
        return pointer == other;
    }

private:
    T* pointer;
    ReferenceCounter* referenceCounter;
};
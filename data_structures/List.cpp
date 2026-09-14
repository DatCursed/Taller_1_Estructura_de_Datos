#include "List.hpp"

template <typename T>
List<T>::List() {
    this->start = nullptr;
}

template <typename T>
List<T>::~List() {
    clear();
}

template <typename T>
bool List<T>::empty() {
    return this->start == nullptr;
}

template <typename T>
void List<T>::insert(T value, int index) {
    if (index < 0) throw 0;
    if (index == 0) {
        insertFirst(value);
        return;
    }

    Node<T>* cursor = this->start;
    for (int i = 0; i < index - 1; i++) {
        cursor = cursor->getNext();
        if (!cursor) throw 0;
    }

    Node<T>* nuevo = new Node(value);
    nuevo->setNext(cursor->getNext());
    cursor->setNext(nuevo);
}

template <typename T>
void List<T>::insertFirst(T value) {
    Node<T>* nuevo = new Node(value);
    nuevo->setNext(this->start);
    this->start = nuevo;
}

template <typename T>
void List<T>::insertLast(T value) {
    if (this->start == nullptr) {
        this->start = new Node(value);
        return;
    }

    Node<T>* cursor = this->start;
    while (cursor->getNext() != nullptr) {
        cursor = cursor->getNext();
    }
    cursor->setNext(new Node(value));
}

template <typename T>
T List<T>::get(int index) {
    if (!this->start || index < 0) throw 0;
    Node<T>* cursor = this->start;
    for (int i = 0; i < index; i++) {
        cursor = cursor->getNext();
        if (!cursor) throw 0;
    }
    return cursor->getValue();
}

template <typename T>
T List<T>::getFirst() {
    if (this->start == nullptr) throw 0;
    return this->start->getValue();
}

template <typename T>
T List<T>::getLast() {
    if (this->start == nullptr) throw 0;
    Node<T>* cursor = this->start;
    while (cursor->getNext() != nullptr) {
        cursor = cursor->getNext();
    }
    return cursor->getValue();
}

template <typename T>
void List<T>::remove(int index) {
    if (!this->start || index < 0) throw 0;
   
    if (index == 0) {
        Node<T>* toDelete = this->start;
        this->start = this->start->getNext();
        delete toDelete;
        return;
    }

    Node<T>* cursor = this->start;
    for (int i = 0; i < index - 1; i++) {
        cursor = cursor->getNext();
        if (!cursor) throw 0;
    }

    Node<T>* toDelete = cursor->getNext();

    if (toDelete != nullptr) {
        cursor->setNext(toDelete->getNext());
    } else {
        cursor->setNext(nullptr);
    }

    delete toDelete;
}

template <typename T>
void List<T>::clear() {
    while (this->start != nullptr) {
        Node<T>* temp = this->start->getNext();
        delete this->start;
        this->start = temp;
    }
}
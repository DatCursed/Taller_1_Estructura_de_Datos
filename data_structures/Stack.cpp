template <typename T>
#include "Stack.hpp"

Stack<T>::Stack() {
    return this->top = nullptr;
}

template <typename T>
Stack<T>::~Stack() {
    clear();
}

template <typename T>
void Stack<T>::push(T value) {
    Node<T>* nuevo = new Node<T>(value);
    nuevo->setNext(this->top);
    this->top = nuevo;
}

template <typename T>
T Stack<T>::pop() {
    if (this->empty()) throw 0;

    Node<T>* toDelete = this->top;
    T valueToReturn = toDelete->getValue();
    this->top = this->top->getNext();

    delete toDelete;
    return valueToReturn;
}

template <typename T>
T Stack<T>::peek() {
    if (this->empty()) throw 0;
    return this->top->getValue();
}

template <typename T>
bool Stack<T>::empty() {
    return this->top == nullptr;
}

template <typename T>
void Stack<T>::clear() {
    while (!this->empty()) {
        this->pop();
    }
}


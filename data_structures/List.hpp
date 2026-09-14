#pragma once
#include "Node.hpp"

template <typename T>
class List {
private:
    Node<T>* start;
public:
    List();

    void insert(T value, int index);
    void insertFirst(T value);
    void insertLast(T value);

    T get(int index);
    T getFirst();
    T getLast();

    void remove(int index);
    bool empty();
    void clear();

    ~List();
};

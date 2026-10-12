//
// Created by sloopster on 9/17/26.
//

#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T* data;
    Node<T>* next;

    explicit Node(T* value) : data(value), next(nullptr) {}
};

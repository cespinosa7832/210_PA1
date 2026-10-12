//
// Created by sloopster on 9/15/26.
//

#include<iostream>
#include "List.h"
#pragma once


template <typename T>
class ArrayList : public List<T> {
public:
    void addFront(T* value) override {
        if (size_ >= CAPACITY) {
            std::cout << "ArrayList is full." << std::endl;
            return;
        }
        for (int i = size_; i > 0; --i) {
            data_[i] = data_[i - 1];
        }
        data_[0] = value;
        ++size_;
    }

    void deleteFront() override {
        if (size_ == 0) {
            std::cout << "ArrayList is empty." << std::endl;
            return;
        }
        delete data_[0];
        for (int i = 0; i < size_ - 1; ++i) {
            data_[i] = data_[i + 1];
        }
        --size_;
    }

    void addAnywhere(int position, T* value) override {
        if (size_ >= CAPACITY) {
            std::cout << "ArrayList is full." << std::endl;
            return;
        }
        if (position > size_ || position < 0) {
            std::cout << "Out of Bounds" << std::endl;
        }
        for (int i = size_; i > position; --i) {
            data_[i] = data_[i - 1];
        }
        data_[position] = value;
        ++size_;
    }

    void deleteAnywhere(int position) override {
        if (size_ == 0) {
            std::cout << "ArrayList is empty." << std::endl;
            return;
        }
        if (position < 0 || position >= size_) {
            std::cout << "Out of Bounds" << std::endl;
        }
        delete data_[position];
        for (int i = position; i < size_ - 1; ++i) {
            data_[i] = data_[i + 1];
        }
        --size_;
    }


    void reverse() override {
        if (size_ == 0) {
            std::cout << "ArrayList is empty." << std::endl;
            return;
        }
        for (int i = 0; i < size_ / 2; ++i) {
            T* temp = data_[i];
            data_[i] = data_[size_ - 1 - i];
            data_[size_ - 1 - i] = temp;
        }
    }

    void concat(List<T>* other) override {
        ArrayList<T>* otherList = dynamic_cast<ArrayList<T>* >(other);

        if (otherList == nullptr) {
            return;
        }

        if (otherList->size_ == 0) {
            return;
        }

        if (this->size_ + otherList->size_ > CAPACITY) {
            std::cout << "Not enough slots" << std::endl;
            return;
        }

        for (int i = 0; i < otherList->size_; ++i) {
            data_[i + size_] = new T(*otherList->data_[i]);
        }

        size_ += otherList->size_;
        otherList->size_ = 0;
    }

    bool search(T* value) const override {
        for (int i= 0; i < size_; ++i) {
            if (*data_[i] == *value) {
                return true;
            }
        }
        return false;
    }

    void print() const override {
        for (int i = 0; i < size_; ++i) {
            std:: cout << *data_[i] << ", ";
        }
        std::cout << std::endl;
    }

    ~ArrayList() override {
        for (int i = 0; i < size_; ++i) {
            delete data_[i];
        }
    }

private:
    static const int CAPACITY = 20;
    T* data_[CAPACITY];
    int size_;
};
//
// Created by sloopster on 8/17/26.
//

#pragma once
#include "Node.h"

template<typename T>
class LinkedList : public List<T> {
public:
    LinkedList() : head_(nullptr) {}

    void addFront(T* value) override {
        Node<T>* fresh = new Node<T>(value);
        fresh->next = head_;
        head_ = fresh;
    }

    void deleteFront() override {
        if (head_ == nullptr) {
            std::cout << "List is empty" << std::endl;
            return;
        }
        Node<T>* doomed = head_;
        head_ = head_->next;
        delete doomed->data;
        delete doomed;
    }

    bool search(T* value) const override {
        Node<T>* current = head_;
        while (current != nullptr) {
            if (*current->data == *value) return true;
            current = current->next;
        }
        return false;
    }

    void print() const override {
        Node<T>* current = head_;
        while (current != nullptr) {
            std::cout << *current->data << ", ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void addAnywhere(int position, T* value) override {

        if (position < 0) {
            std::cout << "Position Out of Bounds" << std::endl;
            return;
        }

        if (position == 0 || head_ == nullptr) {
            addFront(value);
            return;
        }

        Node<T>* current = head_;

        for (int i = 0; i < position - 1; i++) {
            if (current == nullptr) {
                std::cout << "Position Out of Bounds" << std::endl;
                return;
            }
            current = current->next;
        }

        if (current == nullptr) {
            std::cout << "Position Out of Bounds" << std::endl;
            return;
        }

        Node<T>* newNode = new Node<T>(value);
        newNode->next = current->next;
        current->next = newNode;

    }

    void deleteAnywhere(int position) override {
        if (position < 0) {
            std::cout << "Position Out of Bounds" << std::endl;
            return;
        }

        if (head_ == nullptr) {
            std::cout << "List is Empty" << std::endl;
            return;
        }

        if (position == 0) {
            Node<T>* doomed = head_;
            head_ = head_->next;
            delete doomed->data;
            delete doomed;
            return;
        }

        Node<T>* current = head_;
        for (int i = 0; i < position - 1; i++) {
            if (current == nullptr) {
                std::cout << "Position Out of Bounds" << std::endl;
                return;
            }
            current = current->next;
        }
        if (current == nullptr || current->next == nullptr) {
            std::cout << "Position Out of Bounds" << std::endl;
            return;
        }

        Node<T>* doomed = current->next;
        current->next = doomed->next;
        delete doomed->data;
        delete doomed;
    }

    void reverse() override {
        Node<T>* prev = nullptr;
        Node<T>* current = head_;
        Node<T>* nextNode = nullptr;

        while (current != nullptr) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        head_ = prev;
    }

    void concat(List<T>* other) override {
        LinkedList<T>* otherList = dynamic_cast<LinkedList<T>* > (other);
        if (otherList == nullptr) {
            return;
        }

        if (head_ == nullptr) {
            head_ = otherList->head_;
            return;
        }

        Node<T>* current = head_;

        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = otherList->head_;
        otherList->head_ = nullptr;
    }

    ~LinkedList() override {
        while (head_ != nullptr) {
            Node<T>* doomed = head_;
            head_ = head_->next;
            delete doomed->data;
            delete doomed;
        }
    }

private:
    Node<T>* head_;
};

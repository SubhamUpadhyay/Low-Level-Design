#pragma once
#include "Iterable.hpp"

class LinkedList : public Iterable {
    struct Node {
        Song data;
        Node* next;
        Node(Song s) : data(s), next(nullptr) {}
    };

    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void add(Song s) {
        Node* newNode = new Node(s);
        newNode->next = head;
        head = newNode;
    }

    Node* getHead() const {
        return head;
    }

    // Forward declaration
    class LinkedListIterator;

    Iterator* getIterator() override;

    // Iterator class
    class LinkedListIterator : public Iterator {
        const LinkedList& list;
        Node* current;

    public:
        LinkedListIterator(const LinkedList& lst) : list(lst), current(lst.getHead()) {}

        bool hasNext() override {
            return current != nullptr;
        }

        Song next() override {
            Song s = current->data;
            current = current->next;
            return s;
        }
    };
};

Iterator* LinkedList::getIterator() {
    return new LinkedListIterator(*this);
}

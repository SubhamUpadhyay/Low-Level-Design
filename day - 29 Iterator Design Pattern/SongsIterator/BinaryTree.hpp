#pragma once
#include <stack>
#include "Iterable.hpp"

class BinaryTree : public Iterable {
    struct Node {
        Song data;
        Node* left;
        Node* right;
        Node(Song s) : data(s), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insertRec(Node* node, Song s) {
        if (!node) return new Node(s);
        if (s < node->data)
            node->left = insertRec(node->left, s);
        else
            node->right = insertRec(node->right, s);
        return node;
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(Song s) {
        root = insertRec(root, s);
    }

    Node* getRoot() const {
        return root;
    }

    class BinaryTreeIterator;

    Iterator* getIterator() override;

    // Iterator class
    class BinaryTreeIterator : public Iterator {
        const BinaryTree& tree;
        std::stack<Node*> st;

        void pushLeft(Node* node) {
            while (node) {
                st.push(node);
                node = node->left;
            }
        }

    public:
        BinaryTreeIterator(const BinaryTree& bt) : tree(bt) {
            pushLeft(bt.getRoot());
        }

        bool hasNext() override {
            return !st.empty();
        }

        Song next() override {
            Node* node = st.top(); st.pop();
            Song result = node->data;
            pushLeft(node->right);
            return result;
        }
    };
};

Iterator* BinaryTree::getIterator() {
    return new BinaryTreeIterator(*this);
}

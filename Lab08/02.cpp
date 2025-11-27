#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int x) {
    if (!root) return new Node(x);
    if (x < root->data) root->left = insert(root->left, x);
    else root->right = insert(root->right, x);
    return root;
}

Node* searchRec(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return searchRec(root->left, key);
    return searchRec(root->right, key);
}


Node* searchIter(Node* root, int key) {
    Node* cur = root;
    while (cur) {
        if (cur->data == key) return cur;
        cur = (key < cur->data) ? cur->left : cur->right;
    }
    return nullptr;
}

Node* findMin(Node* root) {
    if (!root) return nullptr;
    while (root->left) root = root->left;
    return root;
}

Node* findMax(Node* root) {
    if (!root) return nullptr;
    while (root->right) root = root->right;
    return root;
}

Node* inorderSuccessor(Node* root, Node* target) {
    if (!root || !target) return nullptr;
    if (target->right) return findMin(target->right);

    Node* succ = nullptr;
    Node* cur = root;
    while (cur) {
        if (target->data < cur->data) {
            succ = cur;
            cur = cur->left;
        } else if (target->data > cur->data) {
            cur = cur->right;
        } else break; 
    }
    return succ;
}

Node* inorderPredecessor(Node* root, Node* target) {
    if (!root || !target) return nullptr;
    if (target->left) return findMax(target->left);

    Node* pred = nullptr;
    Node* cur = root;
    while (cur) {
        if (target->data > cur->data) {
            pred = cur;
            cur = cur->right;
        } else if (target->data < cur->data) {
            cur = cur->left;
        } else break; // found target
    }
    return pred;
}



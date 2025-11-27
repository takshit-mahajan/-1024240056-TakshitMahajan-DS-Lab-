#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

bool isBSTRange(Node* root, long long minVal = LLONG_MIN, long long maxVal = LLONG_MAX) {
    if (!root) return true;
    if (root->data <= minVal || root->data >= maxVal) return false;
    return isBSTRange(root->left, minVal, root->data) &&
           isBSTRange(root->right, root->data, maxVal);
}


bool isBSTInorder(Node* root, long long &prev) {
    if (!root) return true;
    if (!isBSTInorder(root->left, prev)) return false;
    if (root->data <= prev) return false; 
    prev = root->data;
    return isBSTInorder(root->right, prev);
}

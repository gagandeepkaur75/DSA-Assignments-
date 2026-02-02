#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int value) {
    Node* temp = new Node();
    temp->data = value;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}

bool isBSTUtil(Node* root, int minVal, int maxVal) {
    if (root == nullptr)
        return true;

    if (root->data <= minVal || root->data >= maxVal)
        return false;

    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    Node* root = newNode(50);
    root->left = newNode(30);
    root->right = newNode(70);
    root->left->left = newNode(20);
    root->left->right = newNode(40);
    root->right->left = newNode(60);
    root->right->right = newNode(80);

    if (isBST(root))
        cout << "The given tree IS a Binary Search Tree." << endl;
    else
        cout << "The given tree is NOT a Binary Search Tree." << endl;

    return 0;
}

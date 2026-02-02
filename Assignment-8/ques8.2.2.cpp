#include <iostream>
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

Node* insert(Node* root, int value) {
    if (root == nullptr)
        return newNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

Node* findMin(Node* root) {
    while (root->left != nullptr)
        root = root->left;
    return root;
}

Node* findMax(Node* root) {
    while (root->right != nullptr)
        root = root->right;
    return root;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    insert(root, 12);
    insert(root, 59);

    Node* minNode = findMin(root);
    Node* maxNode = findMax(root);

    if (minNode != nullptr)
        cout << "Minimum value in BST: " << minNode->data << endl;
    if (maxNode != nullptr)
        cout << "Maximum value in BST: " << maxNode->data << endl;

    return 0;
}

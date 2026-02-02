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

Node* inorderSuccessor(Node* root, Node* node) {
    if (node->right != nullptr)
        return findMin(node->right);

    Node* succ = nullptr;
    while (root != nullptr) {
        if (node->data < root->data) {
            succ = root;
            root = root->left;
        } else if (node->data > root->data)
            root = root->right;
        else
            break;
    }
    return succ;
}

Node* inorderPredecessor(Node* root, Node* node) {
    if (node->left != nullptr)
        return findMax(node->left);

    Node* pred = nullptr;
    while (root != nullptr) {
        if (node->data > root->data) {
            pred = root;
            root = root->right;
        } else if (node->data < root->data)
            root = root->left;
        else
            break;
    }
    return pred;
}

Node* search(Node* root, int key) {
    while (root != nullptr) {
        if (root->data == key)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return nullptr;
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

    int key;
    cout << "Enter node value: ";
    cin >> key;

    Node* node = search(root, key);
    if (node == nullptr) {
        cout << "Node not found in BST." << endl;
        return 0;
    }

    Node* succ = inorderSuccessor(root, node);
    Node* pred = inorderPredecessor(root, node);

    if (succ != nullptr)
        cout << "In-order Successor: " << succ->data << endl;
    else
        cout << "In-order Successor: None" << endl;

    if (pred != nullptr)
        cout << "In-order Predecessor: " << pred->data << endl;
    else
        cout << "In-order Predecessor: None" << endl;

    return 0;
}

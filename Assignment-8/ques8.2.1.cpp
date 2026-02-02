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

Node* searchRec(Node* root, int key) {
    if (root == nullptr || root->data == key)
        return root;
    if (key < root->data)
        return searchRec(root->left, key);
    return searchRec(root->right, key);
}

Node* searchIter(Node* root, int key) {
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

void printLocation(Node* root, int key) {
    if (root == nullptr) {
        cout << "Value not found in tree." << endl;
        return;
    }
    if (key == root->data)
        cout << "Value found at ROOT!" << endl;
    else if (key < root->data)
        cout << "Value found in LEFT subtree!" << endl;
    else
        cout << "Value found in RIGHT subtree!" << endl;
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

    int key;
    cout << "Enter value to search: ";
    cin >> key;

    Node* res1 = searchRec(root, key);
    if (res1 != nullptr) {
        cout << "Found (Recursive Search)! ";
        printLocation(root, key);
    } else {
        cout << "Not Found (Recursive Search)." << endl;
    }

    Node* res2 = searchIter(root, key);
    if (res2 != nullptr) {
        cout << "Found (Iterative Search)! ";
        printLocation(root, key);
    } else {
        cout << "Not Found (Iterative Search)." << endl;
    }

    return 0;
}

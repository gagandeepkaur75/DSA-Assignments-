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
Node* findMin(Node* root) {
    while (root->left != nullptr)
        root = root->left;
    return root;
}


Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        }
        else if (root->left == nullptr) {
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int main() {
    Node* root = newNode(50);
    root->left = newNode(30);
    root->right = newNode(70);
    root->left->left = newNode(20);
    root->left->right = newNode(40);
    root->right->left = newNode(60);
    root->right->right = newNode(80);

    int key;
    cout << "Enter value to delete: ";
    cin >> key;

    root = deleteNode(root, key);

    cout << "Node deleted successfully." << endl;

    return 0;
}

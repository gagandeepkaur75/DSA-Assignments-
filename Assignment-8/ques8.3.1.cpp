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
    else
        cout << "Duplicate value " << value << " not allowed." << endl;

    return root;
}

int main() {
    Node* root = nullptr;
    int n, value;

    cout << "How many elements to insert in BST? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;
        root = insert(root, value);
    }

    cout << "Elements inserted successfully!" << endl;

    return 0;
}

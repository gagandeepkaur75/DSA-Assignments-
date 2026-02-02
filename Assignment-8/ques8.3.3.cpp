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

int minDepth(Node* root) {
    if (root == nullptr)
        return 0;

    if (root->left == nullptr && root->right == nullptr)
        return 1;

    if (root->left == nullptr)
        return 1 + minDepth(root->right);

    if (root->right == nullptr)
        return 1 + minDepth(root->left);

    return 1 + min(minDepth(root->left), minDepth(root->right));
}

int maxDepth(Node* root) {
    if (root == nullptr)
        return 0;

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return 1 + max(leftDepth, rightDepth);
}

int main() {
    Node* root = newNode(50);
    root->left = newNode(30);
    root->right = newNode(70);
    root->left->left = newNode(20);
    root->left->right = newNode(40);
    root->right->left = newNode(60);
    root->right->right = newNode(80);

    cout << "Maximum Depth of BST: " << maxDepth(root) << endl;
    cout << "Minimum Depth of BST: " << minDepth(root) << endl;

    return 0;
}

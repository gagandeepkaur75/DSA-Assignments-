#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;

Node* newNode(int value) {
    Node* temp = new Node();
    temp->data = value;
    temp->prev = nullptr;
    temp->next = nullptr;
    return temp;
}

void insertAtBeginning(int value) {
    Node* temp = newNode(value);
    if (head == nullptr) {
        head = temp;
        return;
    }
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtEnd(int value) {
    Node* temp = newNode(value);
    if (head == nullptr) {
        head = temp;
        return;
    }
    Node* curr = head;
    while (curr->next != nullptr)
        curr = curr->next;
    curr->next = temp;
    temp->prev = curr;
}

void insertAfter(int key, int value) {
    Node* curr = head;
    while (curr != nullptr && curr->data != key)
        curr = curr->next;
    if (curr == nullptr) {
        cout << "Node " << key << " not found.\n";
        return;
    }
    Node* temp = newNode(value);
    temp->next = curr->next;
    temp->prev = curr;
    if (curr->next != nullptr)
        curr->next->prev = temp;
    curr->next = temp;
}

void insertBefore(int key, int value) {
    Node* curr = head;
    while (curr != nullptr && curr->data != key)
        curr = curr->next;
    if (curr == nullptr) {
        cout << "Node " << key << " not found.\n";
        return;
    }
    Node* temp = newNode(value);
    temp->next = curr;
    temp->prev = curr->prev;
    if (curr->prev != nullptr)
        curr->prev->next = temp;
    else
        head = temp;
    curr->prev = temp;
}

void deleteNode(int key) {
    Node* curr = head;
    while (curr != nullptr && curr->data != key)
        curr = curr->next;
    if (curr == nullptr) {
        cout << "Node " << key << " not found.\n";
        return;
    }
    if (curr->prev != nullptr)
        curr->prev->next = curr->next;
    else
        head = curr->next;
    if (curr->next != nullptr)
        curr->next->prev = curr->prev;
    delete curr;
    cout << "Node " << key << " deleted.\n";
}

void searchNode(int key) {
    Node* curr = head;
    while (curr != nullptr) {
        if (curr->data == key) {
            cout << "Node " << key << " found!\n";
            return;
        }
        curr = curr->next;
    }
    cout << "Node " << key << " not found.\n";
}

void display() {
    Node* curr = head;
    cout << "List: ";
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    int choice, value, key;

    do {
        cout << "\n--- Doubly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Node\n";
        cout << "4. Insert Before a Node\n";
        cout << "5. Delete a Node\n";
        cout << "6. Search a Node\n";
        cout << "7. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(value);
                break;
            case 3:
                cout << "Enter key and value: ";
                cin >> key >> value;
                insertAfter(key, value);
                break;
            case 4:
                cout << "Enter key and value: ";
                cin >> key >> value;
                insertBefore(key, value);
                break;
            case 5:
                cout << "Enter value to delete: ";
                cin >> key;
                deleteNode(key);
                break;
            case 6:
                cout << "Enter value to search: ";
                cin >> key;
                searchNode(key);
                break;
            case 7:
                display();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}

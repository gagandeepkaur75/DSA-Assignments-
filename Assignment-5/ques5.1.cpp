#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

// Insertion at beginning
void insertAtBeginning(int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
    cout << "Inserted at beginning.\n";
}

// Insertion at end
void insertAtEnd(int value) {
    Node* newNode = new Node{value, nullptr};
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
    cout << "Inserted at end.\n";
}

// Insertion before or after a specific node
void insertBeforeAfter(int value, int key, bool before) {
    Node* newNode = new Node{value, nullptr};
    
    if (head == nullptr) {
        cout << "List is empty.\n";
        delete newNode;
        return;
    }

    if (before) {
        if (head->data == key) {
            newNode->next = head;
            head = newNode;
            cout << "Inserted before " << key << ".\n";
            return;
        }

        Node* prev = nullptr;
        Node* curr = head;
        while (curr && curr->data != key) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) {
            cout << "Node " << key << " not found.\n";
            delete newNode;
            return;
        }

        prev->next = newNode;
        newNode->next = curr;
        cout << "Inserted before " << key << ".\n";
    } else {
        Node* curr = head;
        while (curr && curr->data != key) {
            curr = curr->next;
        }

        if (curr == nullptr) {
            cout << "Node " << key << " not found.\n";
            delete newNode;
            return;
        }

        newNode->next = curr->next;
        curr->next = newNode;
        cout << "Inserted after " << key << ".\n";
    }
}

// Deletion from beginning
void deleteFromBeginning() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
    cout << "Deleted from beginning.\n";
}

// Deletion from end
void deleteFromEnd() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
    } else {
        Node* temp = head;
        while (temp->next->next)
            temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }
    cout << "Deleted from end.\n";
}

// Delete specific node
void deleteNode(int value) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Node " << value << " deleted.\n";
        return;
    }

    Node* prev = nullptr;
    Node* curr = head;

    while (curr && curr->data != value) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) {
        cout << "Node " << value << " not found.\n";
        return;
    }

    prev->next = curr->next;
    delete curr;
    cout << "Node " << value << " deleted.\n";
}

// Search for a node and display position
void search(int value) {
    Node* temp = head;
    int position = 1;

    while (temp) {
        if (temp->data == value) {
            cout << "Node " << value << " found at position " << position << ".\n";
            return;
        }
        temp = temp->next;
        position++;
    }

    cout << "Node " << value << " not found.\n";
}

// Display all nodes
void display() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    cout << "List: ";
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Main menu
int main() {
    int choice, value, key;
    char pos;

    do {
        cout << "\n----- Singly Linked List Menu -----\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before/After Node\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete Specific Node\n";
        cout << "7. Search Node\n";
        cout << "8. Display List\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Insert (b)efore or (a)fter a node? ";
                cin >> pos;
                cout << "Enter key node value: ";
                cin >> key;
                insertBeforeAfter(value, key, pos == 'b');
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteNode(value);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                search(value);
                break;
            case 8:
                display();
                break;
            case 9:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 9);

    return 0;
}

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertEnd(int value) {
    Node* temp = new Node();
    temp->data = value;
    if (head == nullptr) {
        head = temp;
        head->next = head;
        return;
    }
    Node* curr = head;
    while (curr->next != head)
        curr = curr->next;
    curr->next = temp;
    temp->next = head;
}

void display() {
    if (head == nullptr) {
        cout << "List is empty.";
        return;
    }
    Node* curr = head;
    do {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
    cout << head->data; 
    cout << endl;
}

int main() {
    insertEnd(20);
    insertEnd(100);
    insertEnd(40);
    insertEnd(80);
    insertEnd(60);

    cout << "Circular Linked List: ";
    display();

    return 0;
}

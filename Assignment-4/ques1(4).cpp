#include <iostream>
using namespace std;

#define SIZE 100

class Queue {
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full!\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = value;
        cout << value << " enqueued to the queue.\n";
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << arr[front] << " dequeued from the queue.\n";
        front++;
        if (front > rear) {
            front = rear = -1;
        }
    }
    bool isEmpty() {
        return front == -1;
    }
    bool isFull() {
        return rear == SIZE - 1;
    }
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
        } else {
            cout << "Front element: " << arr[front] << endl;
        }
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n Queue Operations Menu->\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. isEmpty\n";
        cout << "4. isFull\n";
        cout << "5. Peek\n";
        cout << "6. Display\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            if (q.isEmpty())
                cout << "Queue is empty.\n";
            else
                cout << "Queue is not empty.\n";
            break;
        case 4:
            if (q.isFull())
                cout << "Queue is full.\n";
            else
                cout << "Queue is not full.\n";
            break;
        case 5:
            q.peek();
            break;
        case 6:
            q.display();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
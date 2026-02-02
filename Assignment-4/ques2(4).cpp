//2) Develop a menu driven program demonstrating the following operations on Circular Queues:
//enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().

#include <iostream>
using namespace std;

#define SIZE 5  

class CircularQueue {
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    
    bool isEmpty() {
        return front == -1;
    }

        bool isFull() {
        return (front == (rear + 1) % SIZE);
    }

    
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full!\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }
        arr[rear] = value;
        cout << value << " enqueued to the queue.\n";
    }

    
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }

        cout << arr[front] << " dequeued from the queue.\n";

        if (front == rear) {
           
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
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
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};


int main() {
    CircularQueue q;
    int choice, value;

    do {
        cout << "\n Circular Queue Menu\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. isEmpty\n";
        cout << "4. isFull\n";
        cout << "5. Peek\n";
        cout << "6. Display\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
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
            cout << (q.isEmpty() ? "Queue is empty.\n" : "Queue is not empty.\n");
            break;
        case 4:
            cout << (q.isFull() ? "Queue is full.\n" : "Queue is not full.\n");
            break;
        case 5:
            q.peek();
            break;
        case 6:
            q.display();
            break;
        case 0:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}

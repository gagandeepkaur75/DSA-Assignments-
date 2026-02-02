#include <iostream>
#include <queue>
using namespace std;


class StackTwoQueues {
    queue<int> q1, q2;

public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Popped: " << q1.front() << endl;
        q1.pop();
    }

    void top() {
        if (q1.empty()) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Top element: " << q1.front() << endl;
    }

    bool empty() {
        return q1.empty();
    }
};


class StackOneQueue {
    queue<int> q;

public:
    void push(int x) {
        int size = q.size();
        q.push(x);
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Popped: " << q.front() << endl;
        q.pop();
    }

    void top() {
        if (q.empty()) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Top element: " << q.front() << endl;
    }

    bool empty() {
        return q.empty();
    }
};


int main() {
    StackTwoQueues stack2Q;
    StackOneQueue stack1Q;

    cout << "Using Two Queues:\n";
    stack2Q.push(10);
    stack2Q.push(20);
    stack2Q.top();    
    stack2Q.pop();    
    stack2Q.top();    
    stack2Q.pop();    
    stack2Q.pop();    

    cout << "\nUsing One Queue:\n";
    stack1Q.push(100);
    stack1Q.push(200);
    stack1Q.top();   
    stack1Q.pop();    
    stack1Q.top();    
    stack1Q.pop();   
    stack1Q.pop();   

    return 0;
}

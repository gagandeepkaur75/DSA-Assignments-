#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int>& q) {
    int n = q.size();

    if (n % 2 != 0) {
        cout << "Queue has odd number of elements, cannot interleave properly." << endl;
        return;
    }

    queue<int> firstHalf;
    int halfSize = n / 2;

  
    for (int i = 0; i < halfSize; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

  
    while (!firstHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();

        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;

    
    q.push(4);
    q.push(7);
    q.push(11);
    q.push(20);
    q.push(5);
    q.push(9);

    cout << "Original Queue: ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

   
    interleaveQueue(q);

   
    cout << "Interleaved Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}

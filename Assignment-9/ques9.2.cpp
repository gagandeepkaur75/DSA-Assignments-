#include <iostream>
using namespace std;

void heapUp(int a[], int i) {
    int p = (i - 1) / 2;
    while (i > 0 && a[i] > a[p]) {
        swap(a[i], a[p]);
        i = p;
        p = (i - 1) / 2;
    }
}

void heapDown(int a[], int n, int i) {
    int big = i, l = 2*i + 1, r = 2*i + 2;

    if (l < n && a[l] > a[big]) big = l;
    if (r < n && a[r] > a[big]) big = r;

    if (big != i) {
        swap(a[i], a[big]);
        heapDown(a, n, big);
    }
}

void insertPQ(int a[], int &n, int x) {
    a[n] = x;
    heapUp(a, n);
    n++;
}

int removeMax(int a[], int &n) {
    if (n == 0) return -1;
    int max = a[0];
    a[0] = a[n-1];
    n--;
    heapDown(a, n, 0);
    return max;
}

void show(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int a[100], n = 0, ch, x;

    while (true) {
        cout << "\n1 Insert\n2 Remove Max\n3 Show\n4 Exit\nChoose: ";
        cin >> ch;

        if (ch == 1) {
            cout << "Enter value: ";
            cin >> x;
            insertPQ(a, n, x);
        }
        else if (ch == 2) {
            cout << "Removed: " << removeMax(a, n) << endl;
        }
        else if (ch == 3) {
            show(a, n);
        }
        else break;
    }
}

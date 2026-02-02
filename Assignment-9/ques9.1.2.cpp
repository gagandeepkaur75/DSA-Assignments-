#include <iostream>
using namespace std;

void heapMin(int a[], int n, int i) {
    int small = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] < a[small])
        small = l;

    if (r < n && a[r] < a[small])
        small = r;

    if (small != i) {
        swap(a[i], a[small]);
        heapMin(a, n, small);
    }
}

void sortDec(int a[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapMin(a, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(a[0], a[i]);
        heapMin(a, i, 0);
    }
}

int main() {
    int a[] = {10, 3, 15, 7, 8, 23, 1};
    int n = sizeof(a) / sizeof(a[0]);

    sortDec(a, n);

    cout << "Decreasing: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

#include <iostream>
using namespace std;

void heap(int a[], int n, int i) {
    int big = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[big])
        big = l;

    if (r < n && a[r] > a[big])
        big = r;

    if (big != i) {
        swap(a[i], a[big]);
        heap(a, n, big);
    }
}

void sortInc(int a[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heap(a, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(a[0], a[i]);
        heap(a, i, 0);
    }
}

int main() {
    int a[] = {10, 3, 15, 7, 8, 23, 1};
    int n = sizeof(a) / sizeof(a[0]);

    sortInc(a, n);

    cout << "Increasing: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

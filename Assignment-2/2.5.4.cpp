#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter dimension of upper triangular matrix: ";
    cin >> n;

    int size = n*(n+1)/2;
    int upper[size];

    cout << "Enter upper triangular elements row-wise:\n";
    for (int i = 0; i < size; i++) {
        cin >> upper[i];
    }

    cout << "Full Upper Triangular Matrix:\n";
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j)
                cout << upper[index++] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }

    return 0;
}

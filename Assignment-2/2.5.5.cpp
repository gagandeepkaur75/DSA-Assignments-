#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter dimension matrix: ";
    cin >> n;

    int size = n*(n+1)/2;
    int sym[size];

    cout << "Enter lower triangle elements \n";
    for (int i = 0; i < size; i++) {
        cin >> sym[i];
    }

    cout << " Symmetric Matrix:\n";
    for (int i = 0;i < n; i++) {
        for (int j = 0; j < n; j++) {
            int index;
            if (i >= j)
                index = i*(i+1)/2 + j; // lower triangle
            else
                index = j*(j+1)/2 + i; // upper 
            cout << sym[index] << " ";
        }
        cout << endl;
    }
    return 0;
}

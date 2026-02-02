#include <iostream>
using namespace std;

int main() {
    
    int A[2][2] = { {1, 2}, {3, 4} };

    
    cout << "Sum of row:\n";
    for (int i = 0; i < 2; i++) {
        int sum = 0;
        for (int j = 0; j < 2; j++) {
            sum = sum + A[i][j]; // add each element in the row
        }
        cout << "Row " << i << " = " << sum << endl;
    }

    
    cout << "Sum of  column:\n";
    for (int j = 0; j < 2; j++) {
        int sum = 0;
        for (int i = 0; i < 2; i++) {
            sum = sum + A[i][j]; 
        }
        cout << "Column " << j << " = " << sum << endl;
    }

    return 0;
}

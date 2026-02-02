#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int A[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int count = 0;

    // Check distinct elements
    for (int i = 0; i < n; i++) {
        bool isDistinct = true;
        // Check if A[i] appeared earlier
        for (int j = 0; j < i; j++) {
            if (A[i] == A[j]) {
                isDistinct = false;
                break;
            }
        }
        if (isDistinct) {
            count++;
        }
    }

    cout << "Total number of distinct elements = " << count << endl;

    return 0;
}

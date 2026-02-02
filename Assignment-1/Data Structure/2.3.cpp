#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 6, 7, 8}; 
    int n = sizeof(arr) / sizeof(arr[0]);

    int missing = -1; 

    for (int i = 0; i < n - 1; i++) {
        if (arr[i+1] - arr[i] != 1) {
            missing = arr[i] + 1;
            break;
        }
    }

    if (missing != -1)
        cout << "Missing number is: " << missing << endl;
    else
        cout << "No number is missing." << endl;

    return 0;
}

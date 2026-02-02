#include<iostream>
using namespace std;

int main() {
    
    int A[3][3] = {
        {0, 0, 1},
        {0, 2, 2},
        {1, 1, 3}
    };
    int sizeA = 3;

    
    int B[3][3] = {
        {0, 1, 4},
        {2, 0, 5},
        {2, 2, 6}
    };
    int sizeB = 3;

    
    int C[100][3];
    int k = 0; 
    
    int temp[10][10] = {0};

    
    for (int i = 0; i < sizeA; i++) {
        for (int j = 0; j < sizeB; j++) {
            if (A[i][1] == B[j][0]) { 
                int row = A[i][0];
                int col = B[j][1];
                temp[row][col] += A[i][2] * B[j][2];
            }
        }
    }

    // Convert result (temp) back to sparse form
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (temp[i][j] != 0) {
                C[k][0] = i;
                C[k][1] = j;
                C[k][2] = temp[i][j];
                k++;
            }
        }
    }

    // Print result
    cout << "Resultant Sparse Matrix (A x B):\n";
    cout << "Row  Col  Val\n";
    for (int x = 0; x < k; x++) {
        cout << C[x][0] << "    "
             << C[x][1] << "    "
             << C[x][2] << endl;
    }

    return 0;
}


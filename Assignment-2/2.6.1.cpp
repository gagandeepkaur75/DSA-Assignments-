#include <iostream>
using namespace std;


void transpose(int sparse[][3], int result[][3]) {
    int rows = sparse[0][0];     
    int cols = sparse[0][1];
    int nonZero = sparse[0][2];  // number of non-zero elements

    
    result[0][0] = cols;
    result[0][1] = rows;
    result[0][2] = nonZero;

    int k = 1; // index for result
    // Go column by column in original
    for (int col = 0; col < cols; col++) {
        for (int i = 1; i <= nonZero; i++) {
            if (sparse[i][1] == col) {
                result[k][0] = sparse[i][1]; // new row = old col
                result[k][1] = sparse[i][0]; // new col = old row
                result[k][2] = sparse[i][2]; // value remains same
                k++;
            }
        }
    }
}

int main() {

    int sparse[5][3] = {
        {4, 5, 4},   
        {0, 1, 10},  // element at (0,1) = 10
        {1, 3, 20},  // element at (1,3) = 20
        {2, 2, 30},  // element at (2,2) = 30
        {3, 0, 40}   // element at (3,0) = 40
    };

    int result[5][3]; // to store transpose

    // Call function
    transpose(sparse, result);

    // Print original
    cout<< "Original Sparse Matrix (3-tuple form):\n";
    for (int i = 0; i < 5; i++) {
        cout << sparse[i][0] << " "
             << sparse[i][1] << " "
             << sparse[i][2]<<endl;
    }

    // Print transpose
    cout << "\nTranspose Sparse Matrix (3-tuple form):\n";
    for (int i = 0; i < 5; i++) {
        cout << result[i][0] << " "
             << result[i][1] << " "
             << result[i][2] << endl;
    }

    return 0;
}

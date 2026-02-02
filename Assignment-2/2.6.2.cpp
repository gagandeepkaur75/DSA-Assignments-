#include<iostream>
using namespace std;

void add(int A[][3],int B[][3],int result[][3]){

    if(A[0][0]!=B[0][0]||A[0][1]!=B[0][1]){
        cout<<"addition not possible";
        return ;
    }
    int i=1,j=1,k=1;
    result[0][0]=A[0][0];
    result[0][1]=A[0][1];


    while(i<=A[0][2]&&j<=B[0][2]){
        if(A[i][0]==B[j][0]&&A[i][1]==B[j][1]){
            result[k][0]=A[i][0];
            result[k][1]=A[i][1];
            result[k][2]=A[i][2]+B[j][2];
            i++,k++,j++;

            }else if(A[i][0]<B[j][0]&&A[i][1]<B[j][0]){
             result[k][0]=A[i][0];
            result[k][1]=A[i][1];
            result[k][2]=A[i][2];
             i++,k++;
                 }else
        result[k][0]=B[i][0];
            result[k][1]=B[i][1];
            result[k][2]=B[i][2];
           j++,k++;
                }
            }
void printMatrix(int matrix[][3], int rows) {
    for (int i = 0; i < rows; i++) {
        cout << matrix[i][0] << " " << matrix[i][1] << " " << matrix[i][2] << endl;
    }
}
            int main() {
    int A[3][3] = {
        {3, 3, 2},   // rows, cols, non-zero
        {0, 1, 5},   // row, col, value
        {2, 2, 8}
    };

    // Example sparse matrix B (3x3, 2 non-zero)
    int B[3][3] = {
        {3, 3, 2},
        {0, 1, 3},
        {2, 2, 2}
    };

    // Result matrix (max size = sum of non-zero elements + 1)
    int result[5][3];  // Enough space for result

    cout << "Matrix A:\n";
    printMatrix(A, A[0][2] + 1);

    cout << "\nMatrix B:\n";
    printMatrix(B, B[0][2] + 1);

    // Add matrices
    add(A, B, result);

    cout << "\nResult of A + B:\n";
    printMatrix(result, result[0][2] + 1);

    return 0;
}

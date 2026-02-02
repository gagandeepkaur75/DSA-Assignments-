#include<iostream>
using namespace std;

int main(){
     int n;
cout<<"enter dimensions:";
cin>>n;

int tri[3*n - 2]; // 3n - 2 non-zero elements

cout << "Enter elements (first lower, then main, then upper diagonals):\n";
    for (int i = 0; i < 3*n - 2; i++) {
        cin >> tri[i];
    }
    cout << "Full Tri-diagonal Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i - j == 1)
                cout << tri[i - 1] << " ";           // Lower
            else if (i == j)
                cout << tri[n - 1 + i] << " ";        // Main
            else if (j - i == 1)
                cout << tri[2*n - 1 + i] << " ";      // Upper
            else
                cout << "0 ";
        }
        cout << endl;
    }

    return 0;
}

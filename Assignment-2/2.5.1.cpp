#include<iostream>
using namespace std;
int main(){

     int n;
cout<<"enter dimensions:";
cin>>n;

int diag[n];
cout<<"enter diagonals elements:";
for(int i=0;i<n;i++){
    cin>>diag[i];
}
cout<<"\nfull matrix:\n";
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(i==j)
        cout<<diag[i]<<" ";
        else
        cout<<"0 ";
        

        }
        cout<<endl;
 
   }
   
   delete[] diag;
   return 0;
}

#include<iostream>
using namespace std;

int main(){
    int n,key;


    cout<<"enter number of elements:";
    cin>>n;

    int arr[n];

    cout<<"enter elements in sorted order:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"enter values to search:";
    cin>>key;
    int low = 0, high = n - 1, mid;
    int foundIndex = -1;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == key) {
            foundIndex = mid; 
            break;
        }
        else if (arr[mid] < key) {
            low = mid + 1; 
         } else {
            high = mid - 1;
        }
    }

    if (foundIndex != -1) {
        cout << "Element found at position " << foundIndex + 1 << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
    

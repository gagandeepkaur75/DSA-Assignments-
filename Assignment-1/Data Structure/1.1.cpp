Assignment 1
Ques1.1
#include<iostream>
using namespace std;

int arr[100];
int n=0;

void createArray(){
    cout<<"enter number of elements:";
    cin>>n;
    cout<<"enter"<<n<<"elements:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}

void displayArray(){
    cout<<"Array elements:";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" "<<endl;

    }
}

void insertElement(){
    int pos,value;
    cout<<"enter position:";
    cin>>pos;
    cout<<"enter value:";
    cin>>value;


    for(int i=n;i>pos;i--){
        arr[i]=arr[i-1];

    }
    arr[pos]=value;
    n++;
}

void deleteElements(){
    int pos;
    cout<<"enter position to delete:";
    cin>>pos;
    for(int i=pos;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    n--;
}

void linearSearch(){
    int search,found=0;
    cout<<"enter value to search:";
    cin>>search;

    for(int i=0;i<n;i++){
        if(arr[i]==search){
            cout<<"element found:"<<endl;

            found=1;
            break;
        }
    }
    if(!found){
        cout<<"element not found!"<<endl;
    }
}

void exitProgram(){
    cout<<"exiting...";

}

int main(){

    int choice;
    do{
        cout<<"\n.......MENU........\n";
        cout<<"1.Create\n2.Display\n3.Insert\n4.Delete\n5.Linear Search\n6.Exit\n";

        cout<<"enter choice:";
        cin>>choice;

        switch(choice){
            case 1:createArray();
            break;
            case 2:displayArray();
            break;
            case 3:insertElement();
            break;
            case 4:deleteElements();
            break;
            case 5:linearSearch();
            break;
            case 6:exitProgram();
            break;

            default:cout<<"invalid choice\n";
        }
    }while(choice!=6);


    return 0;
}

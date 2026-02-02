#include <iostream>

using namespace std;
class String{
    string str;
    public:
    void setstring(){
        cout<<"enter a string:";
        getline(cin,str);
    }
    void reversestring(){
        int n=str.length();

        char stack[100];
        int top=-1;
for(int i=0;i<n;i++){
    stack[++top]=str[i];
}

cout<<"reversed string:";
while(top>=0){
    cout<<stack[top--];

}
cout<<endl;

    }
};

int main() {
    String sr;
    sr.setstring();
    sr.reversestring();

    
    
    return 0;
}

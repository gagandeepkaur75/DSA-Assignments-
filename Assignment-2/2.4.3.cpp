#include<iostream>
using namespace std;

int main(){
    char str[100],result[100];
    int i,j=0;

    cout<<"enter a string:";
    cin>>str;

    for(i=0;str[i]!='\0';i++){
        if(str[i]!='a'&& str[i]!='e'
        &&
        str[i]!='i'&& str[i]!='o'
        &&
        str[i]!='u' 
        &&
        str[i]!='A'&& str[i]!='E'
        &&
        str[i]!='I'&& str[i]!='O'
        &&
        str[i]!='U')

        result[j]=str[i]; //copy
        j++;
    }
    
    result[j]='\0';
    cout<<"string with no vowel:"<<result;

    return 0;
}

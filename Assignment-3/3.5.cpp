#include <iostream>
using namespace std;

int top = -1;
int stack[100]; 


void push(int x) {
    stack[++top] = x;
}


int pop() {
    return stack[top--];
}


int evaluatePostfix(string postfix) {
    for(int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];

        if(isdigit(ch)) {
            push(ch - '0');
        } else {
            int b = pop();
            int a = pop();

            if(ch == '+') push(a + b);
            else if(ch == '-') push(a - b);
            else if(ch == '*') push(a * b);
            else if(ch == '/') push(a / b);
        }
    }
    return pop(); 
}

int main() {
    string postfix;
    cout << "Enter a postfix expression (single-digit numbers): ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;

    return 0;
}

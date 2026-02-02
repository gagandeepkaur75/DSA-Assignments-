#include <iostream>
using namespace std;

int top = -1;
char stack[100];


void push(char c) {
    stack[++top] = c;
}


char pop() {
    return stack[top--];
}


char peek() {
    return stack[top];
}


bool isEmpty() {
    return top == -1;
}


int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(string infix) {
    string postfix = "";
    for(int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        if(isdigit(ch) || isalpha(ch)) {
            postfix += ch;
        } 
        else if(ch == '(') {
            push(ch);
        } 
        else if(ch == ')') {
            while(!isEmpty() && peek() != '(') {
                postfix += pop();
            }
            pop(); 
        } 
        else {
            while(!isEmpty() && precedence(peek()) >= precedence(ch)) {
                postfix += pop();
            }
            push(ch);
        }
    }
    while(!isEmpty()) {
        postfix += pop();
    }
    return postfix;
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}

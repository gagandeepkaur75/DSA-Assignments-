#include <iostream>

using namespace std;

class Stack
{
    char arr[100];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(char ch)
    {
        arr[++top] = ch;
    }
    void pop()
    {
        if (top != -1)
            top--;
    }
    char getTop()
    {
        if (top == -1)
            return '\0';
        return arr[top];
    }
    bool isEmpty()
    {
        return top == -1;
    }
};

bool isbalanced(string expr)
{
    Stack s;
    for (int i = 0; i < expr.length(); i++)
    {
        char ch = expr[i];

        if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            if (s.isEmpty())
            {
                return false;
            }
            s.pop();
        }
    }
    return s.isEmpty();
}

int main()
{

    string expr;
    cout << "enter expression:";
    getline(cin, expr);

    if (isbalanced(expr))
    {
        cout << "balanced";
    }
    else
    {
        cout << "NOT  balanced parentheses." << endl;
    }

    return 0;
}

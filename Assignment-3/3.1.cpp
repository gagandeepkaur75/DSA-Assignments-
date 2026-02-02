#include <iostream>

using namespace std;
class Stack
{
    int capacity;
    int *arr;
    int top;

public:
    Stack(int c)
    {
        this->capacity = c;
        arr = new int[c];
        this->top = -1;
    }
    void push(int data)
    {
        if (this->top == this->capacity - 1)
        {
            cout << "overflow:\n";
            return;
        }
        this->top++;
        this->arr[this->top] = data;
    }
    int pop()
    {
        if (this->top == -1)
        {
            cout << "underflow";
            return INT16_MIN;
        }
        this->top--;
    }
    int peek()
    {
        if (this->top == -1)
        {
            cout << "underflow";
            return INT16_MIN;
        }
        return this->arr[this->top];
    }
    bool isempty()
    {
        return this->top == -1;
    }
    bool isfull()
    {
        return this->top == this->capacity - 1;
    }

    void display()
    {
        if (this->top == -1)
        {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements are:";
        for (int i = this->top; i >= 0; i--)
        {
            cout << this->arr[i] << " ";
        }
        cout << "\n";
    }
};

int main()
{
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    cout << "top element " << st.peek() << "\n";
    st.display();
    st.push(8);
    st.push(8);
    cout << "top element" << st.peek() << "\n";
    st.display();
    st.push(10);
    st.pop();
    st.pop();
    st.pop();
    cout << "top element" << st.peek() << "\n";
    st.display();
    st.push(110);
    cout << st.peek() << "\n";
    return 0;
}

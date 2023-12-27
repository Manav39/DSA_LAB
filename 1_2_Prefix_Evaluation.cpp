#include <bits/stdc++.h>
#define MAX 10
using namespace std;

class Stack
{
private:
    int *arr;
    int top;

public:
    Stack()
    {
        arr = new int[MAX];
        top = -1;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        if (top == MAX - 1)
        {
            return true;
        }
        return false;
    }

    void push(int data)
    {
        if (isFull())
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = data;
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        else
        {
            return arr[top];
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        cout << "Stack is : ";
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack st;
    string s;
    cout << "Enter a prefix expression : ";
    cin >> s;
    int len = s.length();
    for (int i = len - 1; i >= 0; i--)
    {
        char ch = s[i];
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        {
            int a = st.pop();
            int b = st.pop();
            switch (ch)
            {
            case '+':
            {
                int res = a + b;

                st.push(res);
                break;
            }
            case '-':
            {
                int res = a - b;
                st.push(res);
                break;
            }
            case '*':
            {
                int res = a * b;
                st.push(res);
                break;
            }
            case '/':
            {
                int res = a / b;
                st.push(res);
                break;
            }
            case '^':
            {
                int res = a ^ b;
                st.push(res);
                break;
            }
            }
        }
        else
        {
            st.push(ch - 48);
        }
        st.display();
    }
    cout << st.pop() << endl;
    return 0;
}
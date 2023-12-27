#include <bits/stdc++.h>
#define MAX 10
using namespace std;

class Stack
{
private:
    char *arr;
    int top;

public:
    Stack()
    {
        arr = new char[MAX];
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

    void push(char data)
    {
        if (isFull())
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = data;
    }
    char pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return 'W';
        }
        return arr[top--];
    }

    char peek()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return 'W';
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
    cout << "Enter the expression : " << endl;
    cin >> s;
    for (char ch : s)
    {
        if (ch == '(' || ch == '[' || ch == '{')
        {
            st.push(ch);
        }
        else
        {
            if (ch == ']' || ch == '}' || ch == ')')
            {
                if (st.isEmpty())
                {
                    cout << "Not a Valid Expression" << endl;
                    return 0;
                }
                if ((ch == ']' && st.peek() == '[') || (ch == '}' && st.peek() == '{') || (ch == ')' && st.peek() == '('))
                {
                    st.pop();
                }
            }
        }
    }
    if (st.isEmpty())
    {
        cout << "Valid Expression" << endl;
    }
    else
    {
        cout << "Not a Valid Expression" << endl;
    }
    return 0;
}
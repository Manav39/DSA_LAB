#include <bits/stdc++.h>
#define MAX 100
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
    Stack s1, s2, s3;
    string first, second;
    cout << "Enter the first Number : " << endl;
    cin >> first;
    cout << "Enter the second Number : " << endl;
    cin >> second;

    for (char ch : first)
    {
        s1.push(ch - 48);
    }
    for (char ch : second)
    {
        s2.push(ch - 48);
    }
    int carry = 0;
    while (!s1.isEmpty() || !s2.isEmpty() || carry != 0)
    {
        int a, b;
        if (s1.isEmpty())
        {
            a = 0;
        }
        else
        {
            a = s1.pop();
        }

        if (s2.isEmpty())
        {
            b = 0;
        }
        else
        {
            b = s2.pop();
        }

        int res = a + b + carry;
        s3.push(res % 10);
        carry = res / 10;
    }
    s3.display();
    return 0;
}
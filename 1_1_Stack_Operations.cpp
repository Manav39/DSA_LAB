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
    int choice;
    do
    {
        cout << "Select an option : \n1:Push\n2:Pop\n3:Peek\n4:Display\n5:exit\nEnter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the data to be pushed : ";
            int data;
            cin >> data;
            st.push(data);
            break;
        case 2:
        {
            int ans = st.pop();
            if (ans != -1)
            {
                cout << "Popped Element is : " << ans << endl;
            }
            break;
        }
        case 3:
        {
            int ans = st.peek();
            if (ans != -1)
            {
                cout << "Element At the top of Stack is : " << ans << endl;
            }
            break;
        }
        case 4:
            st.display();
            break;
        }
    } while (choice != 5);

    return 0;
}
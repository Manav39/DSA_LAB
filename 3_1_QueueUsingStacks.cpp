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
            cout << "Queue Overflow" << endl;
            return;
        }
        top++;
        arr[top] = data;
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
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
            cout << "Queue Underflow" << endl;
            return;
        }
        cout << "Queue is : ";
        for (int i = 0; i <= top; i++)
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
        cout << "Select an option : \n1:Enqueue\n2:Dequeue\n3:Front Value\n4:Rear Value\n5:Display\n6:Exit\nEnter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the data to be enqueued : ";
            int data;
            cin >> data;
            st.push(data);
            break;
        case 2:
        {
            Stack st2;
            while (!st.isEmpty())
            {
                st2.push(st.pop());
            }
            int ans = st2.pop();
            while (!st2.isEmpty())
            {
                st.push(st2.pop());
            }
            cout << "Dequeue element is : " << ans << endl;
            break;
        }
        case 3:
        {
            Stack st2;
            while (!st.isEmpty())
            {
                st2.push(st.pop());
            }
            int ans = st2.peek();
            while (!st2.isEmpty())
            {
                st.push(st2.pop());
            }
            if (ans != -1)
            {
                cout << "Element At the Front  is : " << ans << endl;
            }
            break;
        }
        case 4:
        {
            cout << "Element at rear is : " << st.peek() << endl;
            break;
        }
        case 5:
        {
            st.display();
            break;
        }
        }
    } while (choice != 6);
    return 0;
}
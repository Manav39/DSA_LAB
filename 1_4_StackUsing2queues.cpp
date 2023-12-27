#include <bits/stdc++.h>
#define MAX 10
using namespace std;

class Queue
{
private:
    int *arr;
    int front;
    int rear;

public:
    Queue()
    {
        arr = new int[MAX];
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        if ((front == -1 && rear == -1) || front > rear)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        if (rear == MAX - 1)
        {
            return true;
        }
        return false;
    }

    void enqueue(int data)
    {
        if (isFull())
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        rear++;
        if (rear == 0)
        {
            front = 0;
        }
        arr[rear] = data;
    }
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return arr[front++];
    }

    int frontValue()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }
    int rearValue()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        else
        {
            return arr[rear];
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
        for (int i = rear; i >= front; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void reverseQueue(Queue &temp)
    {
        for (int i = rear; i >= front; i--)
        {
            temp.enqueue(arr[i]);
        }
    }
};

int main()
{
    Queue q1;
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
            q1.enqueue(data);
            break;
        case 2:
        {
            if (q1.isEmpty())
            {
                cout << "Stack Underflow" << endl;
            }
            else
            {
                Queue q2;
                q1.reverseQueue(q2);
                int ans = q2.dequeue();
                while (!q1.isEmpty())
                {
                    q1.dequeue();
                }
                q2.reverseQueue(q1);
                if (ans != -1)
                {
                    cout << "Popped Element is : " << ans << endl;
                }
            }
            break;
        }
        case 3:
        {
            int ans = q1.rearValue();
            if (ans != -1)
            {
                cout << "Element At the top of Stack is : " << ans << endl;
            }
            break;
        }
        case 4:
            q1.display();
            break;
        }
    } while (choice != 5);
}

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
            cout << "Queue Overflow" << endl;
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
            cout << "Queue Underflow" << endl;
            return -1;
        }
        return arr[front++];
    }

    int frontValue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
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
            cout << "Queue Underflow" << endl;
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
            cout << "Queue Underflow" << endl;
            return;
        }
        cout << "Queue is : ";
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
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
            q.enqueue(data);
            break;
        case 2:
        {
            int ans = q.dequeue();
            if (ans != -1)
            {
                cout << "Dequeued element is : " << ans << endl;
            }
            break;
        }
        case 3:
        {
            int ans = q.frontValue();
            if (ans != -1)
            {
                cout << "Element At Front is : " << ans << endl;
            }
            break;
        }
        case 4:
        {
            int ans = q.rearValue();
            if (ans != -1)
            {
                cout << "Element At Rear is : " << ans << endl;
            }
            break;
        }
        case 5:
        {
            q.display();
            break;
        }
        }
    } while (choice != 6);
    return 0;
}

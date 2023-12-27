#include <bits/stdc++.h>
#define MAX 5
using namespace std;

class CiruclarQueue
{
private:
    int *arr;
    int front;
    int rear;

public:
    CiruclarQueue()
    {
        arr = new int[MAX];
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        if (rear == MAX - 1 && front == 0)
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
        else if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else if (rear == MAX - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear = rear + 1;
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
        int val = arr[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            if (front == MAX - 1)
            {
                front = 0;
            }
            else
            {
                front = front + 1;
            }
        }
        return val;
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
        for (int i = front; i != rear; i = (i + 1) % MAX)
        {
            cout << arr[i] << " ";
        }
        cout << arr[rear] << endl;
    }
};

int main()
{
    CiruclarQueue q;
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

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

int getLength(Node *);

void insert(Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (tail == NULL)
    {
        tail = newNode;
        tail->next = newNode;
        tail->prev = newNode;
        return;
    }
    newNode->next = tail->next;
    tail->next->prev = newNode;
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void print(Node *tail)
{
    if (tail == NULL)
    {
        cout << "Linked List is empty" << endl;
        return;
    }
    Node *temp = tail->next;
    if (temp->next != temp)
    {
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != tail);
    }

    cout << tail->data << endl;
}

Node *johnson(Node *&tail)
{
    Node *temp = tail->next;
    while (getLength(tail) > 1)
    {
        int cnt = 1;
        Node *prev = NULL;
        while (cnt != 3)
        {
            prev = temp;
            temp = temp->next;
            cnt++;
        }
        if (temp == tail)
        {
            prev->next = tail->next;
            tail->next->prev = prev;
            tail = prev;
            print(tail);
        }
        else
        {
            prev->next = temp->next;
            temp->next->prev = prev;
            print(tail);
            Node *forward = prev->next;
            temp = forward;
        }
    }
}

int getLength(Node *tail)
{
    Node *temp = tail->next;
    Node *prev = NULL;
    int len = 1;
    while (temp != tail)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

int main()
{
    Node *tail = NULL;
    insert(tail, 1);
    print(tail);
    insert(tail, 2);
    print(tail);
    insert(tail, 3);
    print(tail);
    insert(tail, 4);
    print(tail);
    insert(tail, 5);
    print(tail);
    insert(tail, 6);
    print(tail);
    johnson(tail);

    return 0;
}
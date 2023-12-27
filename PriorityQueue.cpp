#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        cout << this->data << endl;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is Free" << endl;
    }
};

void insert(Node *&head, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    if (head->data < data)
    {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node *curr = head;
    Node *prev = NULL;
    while (curr->data > data)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL)
    {
        prev->next = newNode;
        return;
    }
    prev->next = newNode;
    newNode->next = curr;
}

int Max(Node *&head)
{
    if (head == NULL)
    {
        cout << "Queue Underflow";
    }
    return head->data;
}

int extractMax(Node *&head)
{
    if (head == NULL)
    {
        cout << "Queue Underflow";
    }
    int val = head->data;
    head = head->next;
    return val;
}

void display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    insert(head, 5);
    display(head);
    insert(head, 10);
    display(head);
    insert(head, 20);
    display(head);
    insert(head, 15);
    display(head);
    cout << "Extract Max : " << extractMax(head) << endl;
    display(head);
    cout << "Max : " << Max(head) << endl;
    display(head);
    return 0;
}
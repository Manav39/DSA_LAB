#include <iostream>
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

void insertAtBeginning(Node *&head, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAtEnd(Node *&head, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtBetween(Node *&head, int data, int element)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    if (element == head->data)
    {
        insertAtBeginning(head, data);
        return;
    }
    Node *temp = head;
    Node *prev = NULL;
    while (temp->data != element && temp != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Element Not Found" << endl;
        return;
    }
    prev->next = newNode;
    newNode->prev = prev;
    newNode->next = temp;
    temp->prev = newNode;
}

void print(Node *head)
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
    insertAtBeginning(head, 10);
    print(head);
    insertAtBeginning(head, 20);
    print(head);
    insertAtEnd(head, 30);
    print(head);
    insertAtBetween(head, 25, 10);
    print(head);
    insertAtBetween(head, 35, 20);
    print(head);
    return 0;
}
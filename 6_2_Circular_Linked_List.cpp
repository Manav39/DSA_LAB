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
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is Free" << endl;
    }
};

void insertNode(Node *&tail, int pos, int data)
{
    if (tail == NULL)
    {
        Node *newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
        return;
    }

    Node *curr = tail;
    while (curr->data != pos)
    {
        curr = curr->next;
    }
    Node *temp = new Node(data);
    temp->next = curr->next;
    curr->next = temp;
}

void deleteNode(Node *&tail, int ValueToBeDeleted)
{
    if (tail == NULL)
    {
        cout << "List is Empty" << endl;
        return;
    }
    else
    {
        Node *check = tail;
        Node *prev = tail;
        Node *curr = tail->next;
        while (curr->data != ValueToBeDeleted)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;

        if (curr == prev)
        {
            tail = NULL;
            return;
        }

        if (tail == curr)
        {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

void display(Node *tail)
{
    if (tail == NULL)
    {
        cout << "Linked List is empty" << endl;
        return;
    }
    Node *temp = tail;
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}

int main()
{
    Node *tail = NULL;
    int choice;
    do
    {
        cout << "Select An Option : \n1:Insert\n2:Delete\n3:Display\n4:Exit\nEnter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Enter the value to be inserted : ";
            int val;
            cin >> val;
            cout << "Enter elements data after which you want to insert data : ";
            int pos;
            cin >> pos;
            insertNode(tail, pos, val);
            break;
        }
        case 2:
        {
            cout << "Enter the value of the node to be deleted : ";
            int val;
            cin >> val;
            deleteNode(tail, val);
            break;
        }
        case 3:
        {
            display(tail);
            break;
        }
        }
    } while (choice != 4);
    return 0;
}
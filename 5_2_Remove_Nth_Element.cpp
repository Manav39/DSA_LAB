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

void deleteNthLast(Node *&);

void InsertAtBeginning(Node *&head, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void InserAtEnd(Node *&head, int data)
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
    return;
}

void InsertAtBetween(Node *&head, int data, int pos)
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    if (pos > len)
    {
        cout << "Wrong Position " << endl;
        return;
    }
    if (pos == 1)
    {
        InsertAtBeginning(head, data);
        return;
    }
    temp = head;
    int cnt = 1;
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL)
    {
        InserAtEnd(head, data);
        return;
    }
    Node *newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

int getLength(Node *head)
{
    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}
void display(Node *head)
{
    if (head == NULL)
    {
        cout << "Linked List in Empty" << endl;
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteAtBeginning(Node *&head)
{
    if (head == NULL)
    {
        cout << "Linked List is Empty " << endl;
        return;
    }
    cout << "Deleted Element is : " << head->data << endl;
    head = head->next;
    return;
}

void deleteAtEnd(Node *&head)
{
    if (head == NULL)
    {
        cout << "Linked List is Empty " << endl;
        return;
    }
    Node *temp = head;
    if (temp->next == NULL)
    {
        head = NULL;
        return;
    }
    if (temp->next->next == NULL)
    {
        temp->next = NULL;
        return;
    }

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    cout << "Deleted Element is : " << temp->next->data << endl;
    temp->next = NULL;
    return;
}

void deleteAtBetween(Node *&head)
{
    if (head == NULL)
    {
        cout << "Linked List is Empty " << endl;
        return;
    }
    int data;
    cout << "Enter the data to be deleted : " << endl;
    cin >> data;
    Node *curr = head;
    if (curr->data == data)
    {
        head = head->next;
        return;
    }
    Node *prev = NULL;
    if (curr == NULL)
    {
        return;
    }
    while (curr != NULL && curr->data != data)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL)
    {
        cout << "Element Not Found" << endl;
        return;
    }
    if (curr->next == NULL)
    {
        prev->next = NULL;
        return;
    }
    prev->next = curr->next;
    return;
}

void deleteNthLast(Node *&head)
{
    int n;
    cout << "Enter the value of n to be deleted from last : ";
    cin >> n;
    if (n == getLength(head))
    {
        head = head->next;
        return;
    }
    if (getLength(head) < n)
    {
        cout << "Value of N is greater than the Linked List Length" << endl;
        return;
    }
    Node *fast = head;
    Node *slow = head;
    for (int i = 1; i < n; i++)
    {
        fast = fast->next;
    }
    cout << "Fast : " << fast->data << endl;
    Node *prev = NULL;
    while (fast->next != NULL)
    {
        prev = slow;
        fast = fast->next;
        slow = slow->next;
    }
    if (slow->next == NULL)
    {
        prev->next = NULL;
        return;
    }
    prev->next = slow->next;
    cout << "Linked List after Deleting : \n";
    display(head);
    return;
}

int main()
{
    Node *head = NULL;
    int choice;
    do
    {
        cout << "Select an Option : \n1:Insert At Beginning\n2:Insert At End\n3:Insert At Specific Position\n4:Delete At Beginning\n5:Delete At End \n6:Delete a Specific Element \n7:Display \n8:Exit\nEnter your choice : " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int data;
            cout << "Enter the data to be inserted : ";
            cin >> data;
            InsertAtBeginning(head, data);
            break;
        }
        case 2:
        {
            int data;
            cout << "Enter the data to be inserted : ";
            cin >> data;
            InserAtEnd(head, data);
            break;
        }
        case 3:
        {
            int data;
            cout << "Enter the data to be inserted : ";
            cin >> data;
            int pos;
            cout << "Enter the position where the data to be inserted : ";
            cin >> pos;
            InsertAtBetween(head, data, pos);
            break;
        }
        case 4:
        {
            deleteAtBeginning(head);
            break;
        }
        case 5:
        {
            deleteAtEnd(head);
            break;
        }
        case 6:
        {
            deleteAtBetween(head);
            break;
        }
        case 7:
        {
            display(head);
            break;
        }
        }
    } while (choice != 8);

    cout << "Your Linked List is : \n";
    display(head);
    deleteNthLast(head);
    return 0;
}
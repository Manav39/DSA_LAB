#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;

    Node(int data)
    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

bool searchNode(Node *root, int val)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == val)
    {
        return true;
    }

    return (val > root->data) ? searchNode(root->right, val) : searchNode(root->left, val);
}

Node *InsertIntoBst(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if (root->data > data)
    {
        root->left = InsertIntoBst(root->left, data);
        return root;
    }
    else
    {
        root->right = InsertIntoBst(root->right, data);
        return root;
    }
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = InsertIntoBst(root, data);
        cin >> data;
    }
}

Node *getMinValue(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

Node *getMaxValue(Node *root)
{
    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

Node *deleteFromBst(Node *root, int val)
{
    if (root == NULL)
    {
        return root;
    }

    if (root->data == val)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->right != NULL && root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        if (root->left != NULL && root->right != NULL)
        {
            int minimumVal = getMinValue(root->right)->data;
            root->data = minimumVal;
            root->right = deleteFromBst(root->right, minimumVal);
            return root;
        }
    }
    else if (root->data > val)
    {
        root->left = deleteFromBst(root->left, val);
        return root;
    }
    else
    {
        root->right = deleteFromBst(root->right, val);
        return root;
    }
}

Node *inorderSuccesor(Node *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }
    Node *succ = NULL;
    while (root)
    {
        if (root->data <= val)
        {
            root = root->right;
        }
        else
        {
            succ = root;
            root = root->left;
        }
    }
    return succ;
}

Node *InorderPre(Node *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }
    Node *pre = NULL;
    while (root)
    {
        if (root->data >= val)
        {
            root = root->left;
        }
        else
        {
            pre = root;
            root = root->right;
        }
    }
    return pre;
}

int main()
{
    Node *root = NULL;
    cout << "Enter data to create BST :  " << endl;
    takeInput(root);
    cout << "Printing the BST" << endl;
    levelOrderTraversal(root);
    int val;
    cout << "Enter the element to be searched in BST" << endl;
    cin >> val;
    if (searchNode(root, val))
    {
        cout << "Element is Present" << endl;
    }
    else
    {
        cout << "Element is not present" << endl;
    }

    cout << "Min Value of BST is : " << getMinValue(root)->data << endl;
    cout << "Max Value of BST is : " << getMaxValue(root)->data << endl;

    int succ;
    cout << "Enter the value of the element for which you want to find Inorded Successor : ";
    cin >> succ;
    cout << "Inorder Successor for " << succ << " is : " << inorderSuccesor(root, succ)->data << endl;

    int pre;
    cout << "Enter the value of the element for which you want to find Inorded predecessor : ";
    cin >> pre;
    cout << "Inorder predecessor for " << succ << " is : " << InorderPre(root, pre)->data << endl;

    int valToBeDeleted;
    cout << "Enter the data to be deleted " << endl;
    cin >> valToBeDeleted;
    root = deleteFromBst(root, valToBeDeleted);
    levelOrderTraversal(root);
    return 0;
}
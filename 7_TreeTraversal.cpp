#include <bits/stdc++.h>
#define SPACE 4
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
        this->left = NULL;
        this->right = NULL;
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
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

Node *buildTree(Node *root)
{
    int data;
    cout << "Enter the data : " << endl;
    cin >> data;

    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the data to be inserted in left of : " << root->data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data to be inserted in right of : " << root->data << endl;
    root->right = buildTree(root->right);
}

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node *print2D(Node *r, int space)
{
    if (r == NULL)
        return r;
    space += SPACE;

    print2D(r->right, space);
    cout << endl;
    if ((space - SPACE) == 7)
    {
        cout << "root ->";
    }
    else
    {
        for (int i = SPACE; i < space; i++)
            cout << " ";
    }
    cout << r->data << "\n";
    print2D(r->left, space);
    return r;
}

int main()
{
    Node *root = root;
    root = buildTree(root);
    print2D(root, 0);
    cout << "Preorder Traversal" << endl;
    preorder(root);
    cout << endl;
    cout << "Inorder Traversal" << endl;
    inorder(root);
    cout << endl;
    cout << "Postorder Traversal" << endl;
    postorder(root);
    cout << endl;
    return 0;
}

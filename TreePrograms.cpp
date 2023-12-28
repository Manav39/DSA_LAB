#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

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
        Node *frontNode = q.front();
        q.pop();
        if (frontNode == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << frontNode->data << " ";
            if (frontNode->left)
                q.push(frontNode->left);
            if (frontNode->right)
                q.push(frontNode->right);
        }
    }
}

void preorder(Node *root)
{
    if (root == NULL)
        return;
    stack<Node *> st;
    Node *curr = root;

    while (!st.empty() || curr != NULL)
    {
        while (curr != NULL)
        {
            cout << curr->data << " ";
            if (curr->right)
                st.push(curr->right);
            curr = curr->left;
        }
        if (!st.empty())
        {
            curr = st.top();
            st.pop();
        }
    }
}

void inorder(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> st;
    Node *curr = root;
    while (!st.empty() || curr != NULL)
    {
        while (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

void postorder(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> st;
    vector<int> v;
    st.push(root);
    while (!st.empty())
    {
        Node *temp = st.top();
        v.push_back(temp->data);
        st.pop();
        if (temp->left)
            st.push(temp->left);
        if (temp->right)
            st.push(temp->right);
    }
    reverse(v.begin(), v.end());
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

Node *buildTree(Node *&root)
{
    int data;
    cout << "Enter the data : " << endl;
    cin >> data;
    root = new Node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter the data in left of : " << root->data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data in right of : " << root->data << endl;
    root->right = buildTree(root->right);
    return root;
}

int countLeafNodes(Node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        if (root != NULL)
        {
            cout << root->data << " ";
        }
        return 0;
    }
    return 1 + countLeafNodes(root->left) + countLeafNodes(root->right);
}

int countNonLeaf(Node *root, int count = 0)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 0;
    count++;
    cout << root->data << " ";
    return count + countNonLeaf(root->left) + countLeafNodes(root->right);
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    cout << "Preorder : " << endl;
    preorder(root);
    cout << endl;
    cout << "Inorder : " << endl;
    inorder(root);
    cout << endl;
    cout << "Postorder : " << endl;
    postorder(root);
    cout << endl;
    cout << "Level Order : " << endl;
    levelOrderTraversal(root);
    cout << "Printing the leaf Nodes" << endl;
    int ans = countLeafNodes(root);
    cout << endl;
    cout << "Total Number of Leaf Nodes : " << ans << endl;
    cout << "Total Number of Non Leaf Nodes : " << countNonLeaf(root) << endl;
}
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};
typedef node *Tree;

Tree getNode(int x)
{
    Tree p = new node;
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void InsertTree(Tree &T, int x)
{
    if (T)
    {
        if (x < T->data)
            InsertTree(T->left, x);
        else if (x > T->data)
            InsertTree(T->right, x);
    }
    else
        T = getNode(x);
}

void inputTree(Tree &T)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        InsertTree(T, x);
    }
}

void NLR(Tree t)
{
    if (t)
    {
        cout << t->data << " ";
        NLR(t->left);
        NLR(t->right);
    }
}

void deleteNode(Tree &T, int x)
{
    if (T == nullptr)
        return;
    if (x < T->data)
        deleteNode(T->left, x);
    else if (x > T->data)
        deleteNode(T->right, x);
    else
    {
        // x found
        if (T->left == nullptr && T->right == nullptr)
        {
            // x is a leaf node
            delete T;
            T = nullptr;
        }
        else if (T->left == nullptr)
        {
            // x has a right child
            Tree temp = T;
            T = T->right;
            delete temp;
        }
        else if (T->right == nullptr)
        {
            // x has a left child
            Tree temp = T;
            T = T->left;
            delete temp;
        }
        else
        {
            // x has both left and right children
            Tree temp = T->right;
            while (temp->left != nullptr)
                temp = temp->left;
            T->data = temp->data;
            deleteNode(T->right, temp->data);
        }
    }
}

int main()
{
    Tree T = nullptr;
    inputTree(T);
    cout << "NLR: ";
    NLR(T);
    int x;
    cout << "\nEnter the element you want to delete: ";
    cin >> x;
    deleteNode(T, x);
    cout << "\nNLR: ";
    NLR(T);
    return 0;
}
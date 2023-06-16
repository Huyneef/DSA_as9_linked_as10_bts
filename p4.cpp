#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node*right;
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
int height(Tree T)
{
    if (T == NULL)
        return -1;
    int leftHeight = height(T->left);
    int rightHeight = height(T->right);
    return 1 + max(leftHeight, rightHeight);
}

bool isBalanced(TreeT)
{
    if (T == NULL)
        return true;
    int leftHeight = height(T->left);
    int rightHeight = height(T->right);
    if (abs(leftHeight - rightHeight) > 1)
        return false;
    return isBalanced(T->left) && isBalanced(T->right);
}

bool isAVL(Tree T)
{
    return isBalanced(T);
}
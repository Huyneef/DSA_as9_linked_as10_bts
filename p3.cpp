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

void NLR(Tree t)
{
    if (t)
    {
        cout << t->data << " ";
        NLR(t->left);
        NLR(t->right);
    }
}

void rotateLeft(Tree &T)
{
    if (T == nullptr)
    {
        cout << "\nKhong the xoay vi cay rong";
        return;
    }
    if (T->right == nullptr)
    {
        cout << "\nKhong the xoay trai vi khong co nut con ben phai";
        return;
    }
    // Tree newRoot = T->right;
    // T->right = newRoot->left;
    // newRoot->left = T;
    // T = newRoot;
    Tree p = T->right;
    T->right = p->left;
    p->left = T;
    T = p;
}

int main()
{
    Tree T = nullptr;
    inputTree(T);
    cout << "NLR: ";
    NLR(T);
    
    rotateLeft(T);
    cout << "\nNLR: ";
    NLR(T);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
typedef Node *Tree;
Tree getNode(int x)
{
    Tree p = new Node;
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}
void insertTree(Tree &t, int x)
{
    if (t)
    {
        
        if (x < t->data)
        {
            insertTree(t->left, x);
        }
        else if (x > t->data)
        {
            insertTree(t->right, x);
        }
    }
    else
        t = getNode(x);
}
void inputTree(Tree &t)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insertTree(t, x);
    }
}
void LNR(Tree t)
{
    if (t)
    {
        LNR(t->left);
        cout << t->data << " ";
        LNR(t->right);
    }
}
Node *Search(Tree t, int x)
{
    if (t)
    {
        Node *p = t;
        while (p != NULL)
        {
            if (x == p->data)
                return p;
            else if (x < p->data)
                p = p->left;
            else
                p = p->right;
        }
        return NULL;
    }
    else
        return NULL;
}
int maxValue(Tree t)
{
    Node *p = t;

    while (p != NULL)
    {
        if (p->right == NULL)
            return p->data;
        p = p->right;
    }
    return p->data;
}
int minValue(Tree t)
{
    Node *p = t;

    while (p != NULL)
    {
        if (p->left == NULL)
            return p->data;
        p = p->left;
    }
    return p->data;
}
int main()
{
    Tree T = NULL;
    inputTree(T);
    cout << "LNR: ";
    LNR(T);
    cout << endl;

    int x;
    cout << "\nEnter the element you want to find: ";
    cin >> x;
    Node *p = Search(T, x);
    if (p)
        cout << "Found";
    else
        cout << "Not found";
    cout << "\nMinimum value in BTS is " << minValue(T);
    cout << "\nMinimax value in BTS is " << maxValue(T);

    return 0;
}

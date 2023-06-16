#include <iostream>
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
void insertTree(Tree &t, int x,bool& isFlag)
{
    if (t)
    {
        if(x == t->data) {isFlag = true; return ;}
        else if (x < t->data)
        {
            insertTree(t->left, x, isFlag);
        }
        else if (x > t->data)
        {
            insertTree(t->right, x, isFlag);
        }
    }
    else
        t = getNode(x);
}
void inputTree(Tree &t)
{
    bool isFlag = false;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        
        insertTree(t, x, isFlag);
        if(isFlag) {
            cout << "Bi trung gia tri, ket thuc qua trinh tao cay" << endl;
            return;
        }
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
bool isFullBinaryTree(Tree t) {
    if(t == nullptr) return true;
    if(!t->left && !t->right) return true;
    if(t->left && t->right) {
        return isFullBinaryTree(t->left) && isFullBinaryTree(t->right);
    }
    return false;
}
int main()
{
	Tree T = NULL;
	inputTree(T);
	cout << "LNR: "; LNR(T);
	int i = isFullBinaryTree(T);
	if(i==0) cout<<"\nThe tree is not a Full Binary Tree";
    else cout<<"\nThe tree is a Full Binary Tree";
	return 0;
}


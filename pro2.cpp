
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
void NLR(Tree t)
{
    if (t)
    {
        cout << t->data << " ";
        NLR(t->left);
        NLR(t->right);
    }
}
Tree rotateRight(Tree &t) {
    if(t == nullptr) {
        cout << "\nKhong the xoay vi cay rong";
        return t;
    }
    else if(t->left == nullptr) {
        cout << "\nKhong the xoay phai vi khong co nut con ben trai";
        return t;
    }
    Tree p = t->left;
    t->left = p->right;
    p->right = t;
    t = p;
    return t;
}
int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"NLR: "; NLR(T);
	T=rotateRight(T);
	cout<<"\nUpdated Tree: \n";
	cout<<"NLR: "; NLR(T);
	return 0;
}




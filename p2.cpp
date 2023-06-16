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
void LNR(Tree t)
{
    if (t)
    {
        LNR(t->left);
        cout << t->data << " ";
        LNR(t->right);
    }
}
//1
int countNodes(Tree t) {
    if(t == NULL) return 0;
    return 1 + countNodes(t->left) + countNodes(t->right);
} 
//2
int dOfTree(Tree T) {
    if(T == NULL) {
        return 0;
    }
    else {
        int dL = dOfTree(T->left);
        int dR = dOfTree(T->right);
        return 1 + max(dL,dR);
    }
    
}
int depthOfTree(Tree T) {
    int d = dOfTree(T);
    return d-1;
}
//3

int ceven(Tree t) {
    int T;
    if(t == NULL) {
        return 0;
    }
    else {
        if(t->data < 0) T = -t->data;
        else T = t->data;
        int c = (T % 2 == 0) ? 1:0;
        c += ceven(t->left);
        c += ceven(t->right);
        return c;
    }
}
int codd(Tree t) {
    int T;
    if(t == NULL) {
        return 0;
    }
    else {
        if(t->data < 0) T = -t->data;
        else T = t->data;
        int c = (T % 2 == 1) ? 1:0;
        c += codd(t->left);
        c += codd(t->right);
        return c;
    }
}
void countEven(Tree T, int &c) {
    c = ceven(T);
}
void countOdd(Tree t, int &c) {
    c = codd(t);
}
int countPositive(Tree root) {
    if (root == nullptr) {
        return 0;
    } else {
        int count = (root->data > 0) ? 1 : 0;
        count += countPositive(root->left);
        count += countPositive(root->right);
        return count;
    }
}
int countNegative(Tree root) {
    if (root == nullptr) {
        return 0;
    } else {
        int count = (root->data < 0) ? 1 : 0;
        count += countNegative(root->left);
        count += countNegative(root->right);
        return count;
    }
}
int isPrimeNumber(int n) {
    if (n < 2) return 0;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) 
        {return 0;}
    }
    return 1;
}
int countPrime(Tree root) {
    int T;
    if (root == nullptr) {
        return 0;
    } else {
        
        int count = (isPrimeNumber(root->data)) ? 1 : 0;
        count += countPrime(root->left);
        count += countPrime(root->right);
        return count;
    }
}
void listPrime(Tree root) {
    if (root == nullptr) {
        return;
    }
    if (isPrimeNumber(root->data)) {
        cout << root->data << " ";
    }
    listPrime(root->left);
    listPrime(root->right);
}

int main()
{
	Tree T = NULL;
	inputTree(T);
    cout<<"LNR: "; LNR(T); cout<<endl;

	cout<<"Number of nodes: " << countNodes(T)<<endl;
    cout<<"Depth of Tree: "<<depthOfTree(T)<<endl;

    int count_even = 0, count_odd =0;
    countEven(T, count_even);countOdd(T, count_odd);
    cout<<"Number of even nodes: "<<count_even<<endl;
    cout<<"Number of odd nodes: "<<count_odd<<endl;

    cout<<"Number of positive nodes: "<<countPositive(T)<<endl;
    cout<<"Number of negative nodes: "<<countNegative(T)<<endl;

    cout<<"Number of prime nodes: "<<countPrime(T)<<endl;
    cout<<"Prime numbers: "; listPrime(T);



	return 0;
}

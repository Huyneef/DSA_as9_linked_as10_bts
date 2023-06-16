
#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node* pLeft;
    Node* pRight;
};
typedef struct Node* Tree;

Tree getNode(int x)
{
    Node* p = new Node;
    if (p == NULL)
    {
        cout << "Khong du bo nho de cap phat!\n";
        return NULL;
    }
    p->info = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}
void SetLeft(Tree p, int x)
{
    if (p == NULL)
    {
        cout << "Node khong ton tai\n";
        return;
    }
    if (p->pLeft != NULL)
    {
        cout << "Da co node con ben trai\n";
        return;
    }
    p->pLeft = getNode(x);
}
void SetRight(Tree p, int x) {
    if (p == NULL) {
        cout << "Node khong ton tai\n";
        return; 
    }
    if(p->pRight != NULL) {
        cout << "Da co node con ben phai\n";
        return;
    }
    p->pRight = getNode(x);
}
Tree Search(Tree t, int x) {
    if(!t) 
    return NULL;
    if(t->info == x) 
    return t;
    Tree tm = Search(t->pLeft,x);
    if(!tm)
    tm = Search(t->pRight,x);
    return tm;
}
void LNR(Tree t) {
    if(t) {
        LNR(t->pLeft);
        cout << t->info << " ";
        LNR(t->pRight);
    }
}
bool isBST(Tree T, int* L, int* R) {
    if (!T ) {
        return 1;
    }
    if ((L != NULL && T->info <= *L) || (R != NULL && T->info >= *R)) 
    {
        return 0;
    }
    return isBST(T->pLeft, L, &(T->info)) && isBST(T->pRight, &(T->info), R);
}

bool isBST(Node* T) {
    return isBST(T, NULL, NULL);
}

int main()
{
	Tree T = NULL;
	int x,b,c; char a;
	cin>>x;	T=getNode(x); // tao nut goc
	while(true)
    {
        cin>>a; // Ky tu cho biet chen vao trai hay phai
        if(a!='L'&& a!='R') break; // Neu khong phai L hoac R thi ket thuc viec tao cay
        cin>>b>>c;
        if(a=='L') SetLeft(Search(T,b),c); // chen c vao ben trai b
        else if (a=='R') SetRight(Search(T,b),c); // chen c vao ben phai b
    }
	cout<<"\nLNR: "; LNR(T); cout<<endl;
    if(isBST(T)) cout<<"Cay vua tao la cay BST";
    else cout<<"Cay vua tao khong phai la cay BST";

	return 0;
}




#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node *pLeft;
    Node *pRight;
};
typedef struct Node* Tree;
Node *getNode(int x);
void insertNode(Tree & T, int x);
void inputTree(Tree &T);
void NLR(Tree T);
int nodesWithLevel(Tree T, int k, int c);

int main()
{
    Tree T = NULL;
    inputTree(T);
    cout<<"\nNLR: "; NLR(T);
    int k; cout<<"\nEnter k: "; cin >>k;
    cout<<nodesWithLevel(T,k,0); //neu tham so thu 3 khong can dung thi trong ham khong can xu ly

    return 0;
}

Node* getNode(int x) {
    Node* p = new Node;
    p->info = x;
    p->pRight = NULL;
    p->pLeft = NULL;
    return p;
}
void insertNode(Tree& T, int x) {
    if(T) {
        if(x < T->info) {
            insertNode(T->pLeft, x) ;
        }
        else if(x > T->info) {
            insertNode(T->pRight, x);
        }
    }
    else T = getNode(x);
}
void inputTree(Tree &T) {
    int n;
    cin >> n;
    int x;
    for(int i = 0; i < n; i++) {
        cin >> x;
        insertNode(T,x);
    }
}
void NLR(Tree T) {
    if(T) {
        cout << T->info << " ";
        NLR(T->pLeft);
        NLR(T->pRight);
    }
}

int nodesWithLevel(Tree T, int k, int c) {
    int cc = 0;
    static int count = 0;
    
    if(!T) {
        return cc;
    }
    
    cc += nodesWithLevel(T->pRight, k, 1+c);
    cc += nodesWithLevel(T->pLeft, k, 1+c);
    if(c == k && T) {
        if(count == 0) {
            cout << "\nList of nodes with level " << k << " (R->L): " << T->info << " ";
            count++;
        }
        else {
            cout << T->info << " ";
        }
        cc++;
    }
    if(c == 0 && cc == 0 && count == 0) {
        
        
        cout << "\nList of nodes with level " << k << " (R->L): ";
        count++;
    }
    if(count == 1 && c == 0) {
        cout << "\nNumber of nodes with level " << k << ": "; 
    }
    
    return cc;
}
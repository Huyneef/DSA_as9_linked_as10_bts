
#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node *pLeft;
    Node *pRight;
};
typedef struct Node* Tree;
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

void secondLargest(Tree T) {
    int scn = 0;
	if(!T || (!T->pLeft && !T->pRight)) return;
       
        Tree sau = T;
        Tree trc = NULL;
        for(;sau->pRight != NULL;) {
            trc = sau;
            sau = sau->pRight;
        }
        if(sau->pLeft != NULL) {
            sau = sau->pLeft;
            while (sau->pRight != NULL) {
                sau = sau->pRight;
            }
            scn = sau->info;
        }
        else {
            scn = trc->info;
        }
        cout << "2nd largest value is " << scn << endl;
    
}


int main()
{
	Tree T = NULL;
	inputTree(T);
    secondLargest(T);
	return 0;
}
 
#include <bits/stdc++.h>
using namespace std;


struct Node {
    int info;
    Node* pRight;
    Node* pLeft;
};

typedef Node* Tree;

Tree getNode(int x) {
    Tree p = new Node;
    p->info = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

void insertTree(Tree& T, int x) {
    if (T) {
        if (x < T->info) {
            insertTree(T->pLeft, x);
        }
        else if (x > T->info) {
            insertTree(T->pRight, x);
        }
    }
    else T = getNode(x);
}

void inputTree(Tree& T) {
    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        insertTree(T, x);
    }
}

int floorBST(Tree T, int x) {
    int flVal = 201; 
    while (T) {
        if (T->info == x) {
            flVal = x;
            break;
        }
        else if (T->info > x) { 
            T = T->pLeft; 
        }
        else { 
            flVal = T->info; 
            T = T->pRight; 
        }
    }
    return flVal;
}

int main() {
    Tree T ;
    T = NULL;
    inputTree(T);
    int x;
    cin >> x;
    int flVal = floorBST(T, x);
    if (flVal != 201) {
        cout << flVal  << endl;
    }
    else {
        cout << "201";
    }
    return 0;
}
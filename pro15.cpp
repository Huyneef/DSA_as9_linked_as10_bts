#include <bits/stdc++.h>

using namespace std;
struct Node
{
    int info;
    Node *pRight;
    Node *pLeft;
};

typedef Node *Tree;

Tree getNode(int x)
{
    Tree p = new Node;
    p->info = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

void insertTree(Tree &T, int x)
{
    if (T)
    {

        if (x == T->info)
        {
            if (T->pRight)
                insertTree(T->pLeft, x);
            else
                insertTree(T->pRight, x);
        }
        else if (x < T->info)
        {
            insertTree(T->pLeft, x);
        }
        else if (x > T->info)
        {
            insertTree(T->pRight, x);
        }
    }
    else
        T = getNode(x);
}

void inputTree(Tree &T, int n, vector<int> mangoes)
{

    for (int i = 0; i < n; i++)
    {
        insertTree(T, mangoes[i]);
    }
}
void LNR(Tree t)
{
    if (t)
    {
        LNR(t->pLeft);
        cout << t->info << " ";
        LNR(t->pRight);
    }
}
int cLeft(Tree T, multiset<int> &visible_mangoes) {
    int cL = 0;
    while(T->pLeft) {
        cL++;
        T = T->pLeft;
        visible_mangoes.insert(T->info);
    }
    
    return cL+1;
}
int cRight(Tree T,multiset<int> &visible_mangoes) {
    int cR = 0;
    while(T->pRight) {
        cR++;
        T = T->pRight;
        visible_mangoes.insert(T->info);
    }
    return cR+1;
}
void getMango(Tree T, multiset<int> &visible_mangoes, int cL, int cR ){
    int cl = 0;
    for(int i = 1; i < cR; i++) {
        Tree p = T->pRight;
        cl = 0;
        while(cl < cL) {
            cl++;
            p = p->pLeft;
            if(p == nullptr) break;
        }
        if(cl == cL && p->pLeft ) visible_mangoes.insert(p->pLeft->info);
        cL++;
        T = T->pRight;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> mangoes(n);
    multiset<int> visible_mangoes;
    for (int i = 0; i < n; i++)
    {
        cin >> mangoes[i];
    }
    Tree T = NULL;
    inputTree(T, n, mangoes);
    int cL = cLeft(T,visible_mangoes), cR = cRight(T,visible_mangoes);
    cout << cL << " " << cR << endl;
    
    visible_mangoes.insert(T->info);
    getMango(T,visible_mangoes,cL,cR);
    for(auto x : visible_mangoes) cout << x << " ";
    // vector<int> visible_mangoes;
    // visible_mangoes.push_back(mangoes[0]);

    // int max_left = mangoes[0];
    // int max_right = -1;
    // for (int i = 1; i < n; i++) {
    //     if (mangoes[i] > max_left) {
    //         visible_mangoes.push_back(mangoes[i]);
    //         max_left = mangoes[i];
    //         max_right = -1;
    //     }
    //     else if (mangoes[i] > max_right) {
    //         visible_mangoes.push_back(mangoes[i]);
    //         max_right = mangoes[i];
    //     }
    // }

    // for (int i = 0; i < visible_mangoes.size(); i++) {
    //     cout << visible_mangoes[i] << " ";
    // }
    // cout << endl;

    return 0;
}
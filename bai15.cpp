
#include <iostream>
#include <utility>
using std::cin;
using std::cout;
using std::endl;
using std::pair;

struct Node{
    int val;
    Node* next;
};

struct List{
    Node *head, *tail;
};

void list_initializing(List &l){
    l.head = l.tail = NULL;
}
void add_tail(List &l, int x){
    Node*p = new Node;
    p->val = x;
    p->next = NULL;

    if (l.head == NULL){
        l.head = l.tail = p;
    } else {
        l.tail->next = p;
        l.tail = p;
    }
}

void xuat(List &l){
    for(Node *p = l.head; p != NULL; p = p->next){
        cout << p->val << " ";
    }
    cout << endl;
}
pair<List, List> split(List l) {
    List odd, even;
    list_initializing(odd);
    list_initializing(even);

    Node* p = l.head;
    Node* oddTail = nullptr;
    Node* evenTail = nullptr;
    bool ispOdd = true;

    while (p != nullptr) {
        if (ispOdd) {
            if (odd.head == nullptr) {
                odd.head = p;
                oddTail = p;
            } else {
                oddTail->next = p;
                oddTail = p;
            }
        } else {
            if (even.head == nullptr) {
                even.head = p;
                evenTail = p;
            } else {
                evenTail->next = p;
                evenTail = p;
            }
        }

        p = p->next;
        ispOdd = !ispOdd;
    }

    if (oddTail != nullptr) {
        oddTail->next = nullptr;
    }

    if (evenTail != nullptr) {
        evenTail->next = nullptr;
    }

    return { odd, even };
}


int main()
{
    List l; list_initializing(l);
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int x;
    do{
        cin >> x;
        if (x != 0) add_tail(l, x);
        else break;
    } while(true);


    pair<List, List> ls = split(l);

    xuat(ls.first);
    xuat(ls.second);

    return 0;
}

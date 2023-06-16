#include <iostream>
#include <iomanip>
using namespace std;

struct DONTHUC
{
    int somu;
    double heso;
};

struct Node
{
    DONTHUC *data;
    Node *next;
};

typedef struct DATHUC
{
    Node *head;
    Node *tail;
} List;
void Nhap(DATHUC &A)
{
    int n;
    int sm;
    double hs;
    A.head = NULL;
    A.tail = NULL;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> hs >> sm;
        Node *a = new Node;
        a->data = new DONTHUC{sm, hs};
        a->next = NULL;
        if (A.head == nullptr)
        {
            A.head = a;
            A.tail = a;
        }
        else
        {
            A.tail->next = a;
            A.tail = a;
        }
    }
}
void Xuat(DATHUC A)
{
    Node *p = A.head;
    int empty = 1;

    while (p != NULL)
    {
        if (p->data->heso != 0)
        {
            empty = 0;
        }
        p = p->next;
    }
    if (empty)
    {
        cout << "0" ;
        cout <<  endl;
        return;
    }
    int phanTuDauTien = 1;
    p = A.head;
    
    while (p != NULL)
    {
        if (p->data->heso)
        {
            if (p->data->heso > 0 && !phanTuDauTien)
            {
                cout << "+";
            }
            phanTuDauTien = 0;
            if (p->data->somu == 1)
            {
                if (p->data->heso == -1)
                {
                    cout <<  "-x";
                }
                
                else if(p->data->heso == 1)
                {
                    cout  << "x";
                }
                else {
                    cout << p->data->heso << "x";
                }
            }
            else if (!p->data->somu)
            {
                cout << p->data->heso;
            }
            else
            {
                if (p->data->heso == -1)
                {
                    cout << "-x^" << p->data->somu;
                }
                else if (p->data->heso == 1)
                {
                    cout << "x^" << p->data->somu;
                }
                else
                {
                    cout << p->data->heso << "x^" << p->data->somu;
                }
            }
        }
        p = p->next;
    }
    cout << endl;
}
// C = A + B
DATHUC Tong2DaThuc(DATHUC a, DATHUC b)
{
    DATHUC c;
    c.head = NULL;
    c.tail = NULL;
    Node *poa = a.head;
    Node *pob = b.head;
    while (poa != NULL && pob != NULL)
    {
        if (pob->data->somu == poa->data->somu)
        {
            double hs = poa->data->heso + pob->data->heso;
            if (hs)
            {
                Node *p = new Node;
                p->data = new DONTHUC{poa->data->somu, hs};
                p->next = NULL;
                if (c.head == NULL)
                {
                    c.head = p;
                    c.tail = p;
                }
                else
                {
                    c.tail->next = p;
                    c.tail = p;
                }
                
            }
            poa = poa->next;
            pob = pob->next;
            
        }
        else if (poa->data->somu > pob->data->somu)
            {
                Node *p = new Node;
                p->data = new DONTHUC{poa->data->somu, poa->data->heso};
                p->next = NULL;
                if (c.head == NULL)
                {
                    c.head = p;
                    c.tail = p;
                }
                else
                {
                    c.tail->next = p;
                    c.tail = p;
                }
                poa = poa->next;
            }
            else
            {
                Node *p = new Node;
                p->data = new DONTHUC{pob->data->somu, pob->data->heso};
                p->next = NULL;
                if (c.head == NULL)
                {
                    c.head = p;
                    c.tail = p;
                }
                else
                {
                    c.tail->next = p;
                    c.tail = p;
                }
                pob = pob->next;
            }
    }
    while (poa != NULL)
    {
        Node *p = new Node;
        p->data = new DONTHUC{poa->data->somu, poa->data->heso};
        p->next = NULL;
        if (c.head == NULL)
        {
            c.head = p;
            c.tail = p;
        }
        else
        {
            c.tail->next = p;
            c.tail = p;
        }
        poa = poa->next;
    }
    while (pob != NULL)
    {
        Node *p = new Node;
        p->data = new DONTHUC{pob->data->somu, pob->data->heso};
        p->next = NULL;
        if (c.head == NULL)
        {
            c.head = p;
            c.tail = p;
        }
        else
        {
            c.tail->next = p;
            c.tail = p;
        }
        pob = pob->next;
    }

    return c;
}
/*



DATHUC Tong2DaThuc(DATHUC A, DATHUC B) {
    DATHUC C;
    C.head = C.tail = NULL;
    Node* pA = A.head;
    Node* pB = B.head;
    while (pA != NULL && pB != NULL) {
        if (pA->data->somu == pB->data->somu) {
            double heso = pA->data->heso + pB->data->heso;
            if (heso != 0) {
                Node* newNode = new Node;
                newNode->data = new DONTHUC{ pA->data->somu, heso };
                newNode->next = NULL;
                if (C.head == NULL) {
                    C.head = C.tail = newNode;
                }
                else {
                    C.tail->next = newNode;
                    C.tail = newNode;
                }
            }
            pA = pA->next;
            pB = pB->next;
        }
        else if (pA->data->somu > pB->data->somu) {
            Node* newNode = new Node;
            newNode->data = new DONTHUC{ pA->data->somu, pA->data->heso };
            newNode->next = NULL;
            if (C.head == NULL) {
                C.head = C.tail = newNode;
            }
            else {
                C.tail->next = newNode;
                C.tail = newNode;
            }
            pA = pA->next;
        }
        else {
            Node* newNode = new Node;
            newNode->data = new DONTHUC{ pB->data->somu, pB->data->heso };
            newNode->next = NULL;
            if (C.head == NULL) {
                C.head = C.tail = newNode;
            }
            else {
                C.tail->next = newNode;
                C.tail = newNode;
            }
            pB = pB->next;
        }
    }
    while (pA != NULL) {
        Node* newNode = new Node;
        newNode->data = new DONTHUC{ pA->data->somu, pA->data->heso };
        newNode->next = NULL;
        if (C.head == NULL) {
            C.head = C.tail = newNode;
        }
        else {
            C.tail->next = newNode;
            C.tail = newNode;
        }
        pA = pA->next;
    }
    while (pB != NULL) {
        Node* newNode = new Node;
        newNode->data = new DONTHUC{ pB->data->somu, pB->data->heso };
        newNode->next = NULL;
        if (C.head == NULL) {
            C.head = C.tail = newNode;
        }
        else {
            C.tail->next = newNode;
            C.tail = newNode;
        }
        pB = pB->next;
    }
    return C;
}
*/
int main()
{
    DATHUC A, B;
    Nhap(A);
    Nhap(B);
    cout << "Da thuc A: ";
    Xuat(A);
    cout << "\nDa thuc B: ";
    Xuat(B);
    cout << "\nA+B = ";
    Xuat(Tong2DaThuc(A, B));
    return 0;
}

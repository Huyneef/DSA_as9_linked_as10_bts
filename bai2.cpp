
#include <iostream>
using namespace std;

struct DNode
{
    int info;
    DNode *pNext, *pPrev;
};

struct DList
{
    DNode *pHead, *pTail;
};

void init(DList &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

DNode *getDNode(const int &x)
{
    DNode *p = new DNode;
    p->info = x;
    p->pNext = NULL;
    p->pPrev = NULL;

    return p;
}

bool searchPro(const DList &L, const int &a)
{
    DNode *current = L.pHead;
    while (current != NULL)
    {
        if (current->info == a)
        {
            return true;
        }
        current = current->pNext;
    }
    return false;
}

DNode *sEle(const DList &l, const int &x)
{
    DNode *p = l.pHead;
    while (p != NULL)
    {
        if (p->info == x)
        {
            return p;
        }
        p = p->pNext;
    }
    return NULL;
}

void printList(const DList &l)
{
    DNode *p = l.pHead;
    if (p == NULL)
    {
        cout << "List is empty";
    }
    else
    {
        while (p != NULL)
        {
            cout << p->info << " ";
            p = p->pNext;
        }
    }
    cout << endl;
}

void addHead(DList &l, const int &x)
{
    DNode *p = getDNode(x);
    if (l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead->pPrev = p;
        l.pHead = p;
    }
}

void addTail(DList &l, const int &x)
{
    DNode *p = getDNode(x);
    if (l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        p->pPrev = l.pTail;
        l.pTail = p;
    }
}

void addAfter(DList &l, const int &x, const int &y)
{
    if (!searchPro(l, x))
    {
        cout << "\nCan't find the value " << x;
    }
    else
    {
        DNode *p = sEle(l, x);
        if (p->info == x)
        {
            DNode *tmp = getDNode(y);
            tmp->pPrev = p;
            tmp->pNext = p->pNext;
            if (p == l.pTail)
            {
                l.pTail = tmp;
            }
            else
            {
                p->pNext->pPrev = tmp;
            }
            p->pNext = tmp;
        }
    }
}

void addBefore(DList &L, const int &x, const int &y)
{

    if (!searchPro(L, x))
        cout << "\nCan't find the value " << x;
    else
    {
        DNode *p = sEle(L, x);
        if (p->info == x)
        {
            DNode *t = getDNode(y);
            t->pNext = p;
            t->pPrev = p->pPrev;
            if (p == L.pHead)
            {
                L.pHead = t;
            }
            else
            {
                p->pPrev->pNext = t;
            }
            p->pPrev = t;
        }
    }
}
void createList(DList &l)
{
    while (true)
    {
        int x;
        cin >> x;
        if (x == -1)
            break;
        else
        {
            addTail(l, x);
        }
    }
}

void addAfterMulti(DList &l, const int &x, const int &y)
{
    if (!searchPro(l, x))
        cout << "\nCan't find the value " << x;
    else
    {
        DNode *p = l.pHead;
        while (p != NULL)
        {
            if (p->info == x)
            {

                DNode *tmp = getDNode(y);
                tmp->pPrev = p;
                tmp->pNext = p->pNext;
                if (p == l.pTail)
                {
                    l.pTail = tmp;
                }
                else
                {
                    p->pNext->pPrev = tmp;
                }
                p->pNext = tmp;
            }
            p = p->pNext;
        }
    }
}

void addBeforeMulti(DList &L, const int &x, const int &y)
{
    if (!searchPro(L, x))
        cout << "\nCan't find the value " << x;
    else
    {
        DNode *p = L.pHead;
        while (p != NULL)
        {

            if (p->info == x)
            {
                DNode *t = getDNode(y);
                t->pNext = p;
                t->pPrev = p->pPrev;
                if (p == L.pHead)
                {
                    L.pHead = t;
                }
                else
                {
                    p->pPrev->pNext = t;
                }
                p->pPrev = t;
            }
            p = p->pNext;
        }
    }
}
void removeHead(DList &l)
{

    char c;
    if (l.pHead == NULL)
    {
        cout << "\nList is empty. Can't delete";
    }
    else
    {
        cout << "\nDo you want to delete the first element?(y/n): ";
        cin >> c;
        if (c == 'y' || c == 'Y')
        {
            if (l.pHead == l.pTail)
            {
                delete l.pHead;
                l.pHead = NULL;
                l.pTail = NULL;
                cout << "\nThe list becomes empty";
            }
            else
            {
                DNode *temp = l.pHead;
                l.pHead = l.pHead->pNext;
                l.pHead->pPrev = NULL;
                delete temp;
            }
        }
    }
}
void removeTail(DList &l)
{
    char c;
    if (l.pHead == NULL)
    {
        cout << "\nList is empty. Can't delete";
    }
    else
    {
        cout << "\nDo you want to delete the last element?(y/n): ";
        cin >> c;
        if (c == 'y' || c == 'Y')

        {
            if (l.pHead == l.pTail)
            {
                delete l.pHead;
                l.pHead = NULL;
                l.pTail = NULL;
                cout << "\nThe list becomes empty";
            }
            else
            {
                DNode *temp = l.pTail;
                l.pTail = l.pTail->pPrev;
                l.pTail->pNext = NULL;
                delete temp;
            }
        }
    }
}
    int main()
    {
        DList L;
        init(L);
        int x, y, choice;
        char c;

        cout << "MENU:";
        cout << "\n1. Create a DList";
        cout << "\n2. Print the DList";
        cout << "\n3. Insert a value at the front";
        cout << "\n4. Insert a value at the end";
        cout << "\n5. Insert a value after a given value (only for the first value found)";
        cout << "\n6. Insert a value before a given value (only for the first value found)";
        cout << "\n7. Insert a value after a given value (for all the same values)";
        cout << "\n8. Insert a value before a given value (for all the same values)";
        cout << "\n9. Delete the first element";
        cout << "\n10. Delete the last element";
        cout << "\n20. Exit" << endl;

        while (true)
        {
            cout << "\n\t\tPLEASE SELECT YOUR CHOICE: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                cout << "\nEnter your positive integers until you enter -1 to finish: ";
                createList(L);
                break;
            case 2:
                cout << "\nYour current DList: ";
                printList(L);
                break;
            case 3:
                cout << "\nEnter a number: ";
                cin >> x;
                addHead(L, x);
                break;
            case 4:
                cout << "\nEnter a number: ";
                cin >> x;
                addTail(L, x);
                break;
            case 5:
                cout << "\nEnter two numbers: ";
                cin >> x >> y;
                addAfter(L, x, y);
                break;
            case 6:
                cout << "\nEnter two numbers: ";
                cin >> x >> y;
                addBefore(L, x, y);
                break;
            case 7:
                cout << "\nEnter two numbers: ";
                cin >> x >> y;
                addAfterMulti(L, x, y);
                break;
            case 8:
                cout << "\nEnter two numbers: ";
                cin >> x >> y;
                addBeforeMulti(L, x, y);
                break;
            case 9:
                removeHead(L);
                break;
            case 10:
                removeTail(L);
                break;
            case 20:
                cout << "\nGOOD BYE";
                return 0;
            }
        }

        return 0;
    }

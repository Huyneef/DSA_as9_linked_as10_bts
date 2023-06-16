
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
void addBefore(DList &L, const int &x, const int &y) \
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
//9
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
                if (l.pHead != NULL)
                {
                    l.pHead->pPrev = NULL;
                }
                else
                {
                    l.pTail = NULL;
                }
                delete temp;
            }
        }
    }
}
//10
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
                if (l.pTail != NULL)
                {
                    l.pTail->pNext = NULL;
                }
                else
                {
                    l.pHead = NULL;
                }
                delete temp;
            }
        }
    }
}
//11
void removeNode(DList &l, const int &x)
{
    if (!searchPro(l, x))
        cout << "\nCan't find the value " << x;
    else
    {
        char c;
        cout << "\nDo you want to delete " << x << " ?(y/n): ";
        cin >> c;
        if (c == 'y' || c == 'Y')
        {

            if (l.pHead == l.pTail && l.pHead->info == x)
            {
                delete l.pHead;
                l.pHead = NULL;
                l.pTail = NULL;
                cout << "\nThe list becomes empty";
            }
            else
            {
                DNode *p = l.pHead;
                while (p != nullptr)
                {
                    if (p->info == x)
                        break;
                    p = p->pNext;
                }
                if (p == l.pHead)
                {
                    l.pHead = l.pHead->pNext;
                    if (l.pHead != NULL)
                    {
                        l.pHead->pPrev = NULL;
                    }
                }
                else if (p == l.pTail)
                {
                    l.pTail = l.pTail->pPrev;
                    if (l.pTail != NULL)
                    {
                        l.pTail->pNext = NULL;
                    }
                }
                else
                {

                    p->pNext->pPrev = p->pPrev;
                    p->pPrev->pNext = p->pNext;
                }
                DNode *temp = p;
                delete temp;
            }
        }
        else
        {
            return;
        }
    }
}
//12
void removeMultiNodeS(DList &l, const int &x)
{
    if (!searchPro(l, x))
        cout << "\nCan't find the value " << x;
    else
    {
        char c;
        cout << "\nDo you want to delete " << x << "s ?(y/n): ";
        cin >> c;
        if (c == 'y' || c == 'Y')
        {

            DNode *p = l.pHead;
            while (p != NULL)
            {
                if (l.pHead->info == x && l.pHead == l.pTail)
                {
                    delete l.pHead;
                    l.pHead = NULL;
                    l.pTail = NULL;
                    cout << "\nThe list becomes empty";
                    p = NULL;
                }
                else
                {
                    if (p->info == x)
                    {

                        if (p == l.pTail)
                        {
                            l.pTail = p->pPrev;
                            if (l.pTail != NULL)
                            {
                                l.pTail->pNext = NULL;
                            }
                        }
                        else if (p == l.pHead)
                        {
                            l.pHead = p->pNext;
                            if (l.pHead != NULL)
                            {
                                l.pHead->pPrev = NULL;
                            }
                        }

                        else
                        {

                            p->pNext->pPrev = p->pPrev;
                            p->pPrev->pNext = p->pNext;
                        }
                        DNode *tmp = p;
                        p = p->pNext;
                        delete tmp;
                    }
                    else
                    {
                        p = p->pNext;
                    }
                }
            }
        }
        else
        {
            return;
        }
    }
}
// 13
void removeAfter(DList &l, const int &x)
{
    if (!searchPro(l, x))
    {
        cout << "\nCan't find the value " << x;
    }
    else
    {
        
        DNode *p = l.pHead;
        while(p != NULL) {
            if(p->info == x) break;
            p = p->pNext;
        }
        if (p == l.pTail)
        {
            cout << endl
                 << x << " is the last element. Can't delete the element after it";
        }
        else
        {
            char c;
            cout << "\nDo you want to delete the element after " << x << " ?(y/n): ";
            cin >> c;
            if (c == 'y' || c == 'Y')
            {
                DNode *temp = p->pNext;
                p->pNext = temp->pNext;
                if (temp->pNext != NULL)
                {
                    temp->pNext->pPrev = p;
                }
                else
                {
                    p->pNext = NULL;
                    l.pTail = p;
                }
                delete temp;
            }
        }
    }
}
// 14
void removeBefore(DList &l, const int &x)
{
    if (!searchPro(l, x))
    {
        cout << "\nCan't find the value " << x;
    }
    else
    {
        DNode *p = l.pHead;
        while(p != nullptr) {
            if(p->info == x) 
            break;
            else 
            p = p->pNext;
        }
        if (p == l.pHead)
        {
            cout << endl
                 << x << " is the first element. Can't delete the element before it";
        }
        else
        {
            char c;
            cout << "\nDo you want to delete the element before " << x << " ?(y/n): ";
            cin >> c;
            if (c == 'y' || c == 'Y')
            {
                DNode *temp = p->pPrev;
                p->pPrev = temp->pPrev;
                if (temp->pPrev != NULL)
                {
                    temp->pPrev->pNext = p;
                }
                else
                {
                    p->pPrev = NULL;
                    l.pHead = p;
                }

                delete temp;
            }
        }
    }
}
// 15
void removeMultiAfters(DList &l, const int &x)
{
    int count = 0;
    DNode *p = l.pHead;
    while (p != NULL)
    {
        if (p->info == x)
        {
            count++;
        }
        p = p->pNext;
    }
    if (count == 0)
    {
        cout << "\nCan't find the value " << x;
    }
    else if (count == 1 && l.pTail->info == x)
    {
        cout << "\nList has only one " << x << " and " << x << " is the last element. Can't delete the element after it";
    }
    else
    {
        char c;
        cout << "\nDo you want to delete all elements after " << x << " ?(y/n): ";
        cin >> c;
        if (c == 'y' || c == 'Y')
        {
            p = l.pHead;

            while (p != NULL)
            {
                if (p->info == x)
                {
                    DNode *temp = p->pNext;
                    p->pNext = temp->pNext;
                    if (temp->pNext != NULL)
                    {
                        temp->pNext->pPrev = p;
                    }
                    else
                    {
                        p->pNext = NULL;
                        l.pTail = p;
                    }
                    delete temp;
                }
                p = p->pNext;
            }
        }
    }
}
// 16
void removeMultiBefores(DList &l, const int &x)
{
    int count = 0;
    DNode *p = l.pHead;
    while (p != NULL)
    {
        if (p->info == x)
        {
            count++;
        }
        p = p->pNext;
    }
    if (count == 0)
    {
        cout << "\nCan't find the value " << x;
    }
    else if (count == 1 && l.pHead->info == x)
    {
        cout << "\nList has only one " << x << " and " << x << " is the first element. Can't delete the element before it";
    }
    else
    {
        char c;
        cout << "\nDo you want to delete all elements before " << x << " ?(y/n): ";
        cin >> c;
        if (c == 'y' || c == 'Y')
        {
            p = l.pHead;

            while (p != NULL)
            {
                if (p->info == x)
                {
                    DNode *temp = p->pPrev;
                    p->pPrev = temp->pPrev;
                    if (temp->pPrev != NULL)
                    {
                        temp->pPrev->pNext = p;
                    }
                    else
                    {
                        p->pPrev = NULL;
                        l.pHead = p;
                    }

                    delete temp;
                }
                p = p->pNext;
            }
        }
    }
}
// 17
void removeAll(DList &l)
{

    char c;
    cout << "\nDo you want to delete all elements?(y/n): ";
    cin >> c;
    if (c == 'y' || c == 'Y')
    {
        DNode* p = l.pHead;
        while(p != nullptr) {
            DNode* temp = p;
            p = p->pNext;
            delete temp;
        }
        l.pHead = nullptr;
        l.pTail = nullptr;
    }
    cout << "\nThe list becomes empty";
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
    cout << "\n11. Delete the first element containing a specific value";
    cout << "\n12. Delete all elements storing a particular value";
    cout << "\n13. Delete the element after a specific value (only for the first one found)";
    cout << "\n14. Delete the element before a specific value (only for the first one found)";
    cout << "\n15. Delete all elements after a specific value";
    cout << "\n16. Delete all elements before a specific value";
    cout << "\n17. Delete all elements";
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
        case 11:
            if (L.pHead == NULL)
            {
                cout << "\nList is empty. Can't delete";
                break;
            }
            cout << "\nEnter a number: ";
            cin >> x;
            removeNode(L, x);
            break;
        case 12:
            if (L.pHead == NULL)
            {
                cout << "\nList is empty. Can't delete";
                break;
            }
            cout << "\nEnter a number: ";
            cin >> x;
            removeMultiNodeS(L, x);
            break;
        case 13:
            if (L.pHead == NULL)
            {
                cout << "\nList is empty. Can't delete";
                break;
            }
            cout << "\nEnter a number: ";
            cin >> x;
            removeAfter(L, x);
            break;
        case 14:
            if (L.pHead == NULL)
            {
                cout << "\nList is empty. Can't delete";
                break;
            }
            cout << "\nEnter a number: ";
            cin >> x;
            removeBefore(L, x);
            break;
        case 15:
            if (L.pHead == NULL)
            {
                cout << "\nList is empty. Can't delete";
                break;
            }
            cout << "\nEnter a number: ";
            cin >> x;
            removeMultiAfters(L, x);
            break;
        case 16:
            if (L.pHead == NULL)
            {
                cout << "\nList is empty. Can't delete";
                break;
            }
            cout << "\nEnter a number: ";
            cin >> x;
            removeMultiBefores(L, x);
            break;
        case 17:
            if (L.pHead == NULL)
            {
                cout << "\nList is empty. Can't delete";
                break;
            }
            removeAll(L);
            break;
        case 20:
            cout << "\nGOOD BYE";
            return 0;
        }
    }

    return 0;
}


#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct tinh
{
    int id;
    char name[31];
    int pop;
    float area;
};

typedef tinh pro;

struct node
{
    pro info;
    node *next;
};

struct List
{
    node *head;
    node *tail;
};

void Init(List &l)
{
    l.head = nullptr;
    l.tail = nullptr;
}

node *getNode(pro x)
{
    node *p = new node;
    if (p != NULL)
    {
        p->info = x;
        p->next = nullptr;
    }
    return p;
}

void addTail(List &L, pro x)
{
    node *p = getNode(x);
    if (L.head == nullptr)
    {
        L.head = p;
        L.tail = p;
    }
    else
    {
        L.tail->next = p;
        L.tail = p;
    }
}
void inputPro(pro &Y)
{
    cin >> Y.id;
    cin.ignore();
    cin.getline(Y.name, 31);
    cin >> Y.pop;
    cin >> Y.area;
}
void inputListProvinces(List &l)
{
    pro x;
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {

        inputPro(x);
        addTail(l, x);
    }
}
void outputProvince(pro p)
{
    cout << p.id << "\t" << p.name << "\t" << p.pop << "\t" << p.area;
}

void outputListProvinces(List l)
{
    node *p = l.head;
    if (p == nullptr)
    {
        cout << "List is empty";
        return;
    }

    while (p != nullptr)
    {
        outputProvince(p->info);
        cout << endl;
        p = p->next;
    }
}

// void delPro(List &L, int& check, string s)
// {

//         node *sau = L.head;
//         node *trc = nullptr;
//         while (sau != nullptr)
//         {
//             if ((sau->info).name == s)
//             {
//                 check = 1;
//                 break;
//             }
//             trc = sau;
//             sau = sau->next;
//         }
//         if (sau != nullptr && trc != nullptr)
//         {
//             trc->next = sau->next;
//             sau->next = NULL;
//             if (sau == L.tail)
//             {
//                 L.tail = trc;
//             }
//             delete sau;
//         }
//         else if (trc == NULL && sau != NULL)
//         {
//             L.head = L.head->next;
//             sau->next = NULL;
//             delete sau;
//             if (L.head == NULL)
//                 L.tail = NULL;
//         }
//         else if (trc != NULL && sau == nullptr)
//         {
//             trc->next = NULL;
//             delete L.tail;
//             L.tail = trc;
//         }

// }
void delPros(List &L, int &check, char s[31])
{

    node *sau = L.head;
    node *trc = nullptr;
    char *l;
    while (sau != nullptr)
    {
        l = strstr((sau->info).name, s);
        if (l)
        {
            check = true;
            if (sau == L.head)
            {
                L.head = sau->next;
                if (L.tail == sau)
                {
                    L.tail = NULL;
                }
                delete sau;
                sau = L.head;
            }
            else if (sau == L.tail)
            {
                trc->next = NULL;
                L.tail = trc;
                delete sau;
                sau = NULL;
            }

            else
            {
                trc->next = sau->next;
                delete sau;
                sau = trc->next;
            }
        }
        else
        {
            trc = sau;
            sau = sau->next;
        }
    }
}
void removeList(List &l)
{
    node *p = l.pHead;
    while (p != nullptr)
    {
        node *temp = p;
        p = p->next;
        delete temp;
    }
    l.pHead = nullptr;
    l.tail = nullptr;
}
int main()
{
    List L;
    Init(L);
    inputListProvinces(L);
    cout << "List of provinces:" << endl;
    cout << "ID\t|Province\t|Population\t|Area" << endl;
    outputListProvinces(L);
    node *dmcd = L.head;
    if (dmcd != nullptr)
    {
        cout << "Enter the last word of name to search:" << endl;
        char s[31];
        int check = 0;
        cin.ignore();
        cin.getline(s, 31);
        delPros(L, check, s);
        if (check)
        {
            cout << "Updated List:" << endl;
            cout << "ID\t|Province\t|Population\t|Area" << endl;
            outputListProvinces(L);
        }
        else
            cout << "Not found";
    }

    return 0;
}
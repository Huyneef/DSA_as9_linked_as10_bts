
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
    node *pHead;
    node *tail;
};

void Init(List &l)
{
    l.pHead = nullptr;
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
    if (L.pHead == nullptr)
    {
        L.pHead = p;
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
    node *p = l.pHead;
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

//         node *sau = L.pHead;
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
//             L.pHead = L.pHead->next;
//             sau->next = NULL;
//             delete sau;
//             if (L.pHead == NULL)
//                 L.tail = NULL;
//         }
//         else if (trc != NULL && sau == nullptr)
//         {
//             trc->next = NULL;
//             delete L.tail;
//             L.tail = trc;
//         }

// }
// void delPros(List &L, int &check, char s[31])
// {

//     node *sau = L.pHead;
//     node *trc = nullptr;
//     char *l;
//     while (sau != nullptr)
//     {
//         l = strstr((sau->info).name, s);
//         if (l)
//         {
//             check = true;
//             if (sau == L.pHead)
//             {
//                 L.pHead = sau->next;
//                 if (L.tail == sau)
//                 {
//                     L.tail = NULL;
//                 }
//                 delete sau;
//                 sau = L.pHead;
//             }
//             else if (sau == L.tail)
//             {
//                 trc->next = NULL;
//                 L.tail = trc;
//                 delete sau;
//                 sau = NULL;
//             }

//             else
//             {
//                 trc->next = sau->next;
//                 delete sau;
//                 sau = trc->next;
//             }
//         }
//         else
//         {
//             trc = sau;
//             sau = sau->next;
//         }
//     }
// }
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
    cout<<"List of provinces:"<<endl;
    cout<<"ID\t|Province\t|Population\t|Area"<<endl;
    outputListProvinces(L);

    if(L.pHead)
    {
        cout<<"Delete all:"<<endl;
        removeList(L);
        outputListProvinces(L);
    }
    return 0;
}





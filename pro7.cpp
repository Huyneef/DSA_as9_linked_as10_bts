
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

typedef Node* Tree;

Node* getNode(int data) {
    Node* newNode = new Node();
    if (newNode == NULL) {
        cout << "";
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void SetLeft(Node* node, int data) {
    if (node == NULL) {
        cout << "";
        return;
    }
    if (node->left != NULL) {
        cout <<  "";
        return;
    }
    node->left = getNode(data);
}

void SetRight(Node* node, int data) {
    if (node == NULL) {
        cout <<  "";
        return;
    }
    if (node->right != NULL) {
        cout <<  "";
        return;
    }
    node->right = getNode(data);
}

Node* Search(Node* node, int data) {
    if (node == NULL || node->data == data) {
        return node;
    }
    Node* leftResult = Search(node->left, data);
    if (leftResult != NULL) {
        return leftResult;
    }
    return Search(node->right, data);
}

void DeleteLeft(Node* node) {
    if (node == NULL) {
        cout << "Node khong ton tai\n";
        return;
    }
    if (node->left == NULL) {
        cout << "Khong co node ben trai\n";
        return;
    }
    if (node->left->left != NULL || node->left->right != NULL) {
        cout << "Khong la node la nen khong xoa duoc\n";
        return;
    }
    delete node->left;
    node->left = NULL;
}

void DeleteRight(Node* node) {
    if (node == NULL) {
        cout << "Node khong ton tai\n";
        return;
    }
    if (node->right == NULL) {
        cout << "Khong co node ben phai\n";
        return;
    }
    if (node->right->left != NULL || node->right->right != NULL) {
        cout << "Khong la node la nen khong xoa duoc\n";
        return;
    }
    delete node->right;
    node->right = NULL;
}

void LNR(Node* node) {
    if (node != NULL) {
        LNR(node->left);
        cout << node->data << " ";
        LNR(node->right);
    }
}



int main()
{
	Tree T = NULL;
	int x,b,c; char a;
	cin>>x;	T=getNode(x); // tao nut goc
	while(true)
    {
        cin>>a; // Ky tu cho biet chen vao trai hay phai
        if(a!='L'&& a!='R') break;
        cin>>b>>c;
        if(a=='L') SetLeft(Search(T,b),c);
        else if (a=='R') SetRight(Search(T,b),c);

    }
	cout<<"LNR: "; LNR(T);
	cout<<"\nDelete some nodes:\n";
	string s;
	while(true)
    {
        cin>>s; // Chuoi cho biet xoa ben trai hay ben phai
        if(s!="DL"&& s!="DR") break;
        cin>>b;
        if(s=="DL") DeleteLeft(Search(T,b));
        else if(s=="DR") DeleteRight(Search(T,b));

    }
    cout<<"\nLNR: "; LNR(T);

	return 0;
}

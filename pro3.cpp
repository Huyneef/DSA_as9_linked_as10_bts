
#include <iostream>
#include <string>
using namespace std;

struct Product {
    int id;
    string name;
    string type;
    int year;
    int warranty;
};

struct Node {
    Product data;
    Node* left;
    Node* right;
};

typedef Node* Tree;

Node* createNode(Product data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Tree insertNode(Tree root, Product data) {
    if (root == NULL) {
        root = createNode(data);
    }
    else if (data.id < root->data.id) {
        root->left = insertNode(root->left, data);
    }
    else if (data.id > root->data.id) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

void listProduct(Tree root, string type) {
    if (root == NULL) {
        return;
    }
    listProduct(root->left, type);
    if (root->data.type == type) {
        cout << root->data.id << "\t" << root->data.name << "\t" << root->data.type << "\t" << root->data.year << "\t" << root->data.warranty << endl;
    }
    listProduct(root->right, type);
}

int countProduct(Tree root, int warrantyYears) {
    if (root == NULL) {
        return 0;
    }
    int count = 0;
    if (root->data.warranty > warrantyYears) {
        count++;
    }
    count += countProduct(root->left, warrantyYears);
    count += countProduct(root->right, warrantyYears);
    return count;
}

void inputTree(Tree& root) {
    int numProducts;
    cin >> numProducts;
    cin.ignore(); // Clear the newline character from the input buffer

    for (int i = 0; i < numProducts; i++) {
        Product product;
        cin >> product.id;
        cin.ignore();
        getline(cin, product.name);
        getline(cin, product.type);
        cin >> product.year;
        cin >> product.warranty;

        root = insertNode(root, product);
    }
}



int main()
{
    Tree T = NULL;
    inputTree(T);

    string type;  cin.ignore(); getline(cin,type);
    cout<<"List of products whose type is  "<<type<<": ";
    cout<<"\nID\tName\tType\tYear\tWarranty\n";
    listProduct(T,type);

    int year;cin>>year;
    cout<<"Number of products with more than "<<year<<" years of warranty: "<<countProduct(T,year)<<endl;


	return 0;
}

                                                                                                      
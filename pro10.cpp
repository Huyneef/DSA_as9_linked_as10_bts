#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
typedef Node *Tree;
Tree getNode(int x)
{
    Tree p = new Node;
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}
void insertTree(Tree &t, int x,bool& isFlag)
{
    if (t)
    {
        if(x == t->data) {isFlag = true; return ;}
        else if (x < t->data)
        {
            insertTree(t->left, x, isFlag);
        }
        else if (x > t->data)
        {
            insertTree(t->right, x, isFlag);
        }
    }
    else
        t = getNode(x);
}
void inputTree(Tree &t)
{
    bool isFlag = false;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        
        insertTree(t, x, isFlag);
        if(isFlag) {
            cout << "Bi trung gia tri, ket thuc qua trinh tao cay" << endl;
            return;
        }
    }
}
void LNR(Tree t)
{
    if (t)
    {
        LNR(t->left);
        cout << t->data << " ";
        LNR(t->right);
    }
}
int countNodes(Tree t) {
    if (!t) return 0;
    return countNodes(t->left) + countNodes(t->right) + 1;
}
int pow2(int n) {
    int result = 1;
    for (int i = 0; i < n; i++) {
        result *= 2;
    }
    return result;
}
int height(Tree t) {
    if (!t) return 0;
    int leftHeight = height(t->left);
    int rightHeight = height(t->right);
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

bool checkCompleteBinaryTree(Tree t, int index, int count) {
    if (!t) return true;
    if (index >= count) return false; // nếu index vượt quá số lượng nút thì không phải Complete Binary Tree
    return checkCompleteBinaryTree(t->left, 2 * index + 1, count) && checkCompleteBinaryTree(t->right, 2 * index + 2, count);
}

bool isCompleteBinaryTree(Tree t) {
    int nodeCount = countNodes(t);
    int h = height(t);
    return checkCompleteBinaryTree(t, 0, nodeCount) && (nodeCount == pow2(h) - 1);
}
// Hàm kiểm tra xem tầng thứ level của cây có phải là full không
// bool isFullLevel(Tree t, int level) {
//     if (!t) return true;
//     if (level == 1) {
//         return (t->left == NULL && t->right == NULL);
//     }
//     else if (level > 1) {
//         return isFullLevel(t->left, level - 1) && isFullLevel(t->right, level - 1);
//     }
//     return false;
// }

// // Hàm tính chiều cao của cây
// int height(Tree t) {
//     if (!t) return 0;
//     int leftHeight = height(t->left);
//     int rightHeight = height(t->right);
//     return max(leftHeight, rightHeight) + 1;
// }
// bool isCompleteBinaryTree(Tree t) {
//     if (!t) return true;
//     int h = height(t);
//     for (int i = 1; i <= h; i++) {
//         if (!isFullLevel(t, i)) return false;
//     }
//     return true;
// }

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"LNR: "; LNR(T);
	int i=isCompleteBinaryTree (T);
	if(i==0) cout<<"\nThe tree is not a Complete Binary Tree";
    else cout<<"\nThe tree is a Complete Binary Tree";
	return 0;
}



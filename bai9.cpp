#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;


struct DONTHUC{
	int somu;
	double heso;
};


struct Node{
	DONTHUC* data;
	Node* next;

};

typedef struct DATHUC{
	Node* head;
	Node* tail;
}List;



void Nhap(DATHUC &B, double hs, int sm) {
    
    Node* a = new Node;
    a->data = new DONTHUC {sm,hs};
    a->next = NULL;
    if(B.head == NULL) {
        B.head = a;
        B.tail = a;
    }
    else {
        B.tail->next = a;
        B.tail = a;
    }

}
void Xuat(DATHUC b) {
    int nothing = 1;
    Node* a = b.head;
    while (a != NULL) {
        if (a->data->heso != 0) {
            nothing = 0;
        }
        a = a->next;
    }
    if (nothing) {
        cout << "0" << endl;
        return;
    }
    a = b.head;
    int phanTuDauTien = 1;
    while(a != NULL) {
        if(a->data->heso != 0) {
            if(a->data->heso > 0 && !phanTuDauTien) {

                cout << "+";
            }
            phanTuDauTien = 0;
            if(a->data->somu == 1) {
                if(a->data->heso != 1)
                cout << a->data->heso << "x";
                else {
                    cout << "x";
                }
            }
            else if(a->data->somu == 0) {
                cout << a->data->heso ;

            }
            else {
                if(a->data->heso == -1) {
                    cout << "-x^" << a->data->somu;
                }
                else if (a->data->heso == 1) {
                    cout << "x^" << a->data->somu;
                }
                else {
                    cout << a->data->heso << "x^" << a->data->somu;
                }
            }

        }
        a = a->next;
    }
}
double TinhDaThuc(DATHUC B, double a) {
    Node* b = B.head;
    double sum = 0;
    while(b != NULL) {
        sum += b->data->heso*pow(a,b->data->somu) ;
        b = b->next;
    }
    return sum;
}
int main() {
    DATHUC B;
    B.head=B.tail=NULL;
    int n; cin >> n;
    double heso; int somu;
    for (int i = 0; i < n; i++)
    {
		cin >> heso >> somu;
		Nhap(B,heso,somu);
    }
    cout << "Da thuc vua nhap la: "; Xuat(B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}

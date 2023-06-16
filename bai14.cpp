struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertAfter(int a, int b) {
        Node* newNode = new Node(b);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            Node* curr = head;
            while (curr != nullptr && curr->data != a) {
                curr = curr->next;
            }
            if (curr == nullptr) {
                newNode->next = head;
                head = newNode;
            } else {
                newNode->next = curr->next;
                curr->next = newNode;
                if (curr == tail) {
                    tail = newNode;
                }
            }
        }
    }

    void moveElements(int k) {
        if (head == nullptr || k == 0) {
            return;
        }

        Node* curr = head;
        int count = 1;
        while (count < k && curr != nullptr) {
            curr = curr->next;
            count++;
        }

        if (curr == nullptr || curr == tail) {
            return;
        }

        tail->next = head;
        head = curr->next;
        curr->next = nullptr;
        tail = curr;
    }

    void printList() {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList linkedList;

    int command;
    while (cin >> command && command != 4) {
        if (command == 0) {
            int num;
            cin >> num;
            linkedList.insertAtHead(num);
        } else if (command == 1) {
            int num;
            cin >> num;
            linkedList.insertAtTail(num);
        } else if (command == 2) {
            int a, b;
            cin >> a >> b;
            linkedList.insertAfter(a, b);
        } else if (command == 3) {
            int k;
            cin >> k;
            linkedList.moveElements(k);
        }
    }

    linkedList.printList();

    return 0;
}
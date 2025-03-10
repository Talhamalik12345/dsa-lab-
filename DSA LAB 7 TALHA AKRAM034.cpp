#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkList {
private:
    Node* head;

public:
    DoublyLinkList() { head = nullptr; }
    void insertAtStart(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    
    void insertAtNth(int value, int n) {
        if (n == 1) {
            insertAtStart(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* temp = head;
        for (int i = 1; temp && i < n - 1; i++) {
            temp = temp->next;
        }
        if (!temp) {
            cout << "Position is out of range!" << endl;
            return;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }

    void insertAtcenter(int value) {
        if (!head) {
            insertAtStart(value);
            return;
        }
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* newNode = new Node(value);
        newNode->next = slow->next;
        newNode->prev = slow;
        if (slow->next) {
            slow->next->prev = newNode;
        }
        slow->next = newNode;
    }


    void displayForward() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

      void displayreverse() {
        if (!head) {
            cout << "LinkList is empty!" << endl;
            return;
        }
        Node* temp = head;
        while (temp->next) {  
            temp = temp->next;
        }
        while (temp) {  
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }
};


int main() {
    DoublyLinkList dll;
    dll.insertAtStart(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    dll.insertAtNth(15, 2);
    dll.insertAtcenter(20); 
    cout << "Forward: ";
    dll.displayForward();

    cout << "dislay Reverse: ";
    dll.displayreverse();

    return 0;
}

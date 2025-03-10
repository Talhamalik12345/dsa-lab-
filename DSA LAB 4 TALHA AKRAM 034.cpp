#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;

    Node(int value) { 
        data = value;
        next = nullptr;
    }
};

// Singly Linked List class
class SinglyLinkList {
private:
    Node* head;

public:
    SinglyLinkList() { head = nullptr; }

    void insertAtStart(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }


    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    
    void insertAtPosition(int value, int pos) {
        if (pos < 1) {
            cout << "Invalid position!" << endl;
            return;
        }

        Node* newNode = new Node(value);

        if (pos == 1) { 
            newNode->next = head;
            head = newNode;
            display();
            return;
        }

        Node* temp = head;
        for (int i = 1; temp != nullptr && i < pos - 1; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Position is out of bounds!" << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        display();
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    ~SinglyLinkList() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    SinglyLinkList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    cout << "Initial List-: ";
    list.display();

    list.insertAtPosition(15, 2); 
    list.insertAtPosition(0, 1); 
    list.insertAtPosition(35, 6); 
    list.insertAtPosition(50, 10); 

    return 0;
}

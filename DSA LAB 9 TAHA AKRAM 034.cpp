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

class CircularLinkList {
private:
    Node* head;

public:
    CircularLinkList() { head = nullptr; }
    void insertAtStart(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head; 
            return;
                   }
        Node* temp = head;
        while (temp->next != head) { 
            temp = temp->next;
                                   }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
                                }

    
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head;
            return;
                   }
        Node* temp = head;
        while (temp->next != head) { 
            temp = temp->next;
                                   }
        temp->next = newNode;
        newNode->next = head;
                              } 

    // Insert at Nth position
    void insertAtNth(int value, int n) {
        if (n == 1) {
            insertAtStart(value);
            return;
                    }
        Node* newNode = new Node(value);
        Node* temp = head;
        for (int i = 1; i < n - 1 && temp->next != head; i++) {
            temp = temp->next;
                                                              }
        if (temp->next == head && n > 2) {
            cout << "Position is out of range!" << endl;
            return;
                                         }
        newNode->next = temp->next;
        temp->next = newNode;
                                        } 

    void insertAtcenter(int value) {
        if (!head) {
            insertAtStart(value);
            return;
                   }
        Node* slow = head;
        Node* fast = head;
        while (fast->next != head && fast->next->next != head) {
            slow = slow->next;
            fast = fast->next->next;
                                                               } 
        Node* newNode = new Node(value);
        newNode->next = slow->next;
        slow->next = newNode;
                                    }

    void displayForward() {
        if (!head) {
            cout << "LinkList is empty!" << endl;
            return;
                   }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)" << endl;
    }

    void displayReverse() {
        if (!head) {
            cout << "LinkList is empty!" << endl;
            return;
        }
        Node* temp = head;
        Node* last = head;
        do {
            last = last->next;
        } while (last->next != head); 

        cout << "Reverse Order is -: ";
        while (last != head) {
            Node* prev = head;
            while (prev->next != last) {
                prev = prev->next;
            }
            cout << last->data << " -> ";
            last = prev;
        }
        cout << head->data << " -> (back to head)" << endl;
    }
};


int main() {
    CircularLinkList cll;
    cll.insertAtStart(10);
    cll.insertAtEnd(30);
    cll.insertAtEnd(40);
    cll.insertAtNth(20, 3); 
    cll.insertAtcenter(15); 


    cout << " Forward-: ";
    
    cll.displayForward();

    cout << "Reverse-: ";
    cll.displayReverse();

    return 0;
}

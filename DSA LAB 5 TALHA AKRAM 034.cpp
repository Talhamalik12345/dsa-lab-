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

class SinglyLinkList {
private:
    Node* head;

public:
    SinglyLinkList() {
        head = nullptr;
                     }


    void insert(int value) {
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
                            }

    void displayFirstNode() {
        if (head)
            cout << "First Node is :: " << head->data << endl;
        else
            cout << "LinkList is empty." << endl;
                            }     

    void displayLastNode() {
        if (!head) {
            cout << "LinkList is empty." << endl;
            return;
                   }       
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
                           }
        cout << "Last Node is :: " << temp->data << endl;
    }

    
    void displayNthNode(int n) {
        Node* temp = head;
        int count = 1;
        while (temp) {
            if (count == n) {
                cout << "Nth Node (" << n << "): " << temp->data << endl;
                return;
            }
            temp = temp->next;
            count++;
        }
        cout << "Nth node does not exist in the linklist." << endl;
    }

    
    void displayCenterNode() {
        if (!head) {
            cout << "LinkList is empty." << endl;
            return;
        }
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Center Node is:: " << slow->data << endl;
    }

    void displayList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};


int main() {
    SinglyLinkList list;
    list.insert(5);
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    list.displayList();
    list.displayFirstNode();
    list.displayLastNode();
    list.displayNthNode(2);
    list.displayCenterNode();

    return 0;
}

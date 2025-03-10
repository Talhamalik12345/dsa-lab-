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

class SinglyLinkedList {
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

    void displayList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
                     }
        cout << "NULL" << endl;
                       }  


    void deletefirstNode() {
        if (!head) {
            cout << "LinkList is empty." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "First node is deleted." << endl;
    }

    void deletelastNode() {
        if (!head) {
            cout << "LinkList is empty." << endl;
            return;
                   }
        if (!head->next) {
            delete head;
            head = nullptr;
            cout << "Last node  is deleted." << endl;
            return;
                         }
        Node* temp = head;
        while (temp->next->next) {
            temp = temp->next;
                                 }
        delete temp->next;
        temp->next = nullptr;
        cout << "Last node is deleted." << endl;
        }

    void deleteNthNode(int n) {
        if (!head) {
            cout << "List is empty." << endl;
            return;
                   }
        if (n == 1) {
            deletefirstNode();
            return;
                    }
        Node* temp = head;
        Node* prev = nullptr;
        int count = 1;
        while (temp && count < n) {
            prev = temp;
            temp = temp->next;
            count++;
                                  }
        if (!temp) {
            cout << "Nth node does not exists." << endl;
            return;
                    }
        prev->next = temp->next;
        delete temp;
        cout << "Nth node  is deleted." << endl;
    }

    void deletecenterNode() {
        if (!head) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
                    }
        if (!head->next) { 
            delete head;
            head = nullptr;
            cout << "Center node is deleted." << endl;
            return;
                          }
        Node* slow = head;
        Node* fast = head;
        Node* prev = nullptr;
        
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
                                   }
        
        prev->next = slow->next;
        delete slow;
        cout << "Center node is deleted." << endl;
    }
};

// Driver Code
int main() {
    SinglyLinkedList list;
    list.insert(5);
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    cout << "Initial List is -: ";
    list.displayList();

    list.deletefirstNode();
    cout << "After deleting the  first node: ";
    list.displayList();

    list.deletelastNode();
    cout << "After deleting  the last node: ";
    list.displayList();

    list.deleteNthNode(2);
    cout << "After deleting the 2nd node: ";
    list.displayList();

    list.deletecenterNode();
    cout << "After deleting the  center node: ";
    list.displayList();

    return 0;
}

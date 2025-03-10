#include <iostream>
using namespace std;
struct DNode {
    int data;
    DNode* next;
    DNode* prev;

    DNode(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
                     }             
};

class DoublyLinkList {
public:
    DNode* head;

    DoublyLinkList() { head = nullptr; }

    void insertAtend(int value) {
        DNode* newNode = new DNode(value);
        if (!head) {
            head = newNode;
            return;
                   }        
        DNode* temp = head;
        while (temp->next) {
            temp = temp->next;
                            }
        temp->next = newNode;
        newNode->prev = temp;
                            }

    void MergeList(DoublyLinkList& list2) {
        if (!head) {
            head = list2.head;
            return;
                   }
        DNode* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = list2.head;

        if (list2.head) {
            list2.head->prev = temp; 
                        }               
    }

    void displayforward() {
        DNode* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
                     }
        cout << " NULL " << endl;
    }

    void displayReverse() {
        if (!head) {
            cout << "LinkList is empty!" << endl;
            return;
                           }
        DNode* temp = head;
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
    DoublyLinkList list1, list2;
    list1.insertAtend(30);
    list1.insertAtend(20);
    list1.insertAtend(10);

    list2.insertAtend(60);
    list2.insertAtend(50);
    list2.insertAtend(40);

    cout << "List 1 (Forward): ";
    list1.displayforward();

    cout << "List 2 (Forward): ";
    list2.displayforward();

    list1.MergeList(list2);

    cout << "Merged List (Forward): ";
    list1.displayforward();

    cout << "Merged List (Reverse): ";
    list1.displayReverse();

    return 0;
}

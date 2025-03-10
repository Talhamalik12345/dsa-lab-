#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
            };

class SinglyLinkList {
public:
    Node* head;
    SinglyLinkList() : head(nullptr) {}


    void insertAtEnd(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void insertAtStart(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = head;
        head = newNode;
                                }
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    SinglyLinkList singlelist;

    // Insert nodes at the end
    singlelist.insertAtEnd(20);
    singlelist.insertAtEnd(30);
    singlelist.insertAtEnd(40);
    cout << "Linked List after inserting value at the end: ";
    singlelist.printList();

    // Insert nodes at the start
    singlelist.insertAtStart(5);
    singlelist.insertAtStart(10);
    cout << "Linked List after inserting value at the start: ";
    singlelist.printList();

    return 0;
}
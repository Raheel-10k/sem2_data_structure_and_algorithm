#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

struct CircularLinkedcList {
    Node* head;

    CircularLinkedcList() : head(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head;  // Point to itself to form a circular link
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void display() {
        if (head == nullptr) {
            cout << "cList is empty." << endl;
            return;
        }

        Node* current = head;
        do {
            cout << current->data << " and my address: "<<current<<endl;
            cout<<current->next<<" ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedcList clist;
    clist.insert(1);
    clist.insert(2);
    clist.insert(3);
    cout << "Circular Linked cList: ";
    clist.display();

    return 0;
}

#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

Node* insert(Node* head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    return newNode;
}//new node

void display(Node* head) {
    Node* current = head;//new nodes
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
};//in reverse order

int main() {
    Node* head = nullptr;// first node

    head=insert(head, 2);
    head=insert(head, 30);
    head=insert(head, 3);

    cout << "Linked List: ";
    display(head);

    return 0;
}

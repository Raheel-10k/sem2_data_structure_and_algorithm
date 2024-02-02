#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

Node *insert(Node *head, int value) {
    Node *newNode = new Node(value); // new nodes
    newNode->next = head;
    cout<<newNode->data<<" : "<<newNode->next<<endl;
    return newNode;
} // new node

void display(Node *head) {
    Node *current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}; // in reverse order

int main() {
    Node *head = nullptr; // first node

    head = insert(head, 2); // last node
    head = insert(head, 30);
    head = insert(head, 3); // first node
    // This is because a linkedlist generally follows fifo
    cout << "Linked List: ";
    display(head);
    return 0;
}

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

Node *insert(Node *head, int value) {
    Node *newNode = new Node(value);
    newNode->next = head;
    return newNode;
}//node at start

void display(Node *head) {
    Node *current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node *head = nullptr;

    head = insert(head, 3);
    head = insert(head, 30);
    head = insert(head, 2);

    cout << "Linked List: ";
    display(head);

    return 0;
}

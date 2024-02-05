#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

Node *insert(Node *head, int value) {
    Node *newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
    } else {
        Node *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    return head;
}

void display(Node *head) {
    Node *current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        cout<<current->next<<" ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node *head = nullptr;

    // Adding nodes at the end
    head = insert(head, 3);
    head = insert(head, 30);
    head = insert(head, 2);

    cout << "Linked List: ";
    display(head);

    return 0;
}

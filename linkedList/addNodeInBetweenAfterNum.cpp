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

Node *insertAfterValue(Node *head, int num, int value) {
    Node *newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
    } else {
        Node *current = head;
        while (current != nullptr && current->data != num) {
            current = current->next;
        }

        if (current != nullptr) {
            newNode->next = current->next;
            current->next = newNode;
        } else {
            head = insert(head, value);
        }
    }

    return head;
}

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

    // Creating a linked list with initial nodes
    head = insert(head, 3);
    head = insert(head, 7);
    head = insert(head, 10);

    cout << "Original Linked List: ";
    display(head);

    int searchVal = 7;

    // Checking for the number and adding a new node after it
    head = insertAfterValue(head, searchVal, 5);

    cout << "Linked List after adding after " << searchVal << ": ";
    display(head);

    return 0;
}

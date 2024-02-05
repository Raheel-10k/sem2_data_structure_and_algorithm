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

Node *insertBeforeValue(Node *head, int num, int value) {
    Node *newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
    } else if (head->data == num) {
        newNode->next = head;
        head = newNode;
    } else {
        Node *current = head;
        while (current->next != nullptr && current->next->data != num) {
            current = current->next;
        }
        if (current->next != nullptr) {
            newNode->next = current->next;
            current->next = newNode;
        } else {
            current->next = newNode;
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
    head = insert(head, 3);
    head = insert(head, 7);
    head = insert(head, 10);

    cout << "Original Linked List: ";
    display(head);

    int searchVal = 7;
    head = insertBeforeValue(head, searchVal, 5);

    cout << "Linked List after adding before " << searchVal << ": ";
    display(head);

    return 0;
}

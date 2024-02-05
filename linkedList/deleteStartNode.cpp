#include <iostream>

using namespace std;
struct Node {
    int data;
    Node* next;
};

Node* deleteStartNode(Node* head) {
    if (head == nullptr) {
        cout << "Linked list is empty. Cannot delete start node." << endl;
        return nullptr;
    }

    Node* newHead = head->next;
    free(head);

    return newHead;
}

Node* insertData(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        return newNode;
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;

    return head;
}

void display(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    head = insertData(head, 3);
    head = insertData(head, 7);
    head = insertData(head, 10);

    cout << "Original Linked List: ";
    display(head);

    head = deleteStartNode(head);

    cout << "Linked List after deleting start node: ";
    display(head);
    head = insertData(head, 5);

    cout << "Linked List after inserting data 5 at the end: ";
    display(head);

    return 0;
}

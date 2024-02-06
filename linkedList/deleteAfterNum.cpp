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
    cout<<newNode->data<<" : "<<newNode->next<<endl;
    return newNode;
}

void deleteNodeAfter(Node* start, int num) {
    Node* ptr = start;

    while (ptr != nullptr && ptr->data != num) {
        ptr = ptr->next;
    }

    Node* temp = ptr->next;
    ptr->next = temp->next;

    free(temp);
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

    head = insert(head, 2);
    head = insert(head, 30);
    head = insert(head, 20);
    head = insert(head, 90);
    head = insert(head, 33);
    head = insert(head, 45);
    head = insert(head, 3);
    cout << "Linked List: ";
    display(head);

    deleteNodeAfter(head, 90);
    display(head);
    return 0;
}

#include <iostream>
#include <cstdlib> // Include for malloc

using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Function to delete the start node of the linked list
Node* deleteStartNode(Node* head) {
    if (head == nullptr) {
        cout << "Linked list is empty. Cannot delete start node." << endl;
        return nullptr;
    }

    Node* newHead = head->next;
    free(head); // Free memory allocated for the start node

    return newHead;
}

// Function to insert a new node with specified data at the end of the linked list
Node* insertData(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        // If the list is empty, make the new node the head
        return newNode;
    }

    // Traverse the list to the end
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    // Add the new node to the end
    current->next = newNode;

    return head;
}

// Function to display the linked list
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

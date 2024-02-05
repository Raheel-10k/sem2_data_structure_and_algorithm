#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

void deleteNodeBefore(Node* start, int num) {

    Node* ptr = start;
    Node* preptr = nullptr;

    while (ptr->next != nullptr && ptr->next->data != num) {
        preptr = ptr;
        ptr = ptr->next;
    }

        Node* temp = preptr->next;
        preptr->next = ptr->next;
        
        delete temp;
    
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

void display(Node *head) {
    Node *current=head;
    while (current != nullptr) {
        cout << current->data << " "<<current->next<< " ";
        current = current->next;
    }
    cout<<endl;
}

// Example Usage
int main() {
    // Create a sample linked list
    Node* start = new Node(1);
    
    start=insertData(start, 2);
    start=insertData(start, 9);
    start=insertData(start, 3);
    start=insertData(start, 5);
    display(start);
    deleteNodeBefore(start, 3);

    display(start);


    return 0;
}

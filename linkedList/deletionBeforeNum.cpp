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
    start->next = new Node(2);
    start->next->next = new Node(3);
    start->next->next->next = new Node(4);
    display(start);
    deleteNodeBefore(start, 3);

    display(start);


    return 0;
}

#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

Node *insert(Node *head, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node)); // new nodes
    ;
    newNode->data = value;
    newNode->next = head;
    cout<<newNode->next<<" "<<newNode->data<<endl;
    return newNode;
} // new node

void display(Node *head) {
  Node *current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
};

int numOfnodes(Node *head) {
    Node *current=head;
    int count=0;
    while(current!=nullptr) {
        count++;
        current=current->next;
    }
    return count;
}

int main() {
    Node *head = nullptr; // first node

    char choice='y';
    while(tolower(choice)!='n') {
        int value=0;
        cout<<"Enter value: ";
        cin>>value;
        head=insert(head, value);
        cout<<"Enter 'n' to exit else press any key to continue: ";
        cin>>choice;
    }
    // This is because a linkedlist generally follows fifo
    cout << "Linked List: ";
    display(head);
    cout<<"Number of nodes: "<<numOfnodes(head);

    return 0;
}

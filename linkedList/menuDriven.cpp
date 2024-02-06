#include "iostream"
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

Node *insertionAtBegining(Node *head, int value) {
    Node *newNode = new Node(value);
    newNode->next = head;
    return newNode;
}

Node *insertionAtEnd(Node *head, int value) {
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

Node* deleteStartNode(Node* head) {
    if (head == nullptr) {
        cout << "Linked list is empty. Cannot delete start node." << endl;
        return nullptr;
    }

    Node* newHead = head->next;
    free(head);

    return newHead;
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
    char choice;
    Node *head=nullptr;
    do
    {
        cout<<"Enter '1' for insertion, '2' for deletion and '3' for displaying: ";
        cin>>choice;
        switch (choice)
        {
        case '1':
            cout<<"Enter '1' For insertion at begining, '2' For insertion at end, '3' For insertion in between: ";
            cin>>choice;
            switch (choice)
            {
            case '1':
                int val;
                cout<<"Enter value to add: ";
                cin>>val;
                insertionAtBegining(head, val);
                break;
            case '2':
                int val;
                cout<<"Enter value to add: ";
                cin>>val;
                insertionAtEnd(head, val);
                break;
            case '3':
                display(head);
                int val, valueToAddAfter;
                cout<<"First enter value to add, then enter the value you would like to add this number after:\n";
                cin>>val>>valueToAddAfter;
                insertAfterValue(head, val, valueToAddAfter);
            default:
                cout<<"invalid error";
                break;
            }
            break;
        
        case '2':
            cout<<"Enter '1' For deletion of start node, '2' For deletion of end node, '3' For deletion in between: ";
            cin>>choice;
            switch (choice)
            {
            case '1':
                deleteStartNode(head);
                break;
            case '2':
                //deletionAtEnd(head, val);
                break;
            case '3':
                //deletionInbetween(head, val, valuetoaddbefore);
            default:
                cout<<"invalid error";
                break;
            }
            break;
        case '3':
            cout<<"Enter '1' For deletion at begining, '2' For deletion at end, '3' For deletion in between: ";
            cin>>choice;
            //display(head);
            break;
        
        default:
            break;
        }
    } while (choice!='n');
    
}
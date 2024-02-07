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
    cout<<"Node deleted.";
    return newHead;
}

Node *deleteLastNode(Node *head) {
    if (head == nullptr) {
        cout << "Linked list is empty. Cannot delete start node." << endl;
        return nullptr;
    }
    Node *current=head;
    Node *previous=nullptr;
    while(current->next!=nullptr) {
        previous=current;
        current=current->next;
    }
    free(current);
    previous->next=nullptr;
    cout<<"Node deleted.";
    return head;
}

Node *deleteNodeWithSpecificValue(Node *head, int val){
    if(head==nullptr) {
        cout << "Linked list is empty. Cannot delete start node." << endl;
        return nullptr;
    }
    Node *current=head;
    Node *previous=current;
    while(current!=nullptr && current->data==val) {
        previous=current;
        current=current->next;
    }
    previous->next=current->next;
    free(current);
    cout<<"Node with value "<<val<<" deleted.";
    return head;
}

Node *deleteNodeBefore(Node* start, int num) {

    Node* ptr = start;
    Node* preptr = nullptr;

    while (ptr->next != nullptr && ptr->next->data != num) {
        preptr = ptr;
        ptr = ptr->next;
    }

        Node* temp = preptr->next;
        preptr->next = ptr->next;
        
        free(temp);
        cout<<"Node deleted.";
        return start;
}

Node *deleteNodeAfter(Node* start, int num) {
    Node* ptr = start;

    while (ptr != nullptr && ptr->data != num) {
        ptr = ptr->next;
    }

    Node* temp = ptr->next;
    ptr->next = temp->next;

    free(temp);
    return start;
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
        int val, valueToAddAfter;
        switch (choice)
        {
        case '1':
            cout<<"Enter '1' For insertion at begining, '2' For insertion at end, '3' For insertion in between: ";
            cin>>choice;
            switch (choice)
            {
            case '1':

                cout<<"Enter value to add: ";
                cin>>val;
                head=insertionAtBegining(head, val);
                break;
            case '2':

                cout<<"Enter value to add: ";
                cin>>val;
                head=insertionAtEnd(head, val);
                break;
            case '3':
                display(head);
                cout<<"First enter value to add, then enter the value you would like to add this number after:\n";
                cin>>val>>valueToAddAfter;
                head=insertAfterValue(head, val, valueToAddAfter);
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
                head=deleteStartNode(head);
                break;
            case '2':
                head=deleteLastNode(head);
                break;
            case '3':
                cout<<"Enter value to delete: ";
                cin>>val;
                head=deleteNodeWithSpecificValue(head, val);
                // head=deleteNodeBefore(head, val);  //where value should be the value before which the node has to be deleted. Better first display the linked list and ask user to refer the list and enter values.
                // head=deleteNodeAfter(head, val);   //where value should be the value after which the node has to be deleted. Better first display the linked list and ask user to refer the list and enter values.
            default:
                cout<<"invalid error";
                break;
            }
            break;
        case '3':
            display(head);
            break;
        
        default:
            cout<<"invalid error";
            break;
        }
        cout<<"press 'n' to end execution or any other key to continue: ";
        cin>>choice;
    } while (choice!='n');
    
}
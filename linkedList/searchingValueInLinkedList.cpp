#include "iostream"
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int val): data(val), next(nullptr) {}
};

Node *insert(Node *head, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node)); // new nodes
    newNode->data = value;
    newNode->next = head;
    cout<<newNode->next<<" "<<newNode->data<<endl;
    return newNode;
}

void searchingVal(Node *head, int val) {
    Node *ptr=head;
    while (ptr!=nullptr) {
        if(ptr->data==val) {
            cout<< "Value found"<<endl;
            return;
        }
        ptr=ptr->next;
    }
    cout<<"Value not found"<<endl;
}

int main() {
    Node *head=nullptr;
    char choice;
    int searchVal;
    do
    {
        int value=0;
        cout<<"Enter value: ";
        cin>>value;
        head=insert(head, value);
        cout<<"Enter 'n' to exit else press any key to continue: ";
        cin>>choice;
    } while (choice!='n');
    
    cout<<"Enter value to search: ";
    cin>>searchVal;
    searchingVal(head, searchVal);

}
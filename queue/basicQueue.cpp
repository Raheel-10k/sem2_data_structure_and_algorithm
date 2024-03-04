#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int value) {
        Node* newNode=new Node(value);
        if(isEmpty()) {
            front=rear=newNode;
        } 
        else {
            rear->next=newNode;
            rear=newNode;
        }
    }

    void dequeue() {
        if(isEmpty()) {
            cout<<"Queue is empty. Cannot dequeue.\n";
        } 
        else {
            Node* temp=front;
            front=front->next;
            delete temp;
        }
    }

    bool isEmpty() {
        return front==nullptr;
    }

    int peek() {
        if(isEmpty()) {
            cout<<"Queue is empty. Cannot peek.\n";
            return -1;
        }
        return front->data;
    }
};

int main() {
    Queue myQueue;
    int choice, value;

    do {
        cout<<"1. Enqueue\n";
        cout<<"2. Dequeue\n";
        cout<<"3. Peek\n";
        cout<<"4. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice) {
            case 1:
                cout<<"Enter value to enqueue: ";
                cin>>value;
                myQueue.enqueue(value);
                cout<<"Enqueued "<<value<<" to the queue.\n";
                break;
            case 2:
                myQueue.dequeue();
                cout<<"Dequeued an element from the queue.\n";
                break;
            case 3:
                cout<<"Front element: "<<myQueue.peek()<<endl;
                break;
            case 4:
                cout<<"Exiting the program.\n";
                break;
            default:
                cout<<"Invalid choice. Please enter a valid option.\n";
        }

    } while(choice != 4);

    return 0;
}

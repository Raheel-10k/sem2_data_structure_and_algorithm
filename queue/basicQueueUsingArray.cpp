#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear, capacity;
    int* array;

public:
    Queue(int size) {
        capacity = size;
        front = rear = -1;
        array = new int[capacity];
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % capacity == front;
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << item << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }

        array[rear] = item;
        cout << item << " enqueued to the queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        cout << array[front] << " dequeued from the queue." << endl;

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return array[front];
    }
};

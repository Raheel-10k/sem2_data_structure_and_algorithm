#include <iostream>

using namespace std;

struct User {
    int id;
    int burstTime;
    int remainingTime;
    User* next;

    User(int _id, int _burstTime) : id(_id), burstTime(_burstTime), remainingTime(_burstTime), next(nullptr) {}
};

User* createUser(int id, int burstTime) {
    return new User(id, burstTime);
}

void addUser(User*& head, int id, int burstTime) {
    User* newUser = createUser(id, burstTime);

    if (!head) {
        head = newUser;
        newUser->next = head;
    } else {
        User* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        tail->next = newUser;
        newUser->next = head;
    }
}

void removeHead(User*& head) {
    if (head == nullptr) {
        return;
    }

    User* temp = head;
    if (head->next != head) {
        User* newHead = head->next;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newHead;
        head = newHead;
    } else {
        head = nullptr;
    }
    delete temp;
}

void roundRobin(User*& head, int quantum) {
    while (head != nullptr) {
        User* current = head;

        if (current->remainingTime <= quantum) {
            cout << "User " << current->id << " has finished printing." << endl;
            removeHead(head);
        } else {
            cout << "User " << current->id << " is printing for " << quantum << " units." << endl;
            current->remainingTime -= quantum;
            head = head->next;
            removeHead(head);
            addUser(head, current->id, current->remainingTime);
        }

        // Update the next pointer of the new head to point back to itself
        if (head != nullptr) {
            head->next = head;
        }
    }
} 

int main() {
    User* head = nullptr;

    addUser(head, 1, 8);
    addUser(head, 2, 3);
    addUser(head, 3, 10);

    int quantum = 3;

    cout << "Users burst times: [1] 8, [2] 3, [3] 10" << endl;
    cout << "Quantum: " << quantum << endl;
    cout << "-------------------------------------------" << endl;

    roundRobin(head, quantum);

    return 0;
}

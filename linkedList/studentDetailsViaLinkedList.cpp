#include <iostream>
using namespace std;

struct studentMarks {
    float marks[5];   //since a restriction of 5 subject marks only is asked.
    string name;
    int rollNumber;
    studentMarks *next;

    studentMarks(float value[], int rollNum, string n) {
        for(int i=0;i<5;i++) {
            marks[i]=value[i];
        }
        rollNumber=rollNum;
        name=n;
        next=nullptr;
    }

    float avgMarks() {
        float sum=0;
        for(int i=0;i<5;i++) {
            sum +=marks[i];
        }
        return sum/5;
    }//finding avr of 5 subjects in THIS node.
};

studentMarks *insert(studentMarks *head, float values[], int rnum, string n) {
    studentMarks *newStudent = new studentMarks(values, rnum, n);
    newStudent->next = head;
    return newStudent;
}

void display(studentMarks *head) {
    studentMarks *current=head;
    cout<<"Student "<<current->name<<", roll num "<<current->rollNumber<<" has scored: "<<endl;
    while(current!=nullptr) {
        for(int i=0;i<5;i++) {
            cout<<current->marks[i]<<" ";
        }
        cout << endl;
        cout <<"Average: "<<current->avgMarks()<<endl;
        current = current->next;
    }
}

int main() {
    studentMarks *head=nullptr;

    char choice='y';
    while(tolower(choice)!='n') {
        float values[5]={0};
        string name;
        int num;
        cout<<"Enter marks for the student (5 values): ";
        for(int i=0;i<5;i++) {
            cin>>values[i];
        }
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Enter roll number: ";
        cin>>num;
        head=insert(head, values, num, name);
        cout<<"Enter 'n' to exit, else press any key to continue: ";
        cin>>choice;
    }

    cout<<"Linked List:\n";
    display(head);


    while (head!=nullptr) {
        studentMarks *temp=head;
        head=head->next;
        delete temp;
    }//delete nodes (since work is done heap must be edited for future use.)

    return 0;
}

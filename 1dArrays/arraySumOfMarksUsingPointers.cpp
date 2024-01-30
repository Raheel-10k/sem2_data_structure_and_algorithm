#include "iostream"
using namespace std;

void sumOfEachSubject(int **subjects, int nOfSubjects, int numOfStundets) {
    for (int i = 0; i < nOfSubjects; i++) {
        int *subject = subjects[i];
        int marks=0;
        for (int j = 0; j < numOfStundets; j++) {
        marks+=subject[j];
        }
        marks/=numOfStundets;
        cout<<"Average of subject"<<i<<": "<<marks;
    }
}

int main() {

    int num = 0;
    cout << "Enter the number of students: ";
    cin >> num;

    int subject1[num];
    int subject2[num];
    int subject3[num];

    for (int i = 0; i < num; i++) {
        cout << "Enter the marks of 1st subject: ";
        cin >> subject1[i];
        cout << "Enter the marks of 2nd subject: ";
        cin >> subject2[i];
        cout << "Enter the marks of 3rd subject: ";
        cin >> subject3[i];
    }

    int *ptrs[3] = {subject1, subject2, subject3};

    sumOfEachSubject(ptrs, 3, num);

    return 0;
}

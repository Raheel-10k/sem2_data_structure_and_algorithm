#include <iostream>
using namespace std;
//STUDENT WISE DATA:
int passingPercentageOfSubject(int data[][5], int nOfStudents, int subject) {
    float passingStudents = 0;
    for (int i = 0; i < nOfStudents; i++) {
        if (data[i][subject] >= 33) {
        passingStudents++;
        }
    }
    float passingPercentage = (passingStudents / nOfStudents) * 100;
    return passingPercentage;
}

float failingPercentageOfSubject(int data[][5], int nOfStudents, int subject) {
    float failingStudents = 0;
    for (int i = 0; i < nOfStudents; i++) {
        if (data[i][subject] < 33) {
        failingStudents++;
        }
    }
    float failingPercentage = (failingStudents / nOfStudents) * 100;
    return failingPercentage;
}

int topperOfSubject(int data[][5], int nOfStudents, int subject) {
    int topperIndex = 0;
    for (int i = 1; i < nOfStudents; i++) {
        if (data[i][subject] > data[topperIndex][subject]) {
        topperIndex = i;
        }
    }
    return topperIndex;
}
//SUBJECT WISE DATA:
void displayStudentMarksSubjectWise(int data[][5], int nOfStd) {
    for (int i = 0; i < 5; i++) {
        cout<<"Subject "<<i+1<<": \n";
        for (int j = 0; j < nOfStd; j++) {
            cout<<"Student "<<j+1<<": "<<data[j][i];
        }
    }
}
void subjectWiseTotalmarks(int data[][5], int nOfStd) {
    int totalMarks[5] = {0};
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < nOfStd; j++) {
            totalMarks[i] += data[j][i];
        }
    }//total Marks In All Subjects

        for (int i = 0; i < 5; i++) {
            cout<<"Total class marks in subject "<<i<<": "<<totalMarks[i]<<" out of "<<100*nOfStd;//keeping max marks of each subject as 100.
        }
}
void subjectWisePercentage(int data[][5], int nOfStd) {
    int totalMarks[5] = {0};
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < nOfStd; j++) {
            totalMarks[i] += data[j][i];
        }
    }//total Marks In All Subjects

        for (int i = 0; i < 5; i++) {
            int percentage=((float)totalMarks[i]/float(nOfStd*100))*100;
            cout<<"Total class marks in subject "<<i<<": "<<percentage<<"%"<<endl;//keeping max marks of each subject as 100.
        }
}

int main() {
    int nOfStudents = 0;
    cout << "Enter the number of students: ";
    cin >> nOfStudents;

    int studentsData[nOfStudents][5];

    for (int i = 0; i < nOfStudents; i++) {
        cout << "Enter the data of student " << i + 1 << ": " << endl;
        for (int j = 0; j < 5; j++) {
            do{
                cout << "Enter the marks of subject " << j + 1 << ": ";
                cin >> studentsData[i][j];
            }while(studentsData[i][j]>100);
        }
        cout << endl;
    }

    cout << "Passing percentage of following subjects: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Subject " << i + 1 << ": "<< passingPercentageOfSubject(studentsData, nOfStudents, i)<< "% passed." << endl;
    }

    cout << "Failing percentage of following subjects: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Subject " << i + 1 << ": "<< failingPercentageOfSubject(studentsData, nOfStudents, i)<< "% failed." << endl;
    }

    cout << "Topper of each subject: " << endl;
    for (int i = 0; i < 5; i++) {
        int topperIndex = topperOfSubject(studentsData, nOfStudents, i);
        cout << "Subject " << i + 1 << ": Student " << topperIndex + 1<< " with marks " << studentsData[topperIndex][i] << endl;
    }

    displayStudentMarksSubjectWise(studentsData, nOfStudents);
    subjectWiseTotalmarks(studentsData, nOfStudents);
    subjectWisePercentage(studentsData, nOfStudents);

    return 0;
}

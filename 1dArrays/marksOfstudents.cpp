//WAP to ask teacher for the number of students, whose paper is checked and let him enter those many marks and store it in an marksOfStudentsay in ascending order. Now ask user to enter the marks of each remaining student, one by one and add it to the marksOfStudentsay in the same ascending order.
#include "iostream"
using namespace std;

void stdresultdata() {
    float marksOfStudents[46]={0.00}, marks;
    int numberOfInitialStudent;
    cout<<"Enter the number of students whose marks you have now: ";
    cin>>numberOfInitialStudent;
    int stdLeft=46-numberOfInitialStudent, count=0;
    for(int i=0;i<numberOfInitialStudent;i++) {
        cout<<"Enter marks of student"<<i<<": ";
        cin>>marks;
        if(i==0) {
            marksOfStudents[i]=marks;
        }
        else{
            for (int j=0;j<i-1; ++j) {
                if (marksOfStudents[i] > marksOfStudents[j]) {
                    int temp = marksOfStudents[i];
                    marksOfStudents[i] = marksOfStudents[j];
                    marksOfStudents[j] = temp;
                }
            }
        }
        count++;
    }
    cout<<stdLeft<<" student data left, please enter it now.";
    for(int i=count;i<numberOfInitialStudent;i++) {
        cout<<"Enter marks of student"<<i<<": ";
        cin>>marks;
        if(i==0) {
            marksOfStudents[i]=marks;
        }
        else{
            for (int j=0;j<i-1; ++j) {
                if (marksOfStudents[i] > marksOfStudents[j]) {
                    int temp = marksOfStudents[i];
                    marksOfStudents[i] = marksOfStudents[j];
                    marksOfStudents[j] = temp;
                }
            }
        }
    }
}


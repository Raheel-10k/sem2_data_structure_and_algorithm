#include "iostream"
using namespace std;

struct subStatus
{
    int marks;
    string sub;
    bool status; //if False then failed, True then passed
    Exam exams;

    void getDetails() {
        cout<<"Enter sub: ";
        cin>>sub;
        cout<<"Enter marks";
        cin>>marks;
    }
    void marksAfterReExam() {
        exams.reExam(&marks);
    };
};

subStatus firstExam[100];
class Exam {
    private:
        int numberOfsubjects;
        string studentName;
    public:
        Exam() {
            cout<<"Enter student name: ";
            cin>>studentName;
            cout<<"Enter number of subjects: ";
            cin>> numberOfsubjects;
            for(int i=0;i<numberOfsubjects;i++) {
                cout<<"Enter subject name: ";
                cin>>firstExam[i].sub;
                cout<<"Enter subject marks attained out of 30: ";
                cin>>firstExam[i].marks;
                while (firstExam[i].marks>30) {
                    cout<<"Enter marks again: ";
                    cin>>firstExam[i].marks;
                }
            }
        }

        int checkMarks() {
            int flag=0;
            for(int i=0;i<numberOfsubjects;i++) {
                if(firstExam[i].marks<20) {
                    //cout<<"You failed at subject "<<firstExam[i].sub<<endl;
                    firstExam[i].status=false;
                    flag+=1;
                }
                else {
                    firstExam[i].status=true;
                }
            }
            return flag;
        }

        void failedIn() {
            for(int i=0;i<numberOfsubjects;i++) {
                if(firstExam[i].marks<20) {
                    cout<<"You failed in subject "<<firstExam[i].sub<<" with "<<firstExam[i].marks<<"/30"<<endl;
                }
                else {
                    firstExam[i].status=true;
                }
            }
        }

        void reExam(int *marks) {
            for(int i=0;i<numberOfsubjects;i++) {
                if(firstExam[i].status==false) {
                    cout<<"Enter marks recieved after reexam of subject "<<firstExam[i].sub<<": ";
                    cin>>*marks;
                    if(*marks<20) {
                        cout<<"Sorry you have failed the retry too";
                    }
                    else {
                        firstExam[i].status=true;
                    }
                }
            }
        }
};


int main() {
    int stdNum;
    cout<<"Enter number of students: ";
    cin>>stdNum;

    for(int i=0; i <stdNum; i++) {
        firstExam[i];
    }


}
#include "iostream"
using namespace std;

struct students {
    string subject;
    float marks[3];
    bool status;

    bool check_status() {
        for(int i=0;i<3;i++) {
            if(marks[i] <40) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    int studentCount;
    cout<<"Student count: ";
    cin>>studentCount;

    students cls1[studentCount];
    string subjects[3]={"DSA", "HTML", "CSS"};

    int passingCount=0;
    for(int j=0;j<studentCount;j++) {
        for(int i=0;i<3;i++) {
            cout<<"Enter marks of student "<<j+1<<" in subject "<<subjects[i]<<": ";
            cin>>cls1[j].marks[i];
            while(cls1[j].marks[i]>100) {
                cout<<"INVALID MARKS: ";
                cin>>cls1[j].marks[i];
            }
        }
        if(cls1[j].check_status()==true) {
            passingCount++;
        }
    }
    int passingPercentage=(float(passingCount)/studentCount)*100;
    int failingPercentage=100-passingPercentage;

    cout<<"Passing Percentage: "<<passingPercentage<<endl;
    cout<<"Failing Percentage: "<<failingPercentage<<endl;
}
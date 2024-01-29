
#include "iostream"

using namespace std;

struct date {
    int dt, mt, yr;

    string birthdate() {
        cout<<"Enter birth date: ";
        cin>>dt;
        cout<<"Enter birth month: ";
        cin>>mt;
        cout<<"Enter birth year: ";
        cin>>yr;

        return to_string(dt)+"-"+to_string(mt)+"-"+to_string(yr);
    }
};
struct record
{
    int rollNum;
    string name;
    string DoB;
    record *linkerS;
    date n;

    void getValues() {
        cout<<"Enter the name of the student: ";
        cin>>name;
        cout<<"Enter the roll number of the student: ";
        cin>>rollNum;
        DoB=n.birthdate();
    }
    void display() {
        cout<<"Student Name: "<<name<<endl;
        cout<<"Student roll no: "<<rollNum<<endl;
        cout<<"Student Dob: "<<DoB<<endl;

    }
};




int main() {
    int length;
    cout<<"Enter the number of students whose detail you want to add: ";
    cin>>length;
    record studendDetail[length];
    for(int i=0;i<length;i++) {
        studendDetail[i].getValues();
    }
    for(int i=0;i<length;i++) {
        studendDetail[i].display();
        // cout<<studendDetail[i].rollNum;
    } 
}
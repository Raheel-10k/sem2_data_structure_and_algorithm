//WAP to calculate passing percentage and failing percentage of students in a given subject.
#include "iostream"
using namespace std;
int main() {
    int stdCount;
    string sub;
    cout<<"Enter number of stdunets: ";
    cin>>stdCount;
    cout<<"Enter subject: ";
    cin>>sub;
    int marks[stdCount];
    int passedCount=0;
    for(int i=0;i<stdCount;i++) {
        cout<<"Enter marks of "<<i<<": ";
        cin>>marks[i];
        if(marks[i]>=40) {
            passedCount++;
        }
    }
    int passedPercentage=(float(passedCount)/stdCount)*100;
    int failedPercentage=100-passedPercentage;

    cout<<"Percentage of student who passed in "<<sub<<" is: "<<passedPercentage<<endl;
    cout<<"Percentage of student who failed in "<<sub<<" is: "<<failedPercentage<<endl;

    return 0;
}
//WAP a cpp program, to read and display n numbers and calculate mean of n numbers using an array.
#include "iostream"
using namespace std;

int main() {
    int n;
    cout<<"Enter value of n: ";
    cin>>n;

    int arr[n];
    float mean=0;
    cout<<"Enter "<< n <<" values of the array:"<<endl;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        mean+=arr[i];
    }
    mean=float(mean/n);
    for(int i=0;i<n;i++) {
        cout<<"arr["<<i<<"]: "<<arr[i]<<endl;
    }
    cout<<mean<<endl;
    return 0;
}

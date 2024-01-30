//WAP to find largest and second largest number from n numbers of using an array, without sorting.
#include "iostream"
using namespace std;

void largestAndSecondLargest(int arr[], int arrlen) {
    int largest=arr[0], secondGreatest;
    for(int i=1;i<arrlen;i++) {
        if(largest<arr[i]) {
            secondGreatest=largest;
            largest=arr[i];
        }
    }
    cout<<largest<<secondGreatest;
} 

int main() {
    int n;
    cout<<"Enter value of n: ";
    cin>>n;

    int arr[n];
    cout<<"Enter "<< n <<" values of the array:"<<endl;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    
    largestAndSecondLargest(arr, n);
}
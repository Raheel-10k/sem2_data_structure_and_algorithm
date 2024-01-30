#include "iostream"
using namespace std;

void swappingLargestAndSmallest(int arr[], int n) {
    int maxNumIndex=0, minNumIndex=0;
    for(int i=0;i<n;i++) {
        if(arr[maxNumIndex]<arr[i]) {
            maxNumIndex=i;
        }
        if(arr[minNumIndex]>arr[i]) {
            minNumIndex=i;
        }
    }
    int temp=arr[maxNumIndex];
    arr[maxNumIndex]=arr[minNumIndex];
    arr[minNumIndex]=temp;
    for(int i=0;i<n;i++) {
        cout<<arr[i];
    }
}

int main() {
    int len;
    cout<<"Enter the number of elements: ";
    cin>>len;
    int arr[len];
    for(int i=0;i<len;i++) {
        cin>>arr[i];
    }
    swappingLargestAndSmallest(arr, len);
    return 0;
}
#include "iostream"

using namespace std;

int main() {
    int num;
    cout<<"Enter length of array: ";
    cin>>num;
    int largest=0, smallest;
    int *arr= (int *)calloc(num,sizeof(int));
    cout<<"Enter elements: ";
    for(int i=0;i<num;i++) {
        cin>>arr[i];
    }
    smallest=arr[0];
    for(int i=0;i<num;i++) {
        if(largest<arr[i]) {
            largest=arr[i];
        }
        if(smallest>arr[i]) {
            smallest=arr[i];
        }
    }
    cout<<"Largest: "<<largest<<endl;
    cout<<"Smallest: "<<smallest<<endl;
}
//Take user input for an array and calculate sum and mean:

#include "iostream"
using namespace std;

int main() {
    //for known length of array:
    int length;
    cout<<"Enter number of elements: ";
    cin>>length;
    int numbers[length];
    for(int i=0;i<length;i++) {
        cout<<"Enter value number "<<i<<": ";
        cin>>numbers[i];
    }
    int sum=0, mean;
    for(int i=0; i<length;i++) {
        sum+=numbers[i];
    }
    cout<<"sum of numbers is: "<<sum;
    mean=sum/length;
    cout<<"Mean of numbers is: "<<mean;

    //for unknown length of array:
    int size_t_count;
    cout<<"Enter initial number of elements: ";
    cin>>size_t_count;
    int *arr=(int *)calloc(size_t_count, sizeof(int));
    //We shall not use the size_t_count variable as it may change ahead:
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]);i++) {
        cin>>arr[i];
    }//more corrected way is to use a do while loop where condition remains same.

    int sum=0, mean;
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]);i++) {
        sum+=arr[i];
    }
    cout<<"sum of numbers is: "<<sum;
    mean=sum/length;
    cout<<"Mean of numbers is: "<<mean;

    return 0;
}
#include "iostream"

using namespace std;

void display(int *array) {
    int sum=0, mul=1;
    for(int i=0;i<sizeof(array)/sizeof(array[0]);i++) {
        sum+=array[i];
        mul*=array[i];
    }
    cout<<"Sum: "<<sum<<endl;
    cout<<"Mul: "<<mul<<endl;
}

int main() {
    int num;
    cout<<"Enter length of array: ";
    cin>>num;
    int *arr= (int *)calloc(num,sizeof(int));
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++) {
        cin>>arr[i];
    }
    display(arr);
    return 0;
}
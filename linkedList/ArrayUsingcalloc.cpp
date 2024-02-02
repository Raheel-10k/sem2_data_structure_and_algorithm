#include "iostream"
using namespace std;


int main() {
    int initialSize;
    cin>>initialSize;
    int *arr=(int *)calloc(initialSize, sizeof(int));

    for(int i=0;i<initialSize;i++) {
        cin>>arr[i];
    }

    for(int i=0;i<initialSize;i++) {
        cout<<arr[i]<<" ";
    }

}
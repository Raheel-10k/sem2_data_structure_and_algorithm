#include "iostream"
using namespace std;

void display(int *arr) {
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int *swap2Data(int *arr) {
    
}
int main() {
    int *arry=(int *)calloc(6,sizeof(int));
    display(arry);
    arry=swap2Data(arry);
}
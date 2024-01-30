#include "iostream"
using namespace std;

int main() {
    int rows, cols;
    cout<<"Enter number of rows and columns for the array: ";
    cin>>rows>>cols;
    int arr[rows][cols];
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            cin>>arr[i][j];
        }
    }//input

    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }//output
}
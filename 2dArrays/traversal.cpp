//WAP to calculate and display the sum and product of diagonal elements of 2d array. You must traverse through the array for this.

#include "iostream"
using namespace std;

int main() {
    int rows, cols;
    cin>>rows>>cols;
    int arr[rows][cols];
    for(int i=0; i<rows;i++) {
        for(int j=0;j<cols;j++) {
            cin>>arr[i][j];
        }
    }//array creation
    int sum=0, product=1;
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            if(i==j){
                sum+=arr[i][j];
                product*=arr[i][j];
            }
        }
    }
    cout<<sum<<endl<<product<<endl;

}
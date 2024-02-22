#include <iostream>
using namespace std;

void mergeArrays(int arr1[], int s1, int arr2[], int s2, int result[]) {
    int i=0,j=0,k=0;

    while(i<s1 && j<s2) {
        if(arr1[i]<=arr2[j]) {
            result[k++]=arr1[i++];
        }
        else {
            result[k++]=arr2[j++];
        }
    }

    while(i<s1) {
        result[k++]=arr1[i++];
    }

    while(j<s2) {
        result[k++]=arr2[j++];
    }
}

int main() {
    int arr1[]={1,3,5,7,3,5,6};
    int size1=sizeof(arr1)/sizeof(arr1[0]);

    int arr2[]={2,4,6,8};
    int size2=sizeof(arr2)/sizeof(arr2[0]);

    int resultSize=size1+size2;
    int* resultArray=new int[resultSize];

    mergeArrays(arr1,size1,arr2,size2,resultArray);

    cout<<"Merged and sorted array: ";
    for(int i=0;i<resultSize;++i) {
        cout<<resultArray[i]<<" ";
    }

    delete[] resultArray;

    return 0;
}

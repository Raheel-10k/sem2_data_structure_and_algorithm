#include "iostream"

using namespace std;

int* removeDuplicates(int inputArray[], int size, int& newSize) {
    newSize=0;

    for (int i=0;i<size;++i) {
        bool isUnique=true;
        for (int j=0;j<newSize;++j) {
            if (inputArray[i]==inputArray[j]) {
                isUnique=false;
                break;
            }
        }
        if(isUnique) {
            inputArray[newSize++]=inputArray[i];
        }
    }
    int* resultArray=new int[newSize];
    for (int i=0;i<newSize;++i) {
        resultArray[i]=inputArray[i];
    }

    return resultArray;
}

int main() {
    int inputArray[]={1,2,3,4,2,3,5,6,1};
    int size = sizeof(inputArray)/sizeof(inputArray[0]);

    int newSize;
    int* resultArray = removeDuplicates(inputArray, size, newSize);

    cout << "Array without duplicates: ";
    for (int i = 0; i < newSize; ++i) {
        cout << resultArray[i] << " ";
    }

    return 0;
}
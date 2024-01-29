#include <iostream>

using namespace std;

int binarySearch(int arr[], int low, int high, int search) {
    int mid=(low+high)/2;
    if(low>high){
        return -1;
    }
    else{
        if(arr[mid]==search) {
            return mid;
        }
        else if(arr[mid]<search) {
            return binarySearch(arr, (mid+1), high, search);
        }
        else {
            return binarySearch(arr, low, mid-1, search);
        }
    }
}

int main() {
    const int arraySize = 5;
    int sortedArray[arraySize] = {1, 2, 3, 4, 5};

    int search_value;
    cout << "Enter the search value value: ";
    cin >> search_value;

    int low = 0;
    int high = arraySize - 1;
    int result = -1;

    // while (low <= high) {
    //     int mid = (low + high) / 2;

    //     if (sortedArray[mid] == search_value) {
    //         result = mid;
    //         break;
    //     } else if (sortedArray[mid] < search_value) {
    //         low = mid + 1;
    //     } else {
    //         high = mid - 1;
    //     }
    // }

    // if (result != -1) {
    //     cout << "Element found at index: " << result << endl;
    // } else {
    //     cout << "Element not found in the array." << endl;
    // }

    cout<<binarySearch(sortedArray, low, high, search_value);

    return 0;
}

#include <iostream>
using namespace std;

void insertVal(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter value " << i << ": ";
        cin >> arr[i];
    }
}

void addToStart(int *arr, int &size, int value) {
    for (int i = size - 1; i >= 0; i--) {
        arr[i + 1] = arr[i];
    }
    arr[0] = value;
    size++;
}

void addToEnd(int *&arr, int &size, int value) {
    int *newArr = new int[size + 1];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    newArr[size] = value;
    delete[] arr;
    arr = newArr;
    size++;
}


void addToPosition(int *&arr, int &size, int value, int position) {
    int *newArr = new int[size + 1];
    for (int i = 0; i < position; i++) {
        newArr[i] = arr[i];
    }
    newArr[position] = value;
    for (int i = position + 1; i <= size; i++) {
        newArr[i] = arr[i - 1];
    }
    delete[] arr;
    arr = newArr;
    size++;
}

void addAfterValue(int *&arr, int &size, int value, int afterValue) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == afterValue) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Value not found in the array.\n";
        return;
    }
    int *newArr = new int[size + 1];
    for (int i = 0; i <= index; i++) {
        newArr[i] = arr[i];
    }
    newArr[index + 1] = value;
    for (int i = index + 2; i <= size + 1; i++) {
        newArr[i] = arr[i - 1];
    }
    delete[] arr;
    arr = newArr;
    size++;
}

void addBeforeValue(int *&arr, int &size, int value, int beforeValue) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == beforeValue) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Value not found in the array.\n";
        return;
    }
    int *newArr = new int[size + 1];
    for (int i = 0; i < index; i++) {
        newArr[i] = arr[i];
    }
    newArr[index] = value;

    for (int i = index + 1; i <= size; i++) {
        newArr[i] = arr[i - 1];
    }

    delete[] arr;
    arr = newArr;
    size++;
}

void deleteFirstValue(int *&arr, int &size) {
    if (size == 0) {
        cout << "Array is already empty.\n";
        return;
    }
    int *newArr = new int[size - 1];
    for (int i = 1; i < size; i++) {
        newArr[i - 1] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    size--;
}

void deleteLastValue(int *&arr, int &size) {
    if (size == 0) {
        cout << "Array is already empty.\n";
        return;
    }
    int *newArr = new int[size - 1];
    for (int i = 0; i < size - 1; i++) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    size--;
}

void deleteAtIndex(int *&arr, int &size, int index) {
    if (index < 0 || index >= size) {
        cout << "Invalid index.\n";
        return;
    }
    int *newArr = new int[size - 1];
    for (int i = 0; i < index; i++) {
        newArr[i] = arr[i];
    }
    for (int i = index + 1; i < size; i++) {
        newArr[i - 1] = arr[i];
    }

    delete[] arr;
    arr = newArr;
    size--;
}

void deleteByValue(int *&arr, int &size, int value) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        cout << "Value not found in the array.\n";
        return;
    }
    int *newArr = new int[size - 1];
    for (int i = 0; i < index; i++) {
        newArr[i] = arr[i];
    }
    for (int i = index + 1; i < size; i++) {
        newArr[i - 1] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    size--;
}

void deleteAfterValue(int *arr, int &size, int afterValue) {
    int index = -1;
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] == afterValue) {
            index = i;
            break;
        }
    }
    if (index == -1 || index == size - 1) {
        cout << "No value found after " << afterValue << " to delete.\n";
        return;
    }
    int *newArr = new int[size];
    for (int i = 0; i <= index; i++) {
        newArr[i] = arr[i];
    }
    for (int i = index + 2; i < size; i++) {
        newArr[i - 1] = arr[i];
    }

    delete[] arr;
    arr = newArr;
    size--;
} //**

void deleteBeforeValue(int *arr, int &size, int beforeValue) {
    int index = -1;
    for (int i = 1; i < size; i++) {
        if (arr[i] == beforeValue) {
            index = i;
            break;
        }
    }

    if (index == -1 || index == 0) {
        cout << "No value found before " << beforeValue << " to delete.\n";
        return;
    }
    int *newArr = new int[size];
    for (int i = 0; i < index; i++) {
        newArr[i] = arr[i];
    }
    for (int i = index + 1; i < size; i++) {
        newArr[i - 1] = arr[i];
    }

    delete[] arr;
    arr = newArr;
    size--;
}

void display(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int n;
    cout << "Enter initial size of array: ";
    cin >> n;

    int *arr = (int *)calloc(n, sizeof(int));
    cout<<"INITIAL VALUES:"<<endl;
    insertVal(arr, n);
    char choice;
    int val, key;
    do
    {
        cout<<"Enter value\n'1' for insertion, '2' for deletion and '3' for updation.";
        cin>>choice;
        switch (choice)
        {
        case '1':
            cout<<"Enter what type of insertion u want. '1' for at start of array, '2' for at end, '3' for at a particular location, '4' for a adding after value and '5' for adding before value: ";
            cin>>choice;
            switch (choice)
            {
            case '1':
                cout<<"Enter value to add: ";
                cin>>val;
                addToStart(arr, n, val);
                break;

            case '2':
                cout<<"Enter value to add: ";
                cin>>val;
                addToEnd(arr, n, val);
                break;

            case '3':
                cout<<"Enter value to add: ";
                cin>>val;
                cout<<"Enter position: ";
                cin>>key;
                addToPosition(arr, n, val, key);
                break;

            case '4':
                cout<<"Enter value to add: ";
                cin>>val;
                cout<<"Enter value after which you want to add: ";
                cin>>key;
                addAfterValue(arr, n, val, key);
                break;

            case '5':
                cout<<"Enter value to add: ";
                cin>>val;
                cout<<"Enter value after which you want to add: ";
                cin>>key;
                addBeforeValue(arr, n, val, key);
                break;
            
            default:
                cout<<"INVALID INPUT.";
                break;
            }
            break;

        case '2':
            cout<<"Enter '1' for deletion of particular index, '2' deletion of particular value, '3' deletion of value post known value, '4' deletion of value pre-known value, '5' deletion of start value, '6' deletion of end value: ";
            cin>>choice;
            switch (choice)
            {
            case '1':
                cout<<"Enter index to delete: ";
                cin>>key;
                deleteAtIndex(arr, n, key);
                break;

            case '2':
                cout<<"Enter value to delete: ";
                cin>>val;
                deleteByValue(arr, n, val);
                break;
            
            case '3':
                cout<<"Enter value to delete: ";
                cin>>val;
                deleteAfterValue(arr, n, val);
                break;

            case '4':
                cout<<"Enter value to delete: ";
                cin>>val;
                deleteBeforeValue(arr, n, val);
                break;
            
            case '5':
                cout<<"Enter value to delete: ";
                cin>>val;
                deleteFirstValue(arr, n);
                break;

            case '6':
                cout<<"Enter value to delete: ";
                cin>>val;
                deleteLastValue(arr, n);
                break;
            
            default:
                cout<<"INVALID INPUT";
                break;
            }
            break;

        case '3':
            display(arr, n);
            break;
        
        default:
            cout<<"INVALID INPUT";
            break;
        }
        cout<<"Press 'n' to end else any other button to continue: ";
        cin>>choice;
    } while (tolower(choice)!='n');
    


    return 0;
}

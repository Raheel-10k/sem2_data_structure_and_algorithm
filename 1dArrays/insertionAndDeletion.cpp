#include "iostream"
#include "algorithm"
using namespace std;

void insertAtBeginning() {
    int arr[100]={}, n;
    cout<<"Enter number of values to add initially: ";
    cin>>n;
    int val=0,i;
    for(i=0;i<n;i++) {
        cout<<"Enter initial value"<<i<<": ";
        cin>>val;
        arr[i]=val;
    }
    cout<<"OG array: "; 
    for(int j=0;j<n;j++){
        cout<<arr[j]<<" ";
    }
    cout<<endl;
    cout<<"Enter new data to add: ";
    cin>>val;
    while(i>=0) {
        arr[i+1]=arr[i];
        i--;
    }
    arr[0] = val;
    cout<<i<<endl;
    i=0;
    cout<<"Array after append: ";
    while(arr[i]!=0) {
        cout<<arr[i]<<" ";
        i++;
    }
    cout<<endl;
}

void insertValueAtEndForEndIsKnown() {
    int arr[100], n;
    fill_n(arr, 100, -1);
    cout<<"Enter number of values to add initially: ";
    cin>>n;
    int val=0,i=0;
    for(i=0;i<n;i++) {
        cout<<"Enter initial value"<<i<<": ";
        cin>>val;
        arr[i]=val;
    }
    cout<<i;
    cout<<"OG array: "; 
    for(int j=0;j<n;j++){
        cout<<arr[j]<<" ";
    }
    cout<<endl;
    cout<<"Enter new data to add: ";
    cin>>arr[i];
    cout<<arr[i];
    i=0;
    while(arr[i]!=-1) {
        cout<<arr[i];
        i++;
    }
}

void insertValueAtEndForEndIsUnknown() {
    int arr[100], n;
    fill_n(arr, 100, -1);
    cout<<"Enter number of values to add initially: ";
    cin>>n;
    int val=0,i;
    for(i=0;i<n;i++) {
        cout<<"Enter initial value"<<i<<": ";
        cin>>val;
        arr[i]=val;
    }
    int count=0;
    i=0;
    while(arr[i]!=-1) {
        count++;
        i++;
    }
    cout<<"Array has "<<count<<" elements."<<endl;
    cout<<"Enter value to add: ";
    cin>>val;
    arr[count+1]=val;
    i=0;
    cout<<"After inserting: "<<endl;
    while(arr[i]==-1) {
        cout<<arr[i];
        i++;
    }
}//where some data is already present and you are unaware of it.

void insertAtGivenLocation() {
    int arr[100], n;
    fill_n(arr, 100, -1);
    cout<<"Enter number of values to add initially: ";
    cin>>n;
    int val=0,i;
    for(i=0;i<n;i++) {
        cout<<"Enter initial value"<<i<<": ";
        cin>>val;
        arr[i]=val;
    }
    int count=0;
    i=0;
    while(arr[i]!=-1) {
        count++;
        i++;
    }
    int pos;
    cout<<"Enter position where you want to enter new value: ";
    cin>>pos;
    if(arr[pos]==-1) {
        cout<<"Enter value to add at this position: ";
        cin>>arr[pos];
    }
    else{
        for(i=count-1;i>=pos;i--) {
            arr[i+1]=arr[i];
        }
        count++;//as one new value added is known.
        cout<<"Enter value to add at this position: ";
        cin>>arr[pos];
    }

    for(int i=0;i<100;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void deletionViaParticularPosition() {
    int arr[100], n;
    fill_n(arr, 100, -1);
    cout<<"Enter number of values to add initially: ";
    cin>>n;
    int val=0;
    for(int i=0;i<n;i++) {
        cout<<"Enter initial value"<<i<<": ";
        cin>>val;
        arr[i]=val;
    }
    cout<<"OG array: "; 
    for(int j=0;j<n;j++){
        cout<<arr[j]<<" ";
    }
    int pos;
    cout<<"Enter position to delete: ";
    cin>>pos;

    for(int i=pos;i<=n-1;i++) {
        arr[i]=arr[i+1];
    }

    cout<<"Array post-deletion: "; 
    for(int j=0;j<n && arr[j]!=-1;j++){
        cout<<arr[j]<<" ";
    }
    cout<<endl;
}

int main() {
    //insertAtBeginning();
    //insertValueAtEndForEndIsKnown();
    //insertValueAtEndForEndIsUnknown();
    //insertAtGivenLocation();
    deletionViaParticularPosition();
    return 0;
}
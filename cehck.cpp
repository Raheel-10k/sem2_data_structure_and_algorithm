#include "iostream"
using namespace std;

int checkfunc(int *ptr) {
    return *ptr+10;
}

int main() {
    int a=0;
    cout<<checkfunc(&a)<<endl;
    cout<<a;
}
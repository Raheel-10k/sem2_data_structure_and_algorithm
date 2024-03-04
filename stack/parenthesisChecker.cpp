#include "iostream"
using namespace std;

class Stack {
    private:
        static const int MAX_SIZE = 100;
        char stack[MAX_SIZE];
        int top;

    public:
        Stack() : top(-1) {}

        void push(char value) {
            if (top < MAX_SIZE - 1) {
                top++;
                stack[top] = value;
                cout << "Pushed: " << value << endl;
            } else {
                cout << "Error: Stack overflow. Cannot push " << value << "." << endl;
            }
        }

        int check(char closing) {
            if(stack[top]==closing) {
                cout<<stack[top]<<"\t"<<closing;
                top=top-1;
                return -1;
            }
            top=top-1;
            return 0;
        }

        void display() {
            cout << "Stack: ";
            for (int i = 0; i <= top; ++i) {
                cout << stack[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    string expersion;
    cout<<"Enter operation: ";
    cin>>expersion;
    Stack stack;
    for(int i=0; i<(sizeof(expersion)/sizeof(expersion[0])); i++) {
        if(expersion[i]=='{' || expersion[i]=='(' || expersion[i]=='[') {
            stack.push(expersion[i]);
        }
    }//all opening brackets pushed to array
    stack.display();
    int flag;
    for(int i=0; i<(sizeof(expersion)/sizeof(expersion[0])); i++) {
        if(expersion[i]=='}' || expersion[i]==')' || expersion[i]==']') {
            flag=stack.check(expersion[i]);
        }
    }

    if(flag=0) {
        cout<<"Valid Exp";
    }
    else {
        cout<<"Invalid Exp";
    }
    return 0;
}
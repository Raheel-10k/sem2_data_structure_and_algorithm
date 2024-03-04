#include "iostream"
using namespace std;

class Stack {
    private:
        static const int MAX_SIZE = 7;
        int stack[MAX_SIZE];
        int top;

    public:
        Stack() : top(-1) {}

        void push(int value) {
            if (top < MAX_SIZE - 1) {
                top++;
                stack[top] = value;
                cout << "Pushed: " << value << endl;
            } else {
                cout << "Error: Stack overflow. Cannot push " << value << "." << endl;
            }
        }

        int peek(Stack st) {
            if(top==-1) {
                return -1;
            }
            else {
                return stack[top--];
            }
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
    int a=0;
    char ch;
    Stack stack;
    do
    {
        cout<<"Enter int value: ";
        cin>>a;
        stack.push(a);
        cout<<"Press y to continue else anything to exit: ";
        cin>>ch;
    } while (tolower(ch)=='y');     //initial stack created.

    cout<<"Initial stack: \n";
    
    stack.display();
    

    
    return 0;
}
#include <iostream>

using namespace std;
#define MAX_SIZE 10


class Stack {
private:
    int stack[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1; // Initializing top of stack to -1
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == MAX_SIZE - 1);
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow" << endl;
        } else {
            top++;
            stack[top] = value;
            cout << value << " pushed into the stack" << endl;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
        } else {
            cout << stack[top] << " popped from the stack" << endl;
            top--;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Elements in the stack are: ";
            for (int i = 0; i <= top; i++) {
                cout << stack[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack myStack;

    myStack.push(5);
    myStack.push(10);
    myStack.push(15);

    myStack.display();

    myStack.pop();
    myStack.display();

    return 0;
}

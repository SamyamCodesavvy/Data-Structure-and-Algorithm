#include <iostream>
#include <cstring>

#define MAX_SIZE 100 // Define maximum size of the stack

using namespace std;

class Stack {
private:
    int top; // Index for the top element
    char arr[MAX_SIZE]; // Array to store stack elements

public:
    Stack() {
        top = -1; // Initializing the stack
    }

    bool isEmpty() {
        return (top == -1); // Check if the stack is empty
    }

    bool isFull() {
        return (top == MAX_SIZE - 1); // Check if the stack is full
    }

    void push(char val) {
        if (isFull()) {
            cout << "Stack Overflow..." << endl;
            return;
        }
        arr[++top] = val; // Increment top and add element to the stack
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow..." << endl;
            return '\0'; // Return null character or handle error as needed
        }
        char poppedElement = arr[top--]; // Get the element and decrement top
        return poppedElement;
    }

    char peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return '\0'; // Return null character or handle error as needed
        }
        return arr[top]; // Return the top element without removing it
    }
};

// Function to check if a given character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to get the precedence of an operator
int getPrecedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1; // For '(' and ')'
}

// Function to convert infix expression to postfix expression
string infixToPostfix(string expression) {
    Stack stk;
    string postfix = "";
    stk.push('('); // Step 1: Push '(' onto stack
    expression += ')'; // Step 1: Add ')' to the end of the expression

    for (char& c : expression) {
        if (c == ' ')
            continue;
        else if (isalnum(c)) // Step 3: If operand, add it to postfix
            postfix += c;
        else if (c == '(') // Step 4: If '(' push onto stack
            stk.push(c);
        else if (isOperator(c)) { // Step 5: If operator
            while (getPrecedence(c) <= getPrecedence(stk.peek())) {
                postfix += stk.pop();
            }
            stk.push(c);
        } else if (c == ')') { // Step 6: If ')'
            while (stk.peek() != '(') {
                postfix += stk.pop();
            }
            stk.pop(); // Remove '('
        }
    }

    return postfix;
}

int main() {
    string infixExpression = "A+(B*C-(D/E^F)*G)*H";
    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Infix Expression: " << infixExpression << endl;
    cout << "Postfix Expression: " << postfixExpression << endl;

    return 0;
}

#include <iostream>
using namespace std;

#define size 10

class convert {
    int a[size];
    int top, count; // Changed the declaration of 'count' in the class

public:
    convert() {
        top = -1;
        count = 0; // Initialize count in the constructor
    }

    bool isEmpty();
    bool isFull();
    void push(int);
    void pop();
};

bool convert::isEmpty() {
    return top == -1;
}

bool convert::isFull() {
    return top == size - 1;
}

void convert::push(int x) {
    int rem = 0;
    if (isFull()) {
        cout << "Stack Overflow..." << endl;
    } else {
        while (x > 0) {
            rem = x % 2;
            x = x / 2;
            a[++top] = rem;
            count++;
        }
    }
}

void convert::pop() {
    if (isEmpty()) {
        cout << "Stack Underflow..." << endl;
    } else {
        cout << "The binary equivalent value is..." << endl;
        while (count > 0) {
            cout << a[top--];
            count--;
        }
    }
}

int main() {
    convert deci;
    int decimal_num;
    cout << "Enter decimal number to find binary..." << endl;
    cin >> decimal_num;
    deci.push(decimal_num);
    deci.pop();
    return 0;
}

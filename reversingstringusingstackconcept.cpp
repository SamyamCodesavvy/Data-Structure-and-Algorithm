#include <iostream>
#include <string>
using namespace std;
const int MAX_SIZE = 10;
class ReverseString {
private:
    char array[MAX_SIZE];
    int top;
public:
    ReverseString()
    {
        top = -1;
    }
    void push(char ch);
    char pop();
    bool isEmpty();
};
void ReverseString::push(char ch) {
    if (top == MAX_SIZE - 1) 
    {
        cout << "Stack Overflow..." << endl;
    } 
    else 
    {
        array[++top] = ch;
    }
}
char ReverseString::pop() {
    if (isEmpty()) 
    {
        cout << "Stack Underflow..." << endl;
        return 0;
    } 
    else 
    {
        char popped = array[top--];
        return popped;
    }
}
bool ReverseString::isEmpty()
{
    return (top == -1);
}
int main() {
    ReverseString str;
    string inputString;
    cout << "Enter a string to reverse: ";
    cin >> inputString;
    for (int i = 0; i < inputString.length(); i++) 
    {
        str.push(inputString[i]);
    }
    string reversed_string;
    while (!str.isEmpty()) 
    {
        reversed_string += str.pop();
    }
    cout << "The reversed string is: " << reversed_string << endl;
    return 0;
}

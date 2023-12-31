#include <iostream>
#define MaxSize 10

using namespace std;

class Queue {
private:
    int front, rear;
    int queue[MaxSize];

public:
    Queue() {
        front = rear = -1;
    }

    bool isFull() {
        return rear == MaxSize - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue overflow" << endl;
            return;
        }

        if (front == -1) {
            front = 0;
        }

        rear++;
        queue[rear] = item;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow" << endl;
            return;
        }

        cout << "Element dequeued from queue: " << queue[front] << endl;
        front++;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue(); // This will cause underflow

    return 0;
}

#include <iostream>
#define MAX 5

using namespace std;

class CircularQueue {
private:
    int front, rear;
    int cqueue[MAX];

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
            return true;
        return false;
    }

    bool isEmpty() {
        if (front == -1)
            return true;
        return false;
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue Overflow" << endl;
            return;
        } else {
            if (front == -1)
                front = 0;
            rear = (rear + 1) % MAX;
            cqueue[rear] = item;
            cout << "Inserted " << item << " into the queue" << endl;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return;
        } else {
            cout << "Element deleted from queue is " << cqueue[front] << endl;
            if (front == rear) {
                front = -1;
                rear = -1;
            } else {
                front = (front + 1) % MAX;
            }
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        } else {
            int i = front;
            cout << "Elements in the queue are: ";
            do {
                cout << cqueue[i] << " ";
                i = (i + 1) % MAX;
            } while (i != (rear + 1) % MAX);
            cout << endl;
        }
    }
};

int main() {
    CircularQueue cq;

    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.enqueue(4);
    cq.enqueue(5);

    cq.display();

    cq.enqueue(6); // Queue overflow

    cq.dequeue();
    cq.dequeue();

    cq.display();

    cq.enqueue(7);
    cq.enqueue(8);

    cq.display();

    return 0;
}

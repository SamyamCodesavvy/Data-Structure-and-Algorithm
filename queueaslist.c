#include <stdio.h>
#include <stdlib.h>

#define max 100
#define TRUE 1
#define FALSE 0

struct nodetype {
    int info, next;
};
struct nodetype node[max];

int avail;
void initializeList() {
    int i;
    avail = 0;
    for (i = 0; i < max - 1; i++) {
        node[i].next = i + 1;
    }
    node[max - 1].next = -1;
}

int getnode() {
    int p;
    if (avail == -1) {
        printf("Overflow\n");
        exit(1);
    } else {
        p = avail;
        avail = node[avail].next;
        return p;
    }
}

void freenode(int p) {
    node[p].next = -1;
    avail = p;
}

struct queue {
    int front, rear;
};
struct queue q;

int empty(struct queue *pq) {
    return ((pq->front == -1) ? TRUE : FALSE);
}

void insert(struct queue *pq, int data) {
    int p;
    p = getnode();
    node[p].info = data;
    node[p].next = -1;
    if (pq->rear == -1) {
        pq->front = p;
        pq->rear = p;
    } else {
        node[pq->rear].next = p;
        pq->rear = p;
    }
}

int removeData(struct queue *pq) {
    int p, data;
    if (empty(pq)) {
        printf("Underflow\n");
        exit(1);
    }
    p = pq->front;
    data = node[p].info;
    pq->front = node[p].next;
    if (pq->front == -1) {
        pq->rear = -1;
    }
    freenode(p);
    return data;
}

void display(struct queue *pq) {
    if (empty(pq)) {
        printf("Queue is empty.\n");
        return;
    }

    int current = pq->front;
    printf("Queue: ");
    while (current != -1) {
        printf("%d ", node[current].info);
        current = node[current].next;
    }
    printf("\n");
}

int main() {
    initializeList();
    q.front = q.rear = -1;

    insert(&q, 10);
    display(&q);
    insert(&q, 20);
    display(&q);
    insert(&q, 30);
    display(&q);

    printf("Removed element: %d\n", removeData(&q));
    display(&q);
    printf("Removed element: %d\n", removeData(&q));
    display(&q);
    printf("Removed element: %d\n", removeData(&q));
    display(&q);

    return 0;
}

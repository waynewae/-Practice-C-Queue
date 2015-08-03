#include<stdio.h>
#include<stdlib.h>

#define QUEUESIZE 2

typedef struct {
	int data[QUEUESIZE];
	int* front;
	int* rear;
}Queue;

Queue queue;

//void initialQueue(Queue* queue) {
void initialQueue() {
	int i;

	for(i = 0 ; i < QUEUESIZE ; i++) queue.data[i] = 0;
	printf("initial data array, &data = %p\n", &queue.data);
	queue.front = queue.data;
	printf("initial front, &front = %p\n", queue.front);
	queue.rear = queue.data;
	printf("initial rear, &rear = %p\n", queue.rear);
}

void pushQueue(int input) {
	if(queue.rear == &queue.data[QUEUESIZE]) printf("Queue is full\n");
	else {
		*queue.rear = input;
		printf("insert the data : %d, location : %p\n", *queue.rear, queue.rear);
		queue.rear++;
	}
}

void popQueue() {
	int *tmp = queue.front;
	if(queue.front == queue.rear) printf("Queue is empty\n");
	else {
		printf("pop the data of front : %d, location : %p\n", *queue.front, queue.front);
		while(tmp != queue.rear) {
			*tmp = *(tmp+1);
			tmp++;
		}
		queue.rear--;
	}
}

int main() {
	initialQueue();
	pushQueue(10);
	pushQueue(8);
	pushQueue(12);
	popQueue();
	popQueue();
	popQueue();
	return 0;
}

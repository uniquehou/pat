#include <stdio.h>
#include <malloc.h>

#define null -101
struct Queue {
	char *data;
	int size;
	int front;
};
typedef struct Queue *Queue;

Queue CreateQueue() {
	Queue Q = (Queue)malloc(sizeof(struct Queue));
	Q->data = (char*)calloc(1000, sizeof(char));
	Q->size = 0;
	Q->front = 0;
	return Q;
}

void AddQ(Queue Q, char item) {
	Q->data[Q->size++]=item;
}

int DeleteQ(Queue Q) {
	if (Q->front != Q->size) {
		return Q->data[Q->front++]-'0';
	}
	else
		return null;
}

int main() {
	Queue Q = CreateQueue();
	char ch;
	while((ch=getchar())!=' ')
		AddQ(Q, ch);
	ch=getchar();   getchar();

	Queue result = CreateQueue();
	int temp = DeleteQ(Q);
	temp=temp*10 + DeleteQ(Q);
	if (temp<0) {
		temp = (temp-null)/10;
		int b = ch-'0';
		printf("%d %d\n", temp/b, temp%b);
		return 0;
	} else {
		while( temp>=0) {
			AddQ(result, (int)(temp/(ch-'0'))+'0');
			temp %= (ch-'0');
			temp=temp*10 + DeleteQ(Q);
		}
	}

	int a;
	if (result->front == result->size)
		printf("0");
	else
		while( (a=DeleteQ(result)) != null )
			printf("%d", a);
	printf(" %d\n", (temp-null)/10);
	return 0;
}
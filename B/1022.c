#include <stdio.h>
#include <malloc.h>

struct Stack {
	int *data;
	int front, rear;
	int size;
};
typedef struct Stack *Stack;

Stack CreateStack() {
	Stack S = (Stack)malloc(sizeof(struct Stack));
	S->data = (int*)calloc(100, sizeof(int));
	S->front = S->rear = 0;
	S->size = 0;
	return S;
}

void AddQ(Stack S, int item) {
	if (S->rear+1 == S->size) {
		S->data = realloc(S->data, (S->size+10)*sizeof(int));
		S->size += 10;
	}
	S->data[S->rear++] = item;
}

int Delete(Stack S) {
	return S->data[--S->rear];
}
int main() {
	int a, b, d;
	Stack S = CreateStack();
	scanf("%d %d %d", &a, &b, &d);
	int sum = a+b;
	AddQ(S, sum%d);
	for(sum/=d; sum; sum/=d) {
		AddQ(S, sum%d);
	}
	while(S->front!=S->rear)
		printf("%d", Delete(S));
	printf("\n");
}
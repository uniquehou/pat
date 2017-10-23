// 差5分，运行超时
#include <stdio.h>
#include <malloc.h>

struct LinkList {
	int data;
	struct LinkList *next;
};
typedef struct LinkList *LinkList;

LinkList CreateLinkList() {
	LinkList L= (LinkList)malloc(sizeof(struct LinkList));
	L->next = 0;
	return L;
}

void Insert(LinkList L, int data) {
	LinkList temp = CreateLinkList();
	temp->data = data;
	for(; L->next; L=L->next)
		if (L->next->data>data)
			break;
	temp->next = L->next;
	L->next = temp;
}

int main() {
	int n;
	int data[100000];
	LinkList result = CreateLinkList();
	int size=0;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &data[i]);

	for(int i=0; i<n; i++) {
		int flag=0;
		for(int j=i+1; j<n; j++)
			if (data[j]<data[i])
				{ flag=1; break; }

		for(int j=i-1; j>=0 && !flag; j--)
			if (data[j]>data[i])
				{ flag=1; break; }

		if (!flag) {
			Insert(result, data[i]);
			size++;
		}
	}

	printf("%d\n", size);
	for(LinkList temp=result->next; temp; temp=temp->next) {
		printf("%d", temp->data);
		if (temp->next)
			printf(" ");
	}
	printf("\n");
	return 0;
}
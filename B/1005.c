#include <stdio.h>
#include <malloc.h>

struct LinkList {
	int data;
	struct LinkList *next;
};
typedef struct LinkList *LinkList;

LinkList CreateLinkList() {
	LinkList L = (LinkList)malloc(sizeof(struct LinkList));
	L->next->next = 0;
	return L;
}

int find(LinkList L, int data) {
	int i=1;
	for(LinkList temp = L->next; temp; temp=temp->next) {
		if (temp->data == data)
			return i;
		i++;
	}
	return 0;
}

// 在 m 前插入 old
void InsertList(LinkList des, int m, LinkList old) {
	for(int i=1; i<m; i++)
		des=des->next;
	old->next = des->next;
	des->next = old;
}

void InsertData(LinkList L, int data) {
	LinkList temp = CreateLinkList();
	L->data = data;
	while(L->next)
		L=L->next;
	L->next = temp;
}

int GetNext(int data) {
	return data%2? (3*data+1)/2: data/2;
}

int main() {
	int count;
	scanf("%d", &count);
	LinkList L[100];
	int index=0;
	for(int i=0; i<count; i++) {
		int flag=0, data;
		scanf("%d", &data); 
		int NextData = data;

		LinkList temp = CreateLinkList();
		printf("abc\n");
		InsertData(temp, NextData);
		for(NextData=data; NextData!=1; NextData=GetNext(NextData)) {
			for(int k=0; k<index; k++) {
				int m = find(L[k], NextData);
				if (m) {
					InsertList(L[k], m, temp);
					flag = 1;
					break;
				}
			}
			if (flag)  break;
			InsertData(temp, NextData);
			printf("Insert data: %d\n", NextData);
		}

		if (!flag) {
			L[index++] = temp;
			printf("Add new LinkList: %d\n", temp->next->data);
		}
	}

	printf("%d\n", index);
	for(int i=0; i<index; i++) {
		printf("%d", L[i]->next->data);
		if (i!=index-1)
			putchar(' ');
	}
	printf("\n");
	return 0;
}

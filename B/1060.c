// 差12分
#include <stdio.h>
#include <malloc.h>

struct LinkList {
	int data;
	int count;
	struct LinkList *next;
};
typedef struct LinkList *LinkList;

LinkList CreateLinkList() {
	LinkList L = (LinkList)malloc(sizeof(struct LinkList));
	L->next = 0;
	return L;
}

// 读入数据，若为新数据，插入并返回1；若已存在，L->count++并返回0
int InsertLinkList(LinkList L, int data) {
	LinkList temp = CreateLinkList();
	temp->data = data;
	temp->count=1;
	for(; L->next; L=L->next)
		if (data<L->next->data) {
			if (data==L->data) {
				L->count++;
				return 0;
			}
			else {
				temp->next = L->next;
				L->next = temp;
				return 1;
			}
		}
	L->next = temp;
	return 1;
}

int main() {
	int n;
	scanf("%d", &n);
	LinkList L = CreateLinkList();
	for(int i=0; i<n; i++) {
		int num;
		scanf("%d", &num);
		InsertLinkList(L, num);
	}

	int data[100001][2];    // 将所有数据提取，并存储至数组中
	int index=0;
	for(L=L->next; L; L=L->next) {
		data[index][0] = L->data;     // 0存储英里数
		data[index][1] = L->count;    // 1存储次数
		index++;
	}

	int count=0;                     // 从后向前的总次数
	for(int i=index-1; i>=0; i--) {
		if (data[i][0] == count) {
			printf("%d\n", count);
			break;
		}
		count += data[i][1];
	}
	return 0;
}
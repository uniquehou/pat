#include <stdio.h>
#include <malloc.h>

struct LinkList{
	int data[3];
	struct LinkList *next;
};
typedef struct LinkList *LinkList;

LinkList CreateLinkList() {
	LinkList L = (LinkList)malloc(sizeof(struct LinkList));
	L->next = 0;
	return L;
}

void Insert(LinkList L, int item[3]) {
	LinkList temp = CreateLinkList();
	for(int i=0; i<3; i++)
		temp->data[i] = item[i];
	for(; L->next; L=L->next);
	L->next = temp;
}

int main() {
	int data[100000][3];
	int start, n, k;
	scanf("%d %d %d", &start, &n, &k);
	LinkList buffer = CreateLinkList();
	int data_index=0;
	for(int i=0; i<n; i++) {
		int TmpStart, TmpData, TmpEnd;
		scanf("%d %d %d", &TmpStart, &TmpData, &TmpEnd);

		if (start == TmpStart) {
			data[data_index][0] = TmpStart;
			data[data_index][1] = TmpData;
			data[data_index][2] = TmpEnd;
			data_index++;
			start = TmpEnd;
			// 依次遍历缓存，看是否已存下一结点
			for(LinkList temp = buffer; temp->next;) {
				if (temp->next->data[0] == start) {
					for(int j=0; j<3; j++)
						data[data_index][j] = temp->next->data[j];
					data_index++;
					start = temp->next->data[2];      // 重置 start
					temp->next = temp->next->next;    // 删除此结点
					temp = buffer;                    // 重新开始遍历
				} else {
					temp=temp->next;
				}
			}
		} else {
			int TmpDataArray[3] = {TmpStart, TmpData, TmpEnd};
			Insert(buffer, TmpDataArray);
		}
	}

	int i;
	for(i=0; i+k-1<data_index; i+=k) {
		for(int j=k-1; j>=0; j--) {
			if (i+k==data_index && j==0)            // 最后一个结点
				printf("%05d %d %d\n", data[i+j][0], data[i+j][1], -1);
			else if (j==0)
				if (i+k+k-1<data_index)
					printf("%05d %d %05d\n", data[i+j][0], data[i+j][1], data[i+k+k-1][0]);
				else
					printf("%05d %d %05d\n", data[i+j][0], data[i+j][1], data[i+k][0]);
			else
				printf("%05d %d %05d\n", data[i+j][0], data[i+j][1], data[i+j-1][0]);
		}
	}
	if (i!=data_index-1)
		for(; i<data_index; i++)
			if (i==data_index-1)            // 最后一个结点
				printf("%05d %d %d\n", data[i][0], data[i][1], -1);
			else
				printf("%05d %d %05d\n", data[i][0], data[i][1], data[i+1][0]);
	return 0;
}
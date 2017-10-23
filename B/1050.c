// 差2分，运行超时
#include <stdio.h>
#include <malloc.h>
#include <math.h>

struct SqList {
	int *data;
	int size;    // 现在数据的长度
};
typedef struct SqList *SqList;

int isInt(int m, int count) {
	return (float)count/m == count/m;
}

int main() {
	int count, m, n;
	scanf("%d", &count);
	// 创建顺序表
	SqList L = (SqList)malloc(sizeof(struct SqList));
	L->data = (int*)calloc(count, sizeof(int));
	L->size = 0;
	// 读入数据
	for(int i=0; i<count; i++)
		scanf("%d", &(L->data[L->size++]));

	// 计算 m,n
	n = (int)sqrt(count);
	for(; !isInt(n, count); n--);
	m = count / n;
	int row=m, col=n;

	// 排序
	for(int i=0; i<count-1; i++) {
		int max = i;
		for(int j=i+1; j<count; j++)
			if ( L->data[max] < L->data[j] )
				max = j;
		// swap
		if (i!=max) {
			L->data[i] ^= L->data[max];
			L->data[max] ^= L->data[i];
			L->data[i] ^= L->data[max];
		}
	}

	// 组建螺旋矩阵
	int *data = (int*)calloc(count, sizeof(int));
	int j, k;
	int start_j=0, start_k=0;
	int index = 0;
	while( j!=m && k!=n && index<count) {
		j = start_j;
		k = start_k;

		for(; k<n; k++) {
			data[j*col+k] = L->data[index++];
		}
		k--;
		for(j++; j<m; j++) {
			data[j*col+k] = L->data[index++];
		}
		j--;
		for(k--; k>=start_k; k--) {
			data[j*col+k] = L->data[index++];
		}
		k++;
		if (index<count)
			for(j--; j>start_j; j--) {
				data[j*col+k] = L->data[index++];
			}

		start_j++;
		start_k++;
		m--;
		n--;
	}

	// 输出螺旋矩阵
	for(j=0; j<row; j++) {
		for(k=0; k<col; k++) {
			printf("%d", data[j*col+k]);
			if (k!=col-1)  putchar(' ');
		}
		printf("\n");
	}
	return 0;
}
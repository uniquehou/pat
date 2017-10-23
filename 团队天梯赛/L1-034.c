#include <stdio.h>

int max=0;
int array[10000], count[10000];
int index=0;

void fun(int numble) {
	int flag = 1;
	for(int i=0; i<index; i++){
		if (array[i] == numble) {
			count[i]++;
			if (count[i] >= count[max]) {
				if (count[i] > count[max])	max = i;
				if (count[i] == count[max]) max = array[i]>array[max]? i: max;
			flag = 0;
			break;
			}
		}
	}
	if (flag) {
		array[index] = numble;
		count[index] = 1;
		index++;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		int temp_n, temp_num;
		scanf("%d", &temp_n);
		for(int i=0; i<temp_n; i++){
			scanf("%d", &temp_num);
			fun(temp_num);
		}
	}
	printf("%d %d\n", array[max], count[max]);
	// for(int i=0; i<index; i++) printf("%3d ", array[i]);  printf("\n");
	// for(int i=0; i<index; i++) printf("%3d ", count[i]);  printf("\n");
}
// 差一分，无力了
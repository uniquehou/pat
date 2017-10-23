#include <stdio.h>

// 判断，甲输返回1，乙输返回2
int juice(int a[2], int b[2]) {
	int sum = a[0] + b[0];
	if (a[1]-sum==0 && b[1]-sum!=0)
		return 2;
	else if (a[1]-sum!=0 && b[1]-sum==0)
		return 1;
	else
		return 0;
}

int main() {
	int a[100][2], b[100][2];
	int n;
	int count[3] = {0};    // 存储甲乙的喝酒数，【1】为甲，【2】为乙
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d %d", &a[i][0], &a[i][1]);
		scanf("%d %d", &b[i][0], &b[i][1]);
	}

	for(int i=0; i<n; i++) {
		int flag = juice(a[i], b[i]);
		if (flag)  count[flag]++;
	}
	printf("%d %d\n", count[1], count[2]);
}
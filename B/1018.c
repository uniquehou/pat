// 差四分
#include <stdio.h>
#include <malloc.h>

int win(char a, char b) {
	int c = a - b;
	if (c<0 || c==8)    // 甲胜
		return 0;
	else if (c==0)
		return 2;
	else
		return 1;
}

int main() {
	int n;
	int result[3]={0,0,0};    // 三个数分别为甲胜、负、平的次数
	int log[2][10]={ {0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}};    // 横向表示甲乙，纵向表示布、锤子、剪刀
	char alpha[2];
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		getchar();    // 接收上一行的换行符
		scanf("%c %c", alpha, &alpha[1]);
		int index = win(alpha[0], alpha[1]);
		result[index]++;
		log[index][alpha[index]-'A']++;
		printf("log[%d][%d]=%d\n", index, alpha[index]-'A', log[index][alpha[index]-'A']);
	}
	n -= result[2];
	printf("%d %d %d\n", result[0], result[2], result[1]);
	printf("%d %d %d\n", n-result[0], result[2], n-result[1]);
	for(int i=0; i<2; i++) {
		int max=1;
		for(int j=2; j<10; j++) {
			if (j>3 && j!=9)
				continue;
			if (log[i][j]>log[i][max])
				max = j;
		}
		alpha[i] = 'A'+max;     // 使用 alpha 存储获胜最多的手势
	}
	printf("%c %c\n", alpha[0], alpha[1]);
}
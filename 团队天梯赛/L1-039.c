// 总体思想：先补齐再输出。最后一列先以空格补齐N个，再依次倒序输出
#include <stdio.h>
#include <string.h>
int main() {
	int n;
	char str[1100];
	scanf("%d", &n); getchar();
	gets(str);
	int len = strlen(str);
	if (len%n)
		for(int i=0; i<n-len%n; i++) strcat(str, " ");
	len = strlen(str);
	for(int j=0; j<n; j++) {
		for(int i=len-n+j; i>=0; i-=n)
			printf("%c", str[i]);
		printf("\n");
	}
	return 0;
}
// 少7分
#include <stdio.h>

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	int sum = a+b;
	int flag = sum>=0? 0:1;   // sum 是否为负
	if (sum<0)  sum=-sum;

	char str[20];
	int index=0;
	for(int i=1; 1; i++) {
		str[index++] = sum%10 + '0';
		sum /= 10;
		if (sum<=0)
			break;
		if (i%3==0 && i>=3)
			str[index++] = ',';
	}
	if(flag) str[index++] = '-';

	for(int i=index-1; i>=0; i--)
		putchar(str[i]);
	printf("\n");
}
#include <stdio.h>
int main() {
	int start, end;
	scanf("%d %d", &start, &end);
	int sum = (end-start)/100.0+0.5;
	int s = sum%60;
	sum /= 60;
	int m = sum%60;
	sum /= 60;
	int h = sum;
	printf("%02d:%02d:%02d\n", h, m, s);
	return 0;
}\
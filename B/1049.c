// 差5分
#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	float data[100000], sum;
	int count=n;
	for(int i=0; i<n; i++) {
		scanf("%f", &data[i]);
		int num = 0;
		num += count;
		num += i*count;
		sum += num * data[i];
		count--;
	}
	
	printf("%.2f\n", sum);
	return 0;
}
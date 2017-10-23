#include <stdio.h>
#define N 4  // 年龄位数
int len_set(int numble){
	int num[N];
	for(int i=N-1; i<=0; i--){
		num[i] = numble % 10;
		numble = (int)numble/10;
	}
	int len = N;
	for(int i=0; i<N-1; i++){
		if (num[i]==0) continue;
		for(int j=i+1; j<N; j++){
			len -= (num[i] == num[j]);
		}
	}
	return len;
}
int main() {
	int a, n, result = 0;
	// scanf("%d %d", &a, &n);
	a = 1988, n=4;
	for(result = a; len_set(result) == n; result++);
	printf("%d %d\n", result, result-a);
	return 0;
}
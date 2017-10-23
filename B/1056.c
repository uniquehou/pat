#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	int sum=0;
	for(int i=0; i<n; i++) {
		int num;
		scanf("%d", &num);
		sum += num;
	}
	printf("%d\n", 11*(sum*(n-1)));
	return 0;
}
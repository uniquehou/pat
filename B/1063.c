#include <stdio.h>
#include <math.h>
int main() {
	float max=0;
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		int a,b;
		scanf("%d %d", &a, &b);
		if (max < sqrt(a*a+b*b))
			max = sqrt(a*a + b*b);
	}
	printf("%.2f\n", max);
	return 0;
}
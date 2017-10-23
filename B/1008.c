#include <stdio.h>
int main() {
	int n, m, data[100];
	scanf("%d %d", &n, &m);
	m = m%n;
	for(int i=0; i<n; i++)
		scanf("%d", &data[i]);

	for(int i=n-m; i<n; i++) {
		printf("%d", data[i]);
		if (!(n==m && i==n-1))
			putchar(' ');
	}
	for(int i=0; i<n-m; i++) {
		printf("%d", data[i]);
		if (i!=n-m-1)
			putchar(' ');
	}
	printf("\n");
	return 0;
}
#include <stdio.h>
int main() {
	int n;
	char ch;
	scanf("%d %c", &n, &ch);

	for(int i=0; i<n; i++)
		putchar(ch);
	printf("\n");
	for(int i=0; i<(int)((float)n/2+0.5)-2; i++) {
		putchar(ch);
		for(int j=0; j<n-2; j++)
			putchar(' ');
		printf("%c\n", ch);
	}
	for(int i=0; i<n; i++)
		putchar(ch);
	printf("\n");
	return 0;
}
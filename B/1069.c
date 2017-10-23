#include <stdio.h>
#include <string.h>

int main() {
	char names[1000][21], name[21];
	int m, n, s, index=0;
	scanf("%d %d %d", &m, &n, &s);
	getchar();

	for(int i=0; i<n; i++)
		gets(name);
	strcpy(names[index++], name);

	for(int i=0; )
}
#include <stdio.h>
#include <string.h>

int main() {
	char str[80];
	gets(str);
	char words[80][80];
	int index=0;
	for(int i=0; i<strlen(str); i++) {
		int j;
		for(j=0; str[i]!=' ' && str[i]!='\0'; j++) {
			words[index][j] = str[i++];
		}
		words[index++][j] = '\0';
	}
	for(int i=index-1; i>=0; i--) {
		printf("%s", words[i]);
		if (i)
			putchar(' ');
	}
	printf("\n");
	return 0;
}
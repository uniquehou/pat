#include <stdio.h>
#include <string.h>

int main() {
	char words[81];
	gets(words);
	int n1, n2, length=strlen(words);
	n2 = length%2? 3: 4;
	for(; n2<length; n2+=2) {
		n1 = (length-n2)/2 + 1;
		if (n1<=n2)
			break;
	}

	int i,j;
	for(i=0; i<n1-1; i++) {
		j = length-i-1;
		putchar(words[i]);
		for(int k=0; k<n2-2; k++)
			putchar(' ');
		putchar(words[j]);
		printf("\n");
	}
	while(i<j)
		putchar(words[i++]);
	printf("\n");
}
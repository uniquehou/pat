#include <stdio.h>

int main() {
	int ch[255] = {0};
	char bad[255];
	gets(bad);
	for(int i=0; bad[i]!='\0'; i++) {
		if (bad[i]=='+') 
			for(int j='A'; j<='Z'; j++)
				ch[j] = 1;
		else if (bad[i]>='A' && bad[i]<='Z')
			ch[(int)bad[i]+32] = 1;
		else
			ch[(int)bad[i]] = 1;
	}

	char str[100001];
	gets(str);
	for(int i=0; str[i]!='\0'; i++)
		if (!ch[(int)str[i]])
			putchar(str[i]);
	printf("\n");
	return 0;
}
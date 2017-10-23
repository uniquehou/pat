#include <stdio.h>
#include <string.h>
int main() {
	char num[4], result[30];
	gets(num);
	int length = strlen(num);
	int state = 1, index=0;
	for(int i=length-1; i>=0; i--) {
		switch (state++) {
			case 1:
				for(int j=num[i]-'0'; j>0; j--)
					result[index++] = j+'0';
				break;
			case 2:
				for(int j=num[i]-'0'; j>0; j--)
					result[index++] = 'S';
				break;
			case 3:
				for(int j=num[i]-'0'; j>0; j--)
					result[index++] = 'B';
				break;
		}
	}
	result[index] = '\0';
	for(int i=index-1; i>=0; i--)
		putchar(result[i]);
	printf("\n");
}
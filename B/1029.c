// 差2分
#include <stdio.h>

char uppercase(char ch) {
	return ch<97? ch: ch-32;
}

int main() {
	char str[80], str1[80], str2[80]="";
	int index=0;
	gets(str);
	gets(str1);
	int j=0;
	for(int i=0; str[i]!='\0'; i++) {
		if (str[i] != str1[j] || str[j]=='\0') {
			int k=0;
			for(; str2[k]!='\0'; k++)
				if (str2[k] == uppercase(str[i]))
					break;
			if (k==index)
				str2[index++] = uppercase(str[i]);
		}
		else
			j++;
	}
	puts(str2);
}
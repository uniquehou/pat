#include <stdio.h>
int main() {
	char str[10001];
	char ch[7]="PATest";
	gets(str);
	int count[6];    // 代表6个字母的个数
	for(int i=0; str[i]!='\0'; i++)
		switch(str[i]) {
			case 'P': count[0]++; break;
			case 'A': count[1]++; break;
			case 'T': count[2]++; break;
			case 'e': count[3]++; break;
			case 's': count[4]++; break;
			case 't': count[5]++; break;
		}

	int flag=1;
	while(flag) {
		flag=0;
		for(int i=0; i<6; i++)
			if ((count[i]--)>0)
				{ putchar(ch[i]); flag=1;}
	}
	printf("\n");
	return 0;
}
// 差2分
#include <stdio.h>
int main() {
	char str[1000];
	int ch[255] = {0};

	gets(str);
	for(int i=0; str[i]!='\0'; i++)
		ch[(int)str[i]]++;
	for(int i=(int)'a'; i<=(int)'z'; i++)
		ch[i] += ch[i-32];

	int max=0;
	for(int i=(int)'A'; i<=(int)'z'; i++) {
		if (i>'Z' && i<'a')
			continue;
		if (ch[i]>ch[max] || (ch[i]==ch[max] && max>i))
			max = i;
	}
	printf("%c %d\n", max, ch[max]);
	return 0;
}
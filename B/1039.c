#include <stdio.h>
int main() {
	char str1[1001], str2[1001];
	int flag=1, index[1000]={0}, count=0;
	gets(str1);
	gets(str2);

	for(int i=0; str2[i]!='\0'; i++) {
		int j;
		for(j=0; str1[j]!='\0'; j++)
			if (str1[j] == str2[i] && index[j]==0)
				{ index[j]=1; break; }
		if (str1[j]=='\0') {
			flag = 0;
			count++;
		}
	}

	if (flag==1) {
		printf("Yes ");
		for(int i=0; str1[i]!='\0'; i++)
			count += index[i]==0;
		printf("%d\n", count);
	} else {
		printf("No %d\n", count);
	}
	return 0;
}
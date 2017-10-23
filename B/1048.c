// 差7分
#include <stdio.h>
#include <string.h>

int Int(char ch) {
	return (int)ch-'0';
}

int main () {
	char a[101], b[101];
	int result[101];
	char ch[14] = " 123456789JQK";
	scanf("%s %s", a, b);

	int j=strlen(a)-1;
	int i=strlen(b)-1;
	int flag=1;
	while( i>=0 && j>=0 ) {
		if ( flag )
			result[i] = (Int(b[i]) + Int(a[j])) % 13;
		else {
			result[i] = Int(b[i]) - Int(a[j]);
			result[i] = result[i]>=0? result[i]: result[i]+10;
		}
		flag = flag? 0: 1;
		i--; j--;
	}
	while(i>=0) {
		result[i] = Int(b[i]);
		i--;
	}

	for(i=0; i<strlen(b); i++)
		putchar(ch[result[i]]);
	printf("\n");
	return 0;
}
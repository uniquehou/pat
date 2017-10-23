#include <stdio.h>
int main() {
	char ch;
	int sum=0;
	while( (ch=getchar()) != '\n' ) {
		if (ch>='a' && ch<='z')
			sum += (int)ch-'a' + 1;
		else if (ch>='A' && ch<='Z')
			sum += (int)ch-'A' + 1;
	}

	int count_1=0, count_0=0;
	for(; sum; sum/=2)
		if (sum%2==1) count_1++;
		else count_0++;
	printf("%d %d\n", count_0, count_1);
	return 0;
}
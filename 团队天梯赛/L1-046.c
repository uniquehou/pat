#include <stdio.h>
int len_1(long numble) {
	int count = 0;
	for(; numble; numble = (long)numble/10) {
		if (numble % 10 == 1)
			count++;
		else
			return 0;
	}
	return count;
}
int main() {
	int x, len;
	scanf("%d", &x);
	for(int i=1; 1; i++) {
		if ( len = len_1(i*x) ) {
			printf("%d: %d %d\n", i, i*x, len);
			break;
		}
	}
}
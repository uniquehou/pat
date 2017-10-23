#include <stdio.h>

int main() {
	int flag1, i_num, f_num, flag2, e;
	scanf("%c%1d.%dE%c%d", &flag1, &i_num, &f_num, &flag2, &e)

	if (flag1=='-')  printf("-");
	if (e==0)
		printf("%d.%d", i_num, f_num);
	else {
		if (flag2=='-') {
			for(int i=0; i<e; i++) {
				printf("0");
				if (i==0)  printf(".");
			}
			printf("%d%d\n", i_num, f_num);
		} else {
			f_num *= e;
		}
		
	}
	return 0;
}
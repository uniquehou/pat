#include <stdio.h>

int main() {
	int count1, count2;
	int grade1[100000], grade2[100000];

	scanf("%d", &count1);
	for(int i=0; i<count1; i++)
		scanf("%d", &grade1[i]);
	scanf("%d", &count2);
	for(int i=0; i<count2; i++)
		scanf("%d", &grade2[i]);

	for(int i=0; i<count2; i++) {
		int count=0;
		for(int j=0; j<count1; j++) {
			if (grade1[j]==grade2[i])
				count++;
		}

		printf("%d", count);
		if (i!=count2-1)  putchar(' ');
	}
	printf("\n");
	return 0;
}
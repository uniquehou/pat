#include <stdio.h>

int main() {
	int num[50], index=0, temp;
	for(int i=0; i<10; i++) {
		scanf("%d", &temp);
		for(int j=0; j<temp; j++)
			num[index++]=i;
	}
	for(int i=1; i<index; i++)
		for(int j=0; j<i; j++)
			if (num[i]<num[j]) {
				temp = num[i];
				for(int k=i; k>=j; k--)
					num[k] = num[k-1];
				num[j] = temp;
			}

	temp = -1;
	for(int i=0; i<index; i++)
		if (num[i]!=0) {
			temp = i;
			printf("%d", num[i]);
			break;
		}
	for(int i=0; i<index; i++) {
		if (temp>=0 && i==temp)
			continue;
		printf("%d", num[i]);
	}
	printf("\n");
	return 0;
}
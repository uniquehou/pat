#include <stdio.h>

int main() {
	int count, num, data[100001];
	scanf("%d %d", &count, &num);
	for(int i=0; i<count; i++) {
		scanf("%d", &data[i]);
	}
	// sorted
	for(int i=1; i<count; i++) {
		int temp = data[i];
		int j;
		for(j=i; j>0; j--)
			if (temp<data[j-1]) {
				data[j] = data[j-1];
			}
			else
				break;
		if (data[i] != temp)
			data[j] = temp;
	}
	
	int max=0;
	for(int i=0; i<count; i++) {
		int M = data[i] * num;
		int j=0;
		for(j=i; data[j]<=M && j<count; j++);
		if (max<j-i) max=j-i;
	}
	printf("%d\n", max);
	return 0;
}
// 差8分
#include <stdio.h>
#include <string.h>

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	char name[10000][9];
	int height[10000];
	for(int i=0; i<n; i++) 
		scanf("%s %d", name[i], &height[i]);

	for(int i=0; i<n-1; i++) {
		int temp = height[i+1], j;
		char str[9];
		strcpy(str, name[i+1]);
		for(j=i; j>=0; j--)
			if (temp>=height[j]) {
				height[j+1] = height[j];
				strcpy(name[j+1], name[j]);
			}
			else
				break;
		height[j+1] = temp;
		strcpy(name[j+1], str);
	}

	int plot = -1;
	int count = n/k + n%k;
	for(int i=0; i<k; i++) {
		int start = count%2==0? count: count-1;
		for(; start>1; start-=2) 
			printf("%s ", name[plot+start]);
		for(start=1; start<=count; start+=2) {
			printf("%s", name[plot+start]);
			if (start<count-1)
				printf(" ");
		}
		printf("\n");

		plot += count;
		count = n/k;
	}
}
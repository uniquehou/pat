#include <stdio.h>
int main() {
	int row, col, low, hight, match;
	scanf("%d %d %d %d %d", &row, &col, &low, &hight, &match);
	for(int i=0; i<row; i++) {
		int data[500];
		for(int j=0; j<col; j++) {
			scanf("%d", &data[j]);
			if (data[j]>=low && data[j]<=hight)
				data[j] = match;
		}

		printf("%03d", data[0]);
		for(int j=1; j<col; j++)
			printf(" %03d", data[j]);
		printf("\n");
	}
	return 0;
}
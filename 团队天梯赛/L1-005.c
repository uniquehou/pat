#include <stdio.h>
struct Student {
	char name[15];
	int x,y;
};
int main() {
	struct Student students[1000];
	int max;

	scanf("%d", &max);
	getchar();
	for(int i=0; i<max; i++) {
		scanf("%s%d%d", students[i].name, &students[i].x, &students[i].y);
	}
		
	
	int search_sum, search[1000];
	scanf("%d", &search_sum);
	for(int i=0; i<search_sum; i++)
		scanf("%d", &search[i]);

	for(int i=0; i<search_sum; i++) {
		for (int j=0; j<max; j++) {
			if (students[j].x == search[i]) {
				printf("%s %d\n", students[j].name, students[j].y);
				break;
			}
		}
	}
}
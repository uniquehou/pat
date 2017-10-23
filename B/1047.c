#include <stdio.h>

int main() {
	int n, max=0;
	int GRADE[1001] = {0};
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		int id, temp, grade;
		scanf("%d-%d %d", &id, &temp, &grade);
		GRADE[id] += grade;
		if (GRADE[id]>GRADE[max])
			max=id;
	}
	printf("%d %d\n", max, GRADE[max]);
	return 0;
}
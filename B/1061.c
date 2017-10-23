#include <stdio.h>
int main() {
	int stu_count, pro_count;
	scanf("%d %d", &stu_count, &pro_count);
	int grade[100], answer[100];
	for(int i=0; i<pro_count; i++)
		scanf("%d", &grade[i]);
	for(int i=0; i<pro_count; i++)
		scanf("%d", &answer[i]);

	for(int i=0; i<stu_count; i++) {
		int result=0, num;
		for(int j=0; j<pro_count; j++) {
			scanf("%d", &num);
			if (num==answer[j])
				result += grade[j];
		}
		printf("%d\n", result);
	}
	return 0;
}
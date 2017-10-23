#include <stdio.h>
#include <string.h>

int main() {
	int student_count, problem_count;
	scanf("%d %d", &student_count, &problem_count);
	int problem[100][3];
	char problem_answer[100][10];
	for(int i=0; i<problem_count; i++) {
		scanf("%d %d %d ", &problem[i][0], &problem[i][1], &problem[i][2]);
		gets(problem_answer[i]);
	}
	int student[1000][100];
	char student_answer[1000][100][10];
	for(int i=0; i<student_count; i++) {
		char str[1500];
		gets(str);
		int index=0;     // 题目索引
		for(int j=0; str[j]!='\0'; j++) {
			if (str[j]!='(')
				continue;
			student[i][index] = (int)str[++j] - '0';
			j++;
			int index1=0;
			for(j++; str[j]!=')'; j++)
				student_answer[i][index][index1++] = str[j];
			student_answer[i][index][index1] = '\0';
			index++;
		}
	}

	int max=0;
	int error[100] = {0};         // 存储各题错误次数
	for(int i=0; i<student_count; i++) {
		int count = 0;
		for(int j=0; j<problem_count; j++) {
			if (student[i][j] == problem[j][2] && strcmp(student_answer[i][j], problem_answer[j])==0 )
				count += problem[j][0];
			else {
				error[j]++;
				if (error[j]>error[max])
					max=j;
			}
		}
		printf("%d\n", count);
	}
	if (error[max]==0)
		printf("Too simple\n");
	else {
		printf("%d", error[max]);
		for(int i=0; i<problem_count; i++)
			if (error[i]==error[max])
				printf(" %d", i+1);
		printf("\n");
	}
	return 0;
}
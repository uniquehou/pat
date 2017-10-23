#include <stdio.h>

int main() {
	int grade[100001];
	int count;
	scanf("%d", &count);
	for (int i=0; i<count; i++) {
		int TmpNum, TmpGrade;
		scanf("%d %d", &TmpNum, &TmpGrade);
		grade[TmpNum] += TmpGrade;
	}

	int MaxNum=0, MaxGrade=0;
	for(int i=1; i<100001; i++)
		if (grade[i]>MaxGrade) {
			MaxGrade=grade[i];
			MaxNum = i;
		}

	printf("%d %d\n", MaxNum, MaxGrade);
	return 0;
}
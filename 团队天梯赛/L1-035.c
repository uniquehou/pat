#include <stdio.h>
#include <string.h>
int main() {
	char A[10]=".", B[10]=".", str[10];
	for(int i=1; str[0]!='.'; i++){
		gets(str);
		if (i==2) strcpy(A, str);
		if (i==14) strcpy(B, str);
	}
	if (B[0] != '.') printf("%s and %s are inviting you to dinner...\n", A, B);
	else if (A[0] == '.') printf("Momo... No one is for you ...\n");
	else printf("%s is the only one for you...\n", A);
	return 0;
}
// 格式差两分。^~^
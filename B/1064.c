// 差1分
#include <stdio.h>
#include <string.h>

int main() {
	char pass[21];
	int count;
	scanf("%s %d", pass, &count);
	getchar();

	char str[100];
	int n=1;
	for( gets(str); strcmp(str, "#")!=0; gets(str)) {
		if (n>count) {
			printf("Account locked\n");
			break;
		}
		if (strcmp(str, pass)==0) {
			printf("Welcome in\n");
			break;
		}
		else
			printf("Wrong password: %s\n", str);
		n++;
	}
	return 0;
}
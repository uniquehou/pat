#include <stdio.h>
struct Student{
	char name[4];
	int a;
	int b;
}stu[10];
int main() {
	int n;
	scanf("%d", &n); getchar();
	for(int i=0; i<n; i++) {
		scanf("%s %d %d", stu[i].name, &stu[i].a, &stu[i].b);
	}
	for(int i=0; i<n; i++) 
		if (stu[i].a < 15 || stu[i].a > 20 || stu[i].b < 50 || stu[i].b > 70)
			printf("%s\n", stu[i].name);
}
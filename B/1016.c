#include <stdio.h>
int main() {
	char Da[10], Db[10], A, B;
	scanf("%s %c %s %c", Da, &A, Db, &B);
	
	int a=0, b=0;
	for(int i=0; Da[i]!='\0'; i++)
		if(Da[i]==A)
			a = a*10 + (Da[i]-'0');
	for(int i=0; Db[i]!='\0'; i++)
		if(Db[i]==B)
			b = b*10 + (Db[i]-'0');
	printf("%d\n", a+b);
	return 0;
}
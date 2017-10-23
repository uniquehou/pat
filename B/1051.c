// 差1分，答案错误
#include <stdio.h>
#include <math.h>
int main() {
	float r1, p1, r2, p2;
	scanf("%f %f %f %f", &r1, &p1, &r2, &p2);
	float a1, b1, a2, b2, a, b;
	a1 = r1*cos(p1);
	b1 = r1*sin(p1);
	a2 = r2*cos(p2);
	b2 = r2*sin(p2);
	a = a1*a2 - b1*b2;
	b = a1*b2 + b1*a2;
	if (b<0)
		printf("%.2f-%.2fi\n", a, -b);
	else
		printf("%.2f+%.2fi\n", a, b);
	return 0;
}
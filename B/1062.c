#include <stdio.h>
int main() {
	int low, m, high, n, num;
	scanf("%d/%d %d/%d %d", &low, &m, &high, &n, &num);
	low = int(low * num / low + 0.5);
	high = int(high * num / low + 0.5);

}
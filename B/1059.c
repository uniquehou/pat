#include <stdio.h>
#include <math.h>

int isPrime(int n) {
	if (n==2)
		return 1;
	else if (n%2==0)
		return 0;
	else {
		for(int i=3; i<=sqrt(n); i++)
			if (n%i==0)
				return 0;
	}
	return 1;
}

int main() {
	int n;
	int data[10000];
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &data[i]);

	int m;
	int check[10000];
	scanf("%d", &m);
	for(int i=0; i<m; i++)
		scanf("%d", &check[i]);

	int flag[10000] = {0};
	for(int i=0; i<m; i++) {
		int j;
		for(j=0; j<n; j++)
			if (check[i] == data[j]) {
				if (flag[j]==0) {
					if (j==0)
						printf("%04d: Mystery Award\n", data[j]);
					else if(isPrime(j+1))
						printf("%04d: Minion\n", data[j]);
					else
						printf("%04d: Chocolate\n", data[j]);
					flag[j]=1;
				}
				else
					printf("%04d: Checked\n", data[j]);
				break;
			}
		if (j==n)
			printf("%04d: Are you kidding?\n", check[i]);
	}
	return 0;
}
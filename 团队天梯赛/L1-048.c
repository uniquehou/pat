#include <stdio.h>
int main() {
	int Ra, Ca, Rb, Cb;
	int a[100][100], b[100][100];
	scanf("%d %d", &Ra, &Ca);
	for(int i=0; i<Ra; i++)
		for(int j=0; j<Ca; j++)
			scanf("%d", &a[i][j]);
	scanf("%d %d", &Rb, &Cb);
	for(int i=0; i<Rb; i++)
		for(int j=0; j<Cb; j++)
			scanf("%d", &b[i][j]);

	if (Ca != Rb) {
		printf("Error: %d != %d\n", Ca, Rb);
		return 0;
	}

	int Rc = Ra, Cc = Cb;
	int c[100][100];
	for(int i=0; i<Rc; i++)
		for(int j=0; j<Cc; j++) {
			c[i][j] = 0;
			for(int k=0; k<Ca; k++)
				c[i][j] += a[i][k] * b[k][j];
		}

	printf("%d %d\n", Rc, Cc);
	for(int i=0; i<Rc; i++){
		for(int j=0; j<Cc; j++) {
			if (j==Cc-1)
				printf("%d\n", c[i][j]);
			else
				printf("%d ", c[i][j]);
		}
	}
}
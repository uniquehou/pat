#include <stdio.h>
#include <string.h>

int main() {
	int n1, n2;
	char site_id[1000][15];
	int site_num[1000][2];
	int test_num[1000];

	scanf("%d", &n1);
	for(int i=0; i<n1; i++) {
		scanf("%s %d %d", site_id[i], &site_num[i][0], &site_num[i][1]);
	}
	scanf("%d", &n2);
	for(int i=0; i<n2; i++)
		scanf("%d", &test_num[i]);

	for(int i=0; i<n2; i++)
		for(int j=0; j<n1; j++)
			if (test_num[i] == site_num[j][0])
				printf("%s %d\n", site_id[j], site_num[j][1]);
	return 0;
}
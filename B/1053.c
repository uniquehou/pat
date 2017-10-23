// 差7分
#include <stdio.h>
#include <malloc.h>

int main() {
	float count, e, d;
	scanf("%f %f %f", &count, &e, &d);

	float *data[1000];
	int maybe=0, free=0;
	for(int i=0; i<count; i++) {
		float n, TmpData, TmpCount=0;
		scanf("%f", &n);

		data[i] = (int*)calloc(n, sizeof(int));
		for(int j=0; j<n; j++) {
			// scanf("%d", &(data[i][j]) );
			scanf("%f", &TmpData);
			if (TmpData<e)
				TmpCount++;
		}

		if (TmpCount>d)
			free++;
		else if (TmpCount>n/2)
			maybe++;
	}

	// 使用二维数组动态分配空间
	// for(int i=0; i<count; i++) {
	// 	float n;
	// 	scanf("%f", &n);

	// 	data[i] = (float*)calloc(n+1, sizeof(float));
	// 	data[i][0] = n;
	// 	for(int j=1; j<=n; j++) {
	// 		scanf("%f", &(data[i][j]) );
	// 	}
	// }
	// for(int i=0; i<count; i++) {
	// 	int TmpCount=0;
	// 	for(int j=1; j<=data[i][0]; j++)
	// 		if (data[i][j]<e)
	// 			TmpCount++;

	// 	if (TmpCount>d)
	// 		free++;
	// 	else if (TmpCount>data[i][0]/2)
	// 		maybe++;
	// }


	printf("%.1f%% %.1f%%\n", maybe/count*100, free/count*100);
	return 0;
}
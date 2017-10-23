// 差3分，浮点错误，可能有分母为零的情况，但不知道怎么处理
#include <stdio.h>

int data[101][2];    // [0]存放最后的结果，从[1]开始存放数据
int index=1;

int find_down(int item) {
	for(int i=1; i<index; i++)
		if (data[i][1] == item)
			return i;
	return 0;
}

int abs(int item) {
	return item>=0? item: -item;
}

int gcd(int a, int b) {
	while (a!=b) {
		if (a<b)
			{a^=b; b^=a; a^=b;}    // a、b互换
		a = a-b;
	}
	return a;
}

int main() {
	int n, up, down;
	int temp;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d/%d", &up, &down);
		temp = find_down(down);
		if (temp)
			data[temp][0] += up;
		else {
			data[index][0] = up;
			data[index][1] = down;
			index++;
		}
	}

	if (index==2) {
		data[0][0] = data[1][0];
		data[0][1] = data[1][1];
	} else {
		data[0][0] = 0;
		data[0][1] = data[1][1];
		// 算所有数的最小公倍数
		for(int i=2; i<index; i++) {
			int min = data[0][1] > data[i][1]? data[i][1]: data[0][1];
			int max = data[0][1] > data[i][1]? data[0][1]: data[i][1];
			int j=1;
			for(; min*j%max!=0; j++);
			data[0][1] = min*j;
		}

		// 分子相加
		for(int i=0; i<index; i++) {
			data[0][0] += data[0][1]/data[i][1] * data[i][0];
		}
	}
	
	// 输出最后结果
	if (abs(data[0][0])%data[0][1]==0) {
		printf("%d\n", data[0][0]/data[0][1]);
		return 0;
	} else if (abs(data[0][0])>data[0][1]) {
		printf("%d ", data[0][0]/data[0][1]);
		data[0][0] = abs(data[0][0]) % data[0][1];
	}
	
	// 分子分母约分
	temp = gcd(abs(data[0][0]), data[0][1]);
	data[0][0] /= temp;
	data[0][1] /= temp;
	printf("%d/%d\n", data[0][0], data[0][1]);
	return 0;
}
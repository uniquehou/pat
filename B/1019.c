#include <stdio.h>

char *toStr(int num, char *str) {
	// char str[5];
	int index=3;
	for(; num; num/=10)
		str[index--] = num%10 + '0';
	while(index>=0)  str[index--]='0';
	str[4] = '\0';
	return str;
}

int toInt(char *str) {
	int num = 0;
	for(int i=0; i<4; i++)
		num = num*10 + str[i]-'0';
	return num;
}

int getMax(int num) {
	char str[5];
	toStr(num, str);
	for(int i=0; i<3; i++)
		for(int j=i+1; j<4; j++)
			if (str[i]<str[j]) {
				str[i] ^= str[j];
				str[j] ^= str[i];
				str[i] ^= str[j];
			}
	return toInt(str);
}

int getMin(int num) {
	char str[5];
	toStr(num, str);
	for(int i=0; i<3; i++)
		for(int j=i+1; j<4; j++)
			if(str[i]>str[j]) {
				str[i] ^= str[j];
				str[j] ^= str[i];
				str[i] ^= str[j];
			}
	return toInt(str);
}

int main() {
	int num, max, min;
	scanf("%d", &num);
	do {
		max = getMax(num);
		min = getMin(num);
		num = max - min;
		printf("%04d - %04d = %04d\n", max, min, num);
	} while (num!=6174 && num!=0);
	return 0;
}
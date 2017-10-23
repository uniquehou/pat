#include <stdio.h>
#include <string.h>

char bit[13][5] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
char ten[13][5] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int Earth(char str[10]) {
	int num = 0;
	if (strlen(str)>4) {
		for(int i=0; i<13; i++)
			if (str[0] == ten[i][0] && str[1] == ten[i][1] && str[2] == ten[i][2])
				{ num += i*13; break; }
		for(int i=0; i<13; i++)
			if (str[4] == bit[i][0] && str[5] == bit[i][1] && str[6] == bit[i][2])
				{ num += i; break; }
	} else {
		for(int i=0; i<13; i++)
			if (str[0] == ten[i][0] && str[1] == ten[i][1] && str[2] == ten[i][2])
				{ num += i*13; break; }
		for(int i=0; i<13; i++)
			if (str[0] == bit[i][0] && str[1] == bit[i][1] && str[2] == bit[i][2])
				{ num += i; break; }
	}
	return num;
}

void Fire(char str[10]) {
	char num[10] = "";
	if ((strlen(str)==2 && (str[0]>'1' || str[1]>='3')) || strlen(str)==3) {
		int IntNum;
		if (strlen(str)==2)
			IntNum = (str[0]-'0')*10 + str[1]-'0';
		else
			IntNum = (str[0]-'0')*100 + (str[1]-'0')*10 + str[2]-'0';
		strcat(num, ten[IntNum/13]);
		if (IntNum%13>0) {
			strcat(num, " ");
			strcat(num, bit[IntNum%13]);
		}
	} else {
		int IntNum;
		if (strlen(str)==2)
			IntNum = (str[0]-'0')*10 + str[1]-'0';
		else
			IntNum = str[0]-'0';
		strcat(num, bit[IntNum%13]);
	}
	strcpy(str, num);
}

int main() {
	int n;
	scanf("%d", &n);
	getchar();
	char str[100][10];
	for(int i=0; i<n; i++)
		gets(str[i]);

	for(int i=0; i<n; i++) {
		if ( str[i][0] <= '9' ) {
			Fire(str[i]);
			puts(str[i]);
		}
		else
			printf("%d\n", Earth(str[i]));
	}
	return 0;
}
// 差5分，答案错误
#include <stdio.h>
#include <string.h>
#define ERROR 2000.0

float Int(char str[100]) {
	int length = strlen(str);
	float num=0;
	int flag=0;
	if (strchr(str, '.')==NULL) {
		for(int i=length-1; i>=0 && str[i]!='-'; i--) {
			if ( str[i]>='0' && str[i]<='9')
				num = num*10 + (int)str[i]-'0';
			else { flag=1; break; }
		}
		if (!flag && num<=1000.0)
			return (str[0]=='-'? -num: num);
	} else {
		char *p = strchr(str, '.');
		if (&str[length-1]-p<=2) {
			for(char *q=p-1; q>=str && (*q)!='-'; q--)
				if ((*q)>='0' && (*q)<='9')
					num = num*10 + (int)(*q)-'0';
				else { flag=1; break; }
			p++;
			if ( !flag && (*p)!='\0' ) 
				if ((*p)>='0' && (*p)<='9')
					num += ((*p)-'0') * 0.1;
				else
					flag=1;
			p++;
			if ( !flag && (*p)!='\0' ) 
				if ((*p)>='0' && (*p)<='9')
					num += ((*p)-'0') * 0.01;
				else
					flag=1;
			if (!flag && num<=1000.0)
				return (str[0]=='-'? -num: num);
		}
	}

	printf("ERROR: %s is not a legal number\n", str);
	return ERROR;
}

int main() {
	int count, legal=0;
	float sum=0;
	scanf("%d\n", &count);
	for(int i=0; i<count; i++) {
		char str[100];
		scanf("%s", str);

		float num = Int(str);
		if (num!=ERROR) {
			legal++;
			sum += num;
		}
	}

	if (legal>0)
		printf("The average of %d numbers is %.2f\n", legal, sum/legal);
	else
		printf("The average of 0 numbers is Undefined\n");
	return 0;
}
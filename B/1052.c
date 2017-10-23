// 差8分，答案错误
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define ERROR "Are you kidding me? @\\/@"

int main() {
	char hand[10][5], eye[10][5], mouse[10][5];
	int length_hand=0, length_eye=0, length_mouse=0;

	char str[1000];
	int index;
	gets(str);
	for(int i=0; str[i]!='\0'; i++) {
		if (str[i]!='[')
			continue;
		index=0;
		for(i++; str[i]!=']'; i++)
			hand[length_hand][index++] = str[i];
		hand[length_hand][index] = '\0';
		length_hand++;
	}

	gets(str);
	for(int i=0; str[i]!='\0'; i++) {
		if (str[i]!='[')
			continue;
		index=0;
		for(i++; str[i]!=']'; i++)
			eye[length_eye][index++] = str[i];
		eye[length_eye][index] = '\0';
		length_eye++;
	}

	gets(str);
	for(int i=0; str[i]!='\0'; i++) {
		if (str[i]!='[')
			continue;
		index=0;
		for(i++; str[i]!=']'; i++)
			mouse[length_mouse][index++] = str[i];
		mouse[length_mouse][index] = '\0';
		length_mouse++;
	}

	int count;
	scanf("%d", &count);
	int *data = (int*)calloc(count*5, sizeof(int));
	for(int i=0; i<count; i++)
		for(int j=0; j<5; j++)
			scanf("%d", &(data[i*5+j]));

	for(int i=0; i<count; i++)
		if (data[i*5]<=length_hand && data[i*5+4]<=length_hand && data[i*5+1]<=length_eye && data[i*5+3]<=length_eye && data[i*5+2]<=length_mouse)
			printf("%s(%s%s%s)%s\n", hand[ data[i*5+0]-1 ], eye[ data[i*5+1]-1 ], mouse[ data[i*5+2]-1 ], eye[ data[i*5+3]-1 ], hand[ data[i*5+4]-1 ]);
		else
			printf("%s\n", ERROR);
	return 0;
}
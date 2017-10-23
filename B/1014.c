#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define N 60
 
char *GetWeek(char ch) {
    char *week = (char*)calloc(5, sizeof(char));
    ch = ch>'Z'? ch-32: ch;
    switch(ch-'A'+1) {
        case 1: strcpy(week, "MON\0"); break;
        case 2: strcpy(week, "TUE\0"); break;
        case 3: strcpy(week, "WED\0"); break;
        case 4: strcpy(week, "THU\0"); break;
        case 5: strcpy(week, "FRI\0"); break;
        case 6: strcpy(week, "SAT\0"); break;
        case 7: strcpy(week, "SUN\0"); break;
    }
    return week;
}
 
int GetHour(char ch) {
    if (ch<='9')  return ch-'0';
    else {
        ch = ch>'Z'? ch-32: ch;
        return ch-'A'+10;
    }
}
int main() {
    // char *week;
    // char str1[N] = "3485djDkxh4hhGE";
    // char str2[N] = "2984akDfkkkkggEdsb";
    // char str3[N] = "s&hgsfdk";
    // char str4[N] = "d&Hyscvnm";
 
    int flag = 1, hour, min;
    char str1[N], str2[N], str3[N], str4[N], *week;
    gets(str1);
    gets(str2);
    gets(str3);
    gets(str4);
    for(int i=0; str1[i]!='\0' && str2[i]!='\0'; i++)
        if (str1[i] == str2[i]) {
            if (flag==1 && str1[i]>='A' && str1[i]<='Z') {
                week = GetWeek(str1[i]);
                flag++;
            } else if(flag == 2) {
                hour = GetHour(str1[i]);
                break;
            }
        }
    for(int i=0; str3[i]!='\0' && str4[i]!='\0'; i++)
        if (str3[i] == str4[i])
            if ((str3[i]>='a' && str3[i]<='z') || (str3[i]>='A' && str3[i]<='Z')){
                min = i;
                break;
            }
    printf("%s %02d:%02d\n", week, hour, min);
}
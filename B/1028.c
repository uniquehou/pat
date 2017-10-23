// 差1分
#include <stdio.h>
#include <string.h>

int OK(int year, int month, int day) {
	if (year>2014 || year<1814)
		return 0;
	if (year==2014 && (month>9 || month==9 && day>6))
		return 0;
	if (year==1814 && (month<9 || month==9 && day<6))
		return 0;
	return 1;
}

int BirGt(int MinBir[3], int MaxBir[3]) {
	if (MaxBir[0]>MinBir[0])
		return 1;
	if (MinBir[0] == MaxBir[0] && (MaxBir[1] > MinBir[1] || MaxBir[1] == MinBir[1] && MaxBir[2]>MinBir[2]) )
		return 1;
	return 0;
}

int main() {
	int count, num=0;
	scanf("%d", &count);
	char MaxName[6], MinName[6];
	int MaxBir[3], MinBir[3];
	for(int i=0; i<count; i++) {
		char TmpName[6];
		int TmpYear, TmpMonth, TmpDay;
		scanf("%s %4d/%2d/%2d", TmpName, &TmpYear, &TmpMonth, &TmpDay);

		if (OK(TmpYear, TmpMonth, TmpDay)) {
			if (num==0) {
				strcpy(MinName, TmpName);
				strcpy(MaxName, TmpName);
				MinBir[0] = MaxBir[0] = TmpYear;
				MinBir[1] = MaxBir[1] = TmpMonth;
				MinBir[2] = MaxBir[2] = TmpDay;			
			} else {
				int TmpBir[3] = {TmpYear, TmpMonth, TmpDay};
				if (BirGt(MinBir, TmpBir)) {
					strcpy(MinName, TmpName);
					MinBir[0] = TmpBir[0];
					MinBir[1] = TmpBir[1];
					MinBir[2] = TmpBir[2];
				}
				if (BirGt(TmpBir, MaxBir)) {
					strcpy(MaxName, TmpName);
					MaxBir[0] = TmpBir[0];
					MaxBir[1] = TmpBir[1];
					MaxBir[2] = TmpBir[2];
				}
			}
			num++;
		}
	}
	printf("%d %s %s\n", num, MaxName, MinName);
	return 0;
}
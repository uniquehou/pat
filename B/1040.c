#include <stdio.h>
int main() {
	char str[100001];
	int count=0;
	gets(str);
	int CountP=0;
	for(int i=0; str[i]!='\0'; i++) {
		if (str[i]!='A') continue;      // i指向第一个 'P' 的位置
		int j, k;
		int TmpCount=0;
		for(j=i; str[j]!='A'; j++);     // j指向第一个 'A' 的位置
		for(k=j+1; str[k]!='\0'; k++)   // 寻找 A 之后 T 的个数
			TmpCount += str[k]=='T';
		for(k=j-1; k>i; k--)            // 寻找 A 之前 P 的个数
			CountP += (str[k]=='P');
		TmpCount += CountP * TmpCount;
		CountP++;

		count += TmpCount;
		i=j;
	}
	printf("%d\n", count%1000000007);
	return 0;
}
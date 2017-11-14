
#include<stdio.h>
#include<string.h>
int main(){
	int i,j,num_hang,lie=0,sum=0,len,t=0;
	char str[1001],arr[1001][1001]; 
	int K,L;
	scanf("%d",&num_hang);
	getchar();  //回车 
	gets(str);
	len=strlen(str);

	while(sum<len)    //求输出数组的列数 
	{
		sum= lie*num_hang;
		lie++;
	}
	lie--;
		
	for(i=lie-1;i>=0;i--)     //给数组赋值   
	{
	   for(j=0;j<num_hang;j++)     
	   {
	   	 if(t<len) arr[j][i]=str[t++];
	   	 else arr[j][i]=' '; //超出字符串长度补空格 
	   }	
	}

   	for(K=0;K<num_hang;K++)
	    { 
		 for(L=0;L<lie;L++)
		   	  printf("%c",arr[K][L]);
        printf("\n"); 
	   }
	   	
	return 0;
} 
// 第一次错误： 原样输出； 
// 原因：   数组输出错误 ，按照赋值格式原样输出，且未打印换行 (printf ("\n");) 
// 第二次错误 ：赋值错误；
// 原因:  赋值与输出对应行列错误，  二维数组的赋值与输出行列必须相同 。
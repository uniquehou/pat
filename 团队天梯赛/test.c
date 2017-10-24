#include<stdio.h>
int main()
{
  int max,i,j,k,l,Stud[1010][2],SearchNum,search[1000];
  char StuNum[1010][20];

 scanf("%d",&max);
 getchar();

for(i=0;i<max;i++)
  {  
     scanf("%14c%d%d",&StuNum[i],&Stud[i][0],&Stud[i][1]);
     getchar();
   }

  scanf("%d",&SearchNum);
  
  for(j=0;j<SearchNum;j++)
  scanf("%d",&search[j]);

  for(k=0;k<SearchNum;k++)
 {
   for(l=0;l<max;l++)
    {
       if(Stud[l][0]==search[k])
      {
       printf("%s %d\n",StuNum[l],Stud[l][1]);
        break;
      }
    }
 }
return 0;
}
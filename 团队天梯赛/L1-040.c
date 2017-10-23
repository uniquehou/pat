#include <stdio.h>
int main() {
  int n;
  scanf("%d", &n);
  getchar();
  float array[10];
  char sex[10];
  for(int i=0; i<n; i++) {
    scanf("%c %f", &sex[i], &array[i]);
    getchar();
  }
  for(int i=0; i<n; i++)
    if (sex[i]=='M')
      printf("%.2f\n", array[i]/1.09);
    else
      printf("%.2f\n", array[i]*1.09);
  return 0;
}
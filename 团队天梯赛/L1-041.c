#include <stdio.h>
int main() {
  int numble, count=0;
  char ch=' ';
  for(int i=1; ch!='\n'; i++) {
    scanf("%d", &numble);
    ch = getchar();
    if (numble==250 && !count)
      count = i;
  }
  printf("%d\n", count);
  return 0;
}
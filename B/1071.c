#include <stdio.h>
int main() {
    int sum_t, sum_count;
    scanf("%d %d", &sum_t, &sum_count);
    for(int i=0; i<sum_count; i++) {
        int n1, b, t, n2;
        scanf("%d %d %d %d", &n1, &b, &t, &n2);
        
        if (t>sum_t) {
            printf("Not enough tokens. Total=%d.\n", sum_t);
        } else if (n2>n1 && b==1 || n2<n1 && b==0) {
            sum_t += t;
            printf("Win %d! Total=%d.\n", t, sum_t);
        } else {
            sum_t -= t;
            printf("Lose %d. Total=%d.\n", t, sum_t);
            if (sum_t==0) {
                printf("Game Over.\n");
                break;
            }
        }
    }
    return 0;
}

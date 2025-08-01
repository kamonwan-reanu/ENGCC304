#include <stdio.h>

int main() {
    int N;

    printf("Enter value:\n");

    if (scanf("%d", &N) == 1) {

            printf("Series: ");
            if (N % 2 == 1) {
                for (int i = 1; i <= N; i += 2) {
                    printf("%d ", i);
                }
            } else {
                for (int i = N; i >= 0; i -= 2) {
                    printf("%d ", i);
                }
            }
        } 
        else {
            printf("NO!");
    }

    return 0;
}

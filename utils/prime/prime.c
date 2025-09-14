#include <stdio.h>

int main(void) {
    for (int i = 60001; ; i += 2) {
        int is_prime = 1;
        for (int j = 3; j <= i / j; j += 2) {
            if (i % j == 0) {
                is_prime = 0;
                break;
            }
        }

        if (is_prime) {
            printf("%d\n", i);
            break;
        }
    }
    
    return 0;
}
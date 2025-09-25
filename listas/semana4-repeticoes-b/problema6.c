#include <stdio.h>
#include <math.h>

int main() {
    int a, b;
    double c;

    printf("Trios pitagoricos com c < 1000:\n");

    for (a = 1; a < 1000; a++) {
        for (b = a; b < 1000; b++) {
            c = sqrt(a * a + b * b);

            if (c >= 1000) {
                break;
            }

            if (c == (int)c) {
                printf("(%d, %d, %d)\n", a, b, (int)c);
            }
        }
    }

    return 0;
}
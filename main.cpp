#include <iostream>

void print_star(int n, int m) {
    int mid = (n - 1) / 2 + 1;
    int star = (n - m) / 2;
    int i = 1;

    while (i <= star) {
        printf(" ");
        i++;
    }
    while (i < mid) {
        printf("*");
        i++;
    }

    printf("*");
    i++;
    while (i <= n-star) {
        printf("*");
        i++;
    }
    while (i <= n) {
        printf(" ");
        i++;
    }
    printf("\n");


}

int main() {
    int n;
    scanf("%d", &n);
    if (n % 2 == 0&&n>=1&&n<80) {
        printf("error");
        return 0;
    } else {
        for (int i = n; i > 0; i -= 2) {
            print_star(n, i);
        }
        return 0;
    }

}
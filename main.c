#include <stdio.h>
#include <stdbool.h>

int sumOfDivisors(int n) {
    int sum = 1; 
	for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i) { 
                sum += n / i;             }
        }
    }
    return (n > 1) ? sum : 0;
}

bool areFriendly(int a, int b) {
    int sumA = sumOfDivisors(a);
    int sumB = sumOfDivisors(b);
    return (sumA == b && sumB == a);
}

int main() {
    int a = 220, b = 284;
    if (areFriendly(a, b)) {
        printf("%d és %d barátságos számok.\n", a, b);
    } else {
        printf("%d és %d nem barátságos számok.\n", a, b);
    }
    return 0;
}


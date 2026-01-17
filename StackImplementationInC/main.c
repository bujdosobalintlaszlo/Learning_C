#include <stdio.h>
#include "stack.h"

/* Konkrét típus kiírása */
void printInt(void* p) {
    printf("%d", *(int*)p);
}

int main() {
    Stack s;

    if (!initStack(&s, sizeof(int), 5)) {
        printf("Stack init failed\n");
        return 1;
    }

    int a = 10, b = 20, c = 30;
    push(&s, &a);
    push(&s, &b);
    push(&s, &c);

    printf("Stack tartalma: ");
    printStack(s, printInt);

    int x;
    top(s, &x);
    printf("Top (nem torol): %d\n", x);

    pop(&s, &x);
    printf("Pop (torol): %d\n", x);

    printf("Pop utan: ");
    printStack(s, printInt);

    setEmpty(&s);
    printf("Kiurites utan: ");
    printStack(s, printInt);

    return 0;
}

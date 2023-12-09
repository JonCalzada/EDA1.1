#include <stdio.h>
#include <stdlib.h>
#include "Pila.h"

int main()
{
    struct Pila *a;
    a=crear();
    push(a,'A');
    printf("%c\n" ,pop(a));
    return 0;
}

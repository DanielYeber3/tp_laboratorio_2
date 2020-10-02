#include <stdio.h>
#include "employees.h"
#include "menu.h"
#include <string.h>
#include <stdlib.h>
#define T 1000



int main()
{

    sEmployee list[T];

    initEmployees(list, T);
    menuUno(list, T);

    return 0;
}


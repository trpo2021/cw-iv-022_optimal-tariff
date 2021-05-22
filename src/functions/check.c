#include "lib.h"

int check(int a, int check)
{
    if ((a > 0) && (a <= check))
        return 1;
    system("clear");
    printf("Неверный ввод, повторите попытку\n");
    sleep(3);
    return 0;
}
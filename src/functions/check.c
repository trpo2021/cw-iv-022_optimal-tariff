#include "lib.h"

int check(int a, int check)
{
    if (a == 0)
        return 0;
    if ((a > 0) && (a <= check)) {
        return 1;
    }
    return 0;
}
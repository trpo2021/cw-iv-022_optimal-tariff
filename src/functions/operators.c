#include "lib.h"

void operators()
{
    FILE *f;
    struct operators op[4];
    f = fopen("../csv_input/operators.csv", "r");
    char opnmb[40];
    for (int cnt = 1; cnt < 5; cnt++) {
        fscanf(f,"%s", op[cnt].operator);
        sprintf(opnmb,"%d. %s\n", cnt, op[cnt].operator);
        printf(opnmb, op[cnt].operator);
    }
    fclose(f);
}
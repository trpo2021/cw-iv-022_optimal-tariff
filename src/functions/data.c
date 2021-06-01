#include "lib.h"

int data(int b, int c)
{
    FILE* f;
    struct tariffs pr;
    char dir[4][8] = {{"MTC"}, {"TELE2"}, {"YOTA"}, {"MEGAFON"}};
    char path[30];
    sprintf(path, "../csv_input/%s/%d.csv", dir[b - 1], c);
    f = fopen(path, "r");
    if (f == NULL)
        return -1;
    fscanf(f,
           "%s%s%d%s%d%s%d%s%d",
           pr.tf_name,
           pr.gb,
           &pr.gb_value,
           pr.min,
           &pr.min_value,
           pr.sms,
           &pr.sms_value,
           pr.price,
           &pr.price_value);
    fclose(f);
    int b1 = 1;
    int* g;
    g = &b1;
    temp(g, pr.gb_value, pr.min_value, pr.sms_value, pr.price_value);
    return 0;
}
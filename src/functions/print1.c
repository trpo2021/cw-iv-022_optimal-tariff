#include "lib.h"

void print1(int a)
{
    FILE *f;
    struct tariffs pr;
    char dir[4][8]
        = {{"MTC"},
            {"TELE2"},
            {"YOTA"},
            {"MEGAFON"}};
    char path[38];
    for (int i = 1; i <= 4; i++) {
        sprintf(path,"../csv_input/%s/%d.csv",dir[a-1], i);
        f = fopen(path, "r");
            fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
            fclose(f);
            printf("%d: %s\n%s\n%d\n%s\n%d\n%s\n%d\n%s\n%d\n\n", i, pr.tf_name, pr.gb, pr.gb_value, pr.min, pr.min_value, pr.sms, pr.sms_value, pr.price, pr.price_value);
    }
}
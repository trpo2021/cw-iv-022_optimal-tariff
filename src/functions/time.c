#include "lib.h"

int hrs(void)
{
    struct tm *ptr;
    time_t It;
    It = time(NULL);
    ptr = localtime(&It);
    FILE *f;
    f = fopen("../csv_input/time.csv", "w");
    fprintf(f, "%d", ptr->tm_hour);
    fclose(f);
    return 0;
}

void greeting()
{
    FILE *f;
    struct time tm;
    f = fopen("../csv_input/time.csv", "r");
    fscanf(f,"%d", &tm.hours);
    if(tm.hours >= 0 && tm.hours <= 5)
        printf(" Доброй ночи\n");
    else if(tm.hours >= 6 && tm.hours <= 11)
        printf(" Доброе утро\n");
    else if(tm.hours >= 12 && tm.hours <= 16)
        printf(" Добрый день\n");
    else if(tm.hours >= 17 && tm.hours <= 20)
        printf(" Добрый вечер\n");
    else if(tm.hours >= 21 && tm.hours <= 23)
        printf(" Доброй ночи\n");
    fclose(f);
    remove("../csv_input/time.csv");
}
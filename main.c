#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct time
{
    int hours;
};

int hrs(void)
{
    struct tm *ptr;
    time_t It;
    It = time(NULL);
    ptr = localtime(&It);
    FILE *f;
    f = fopen("time.csv", "w");
    fprintf(f, "%d", ptr->tm_hour);
    fclose(f);
}

void greeting()
{
    FILE *f;
    struct time tm;
    f = fopen("time.csv", "r");
    fscanf(f,"%d", &tm.hours);
    if(tm.hours >= 6 && tm.hours <= 11)
        printf(" Доброе утро\n");
    else if(tm.hours >= 12 && tm.hours <= 16)
        printf(" Добрый день\n");
    else if(tm.hours >= 17 && tm.hours <= 21)
        printf(" Добрый вечер\n");
    else if(tm.hours >= 22 && tm.hours <= 5)
        printf(" Доброй ночи\n"); 
}

int main()
{
    system("clear");
    hrs();
    greeting();
    printf(" Выберите пунт для продолжения\n1. Ознакомиться с операторами и тарифами\n2. Подобрать тариф на основе затрат\n");
}
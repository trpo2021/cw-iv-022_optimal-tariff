#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions/comparision.h"

struct operators
{
    char operator[25];
};

struct tariffs
{
    char tf_name[25];

    char gb[20];
    int gb_value;
    
    char min[20];
    int min_value;

    char sms[20];
    int sms_value;

    char price[35];
    int price_value;
};

struct time
{
    int hours;
};

void error()
{
    system("clear");
    printf(" Вы выбрали несуществующий пункт, давайте начнем с начала\n");
    exit(0);
}

int temp(int *g, int gb, int min, int sms, int price)
{
    switch(*g) {
        case 1: {
            printf("В вашем пакете: %d гигабайт\n", gb);
            printf("Сколько гигабайт из тарифа вы используете?\n");
            int gbe;
            scanf("%d", &gbe);
            if (gbe < 0 || gbe > gb) {
                system("clear");
                printf(" Вы ввели неккоректное значение гигабайт, давайте начнем с начала\n");
                temp(g, gb, min, sms, price);
            }
            *g = *g + 1;
            temp(g, gbe, min, sms, price);
            break;
        }
        case 2: {
            printf("В вашем пакете: %d минут звонков\n", min);
            printf("Сколько минут звонков из тарифа вы используете?\n");
            int mine;
            scanf("%d", &mine);
            if (mine < 0 || mine > min) {
                system("clear");
                printf(" Вы ввели неккоректное значение минут, давайте начнем с начала\n");
                temp(g, gb, min, sms, price);
            }
            *g = *g + 1;
            temp(g, gb, mine, sms, price);
            break;
        }
        case 3: {
            printf("В вашем пакете: %d смс\n", sms);
            printf("Сколько смс сообщений из тарифа вы используете?\n");
            int smse;
            scanf("%d", &smse);
            if (smse < 0 || smse > sms) {
                system("clear");
                printf(" Вы ввели неккоректное значение смс, давайте начнем с начала\n");
                temp(g, gb, min, sms, price);
            }
            *g = *g + 1;
            temp(g, gb, min, smse, price);
            break;
        }
        case 4: {
            system("clear");
            comparison(&gb, &min, &sms);
        }
    }
    return 0;
}

int data(int b, int c)
{   
    FILE *f;
    struct tariffs pr;
    char dir[4][8]
        = {{"MTC"},
            {"TELE2"},
            {"YOTA"},
            {"MEGAFON"}};
    char path[30];
    sprintf(path,"../csv_input/%s/%d.csv", dir[b-1], c);
    f = fopen(path, "r");
    fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
    fclose(f);
    int b1 = 1;
    int *g;
    g = &b1;
    temp(g, pr.gb_value, pr.min_value, pr.sms_value, pr.price_value);
    return 0;
}

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
    if(tm.hours >= 6 && tm.hours <= 11)
        printf(" Доброе утро\n");
    else if(tm.hours >= 12 && tm.hours <= 16)
        printf(" Добрый день\n");
    else if(tm.hours >= 17 && tm.hours <= 21)
        printf(" Добрый вечер\n");
    else if(tm.hours >= 22 && tm.hours <= 5)
        printf(" Доброй ночи\n");
    fclose(f);
    remove("time.csv");
}

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

void menu()
{
    char dir[4][10]
          = {{"MTC\n"},
            {"TELE2\n"},
            {"YOTA\n"},
            {"MEGAFON\n"}};
    char path[86];
    int a;
    scanf("%d", &a);
    if(a == 1) {
        system("clear");
        printf(" Выберите оператора для просмотра тарифа\n");
        operators();
        int b;
        scanf("%d", &b);
        if (b < 1 || b > 4)
            error();
        else {
            system("clear");
            sprintf(path," Тарифы оператора %s", dir[b-1]);
            printf("%s", path);
            print1(b);
        }
    }
    else if(a == 2) {
        system("clear");
        printf(" Пожалуйста, выберите своего текущего оператора\n");
        operators();
        int b, c;
        scanf("%d", &b);
        if(b == 1) {
            system("clear");
            sprintf(path," Пожалуйста, выберите свой текущий тариф %s", dir[b-1]);
            printf("%s", path);
            print1(b);
            scanf("%d", &c);
            if(c < 1 || c > 4) {
                error();
            }
            else {
                system("clear");
                data(b,c);
            }
        }
        else if(b == 2) {
            system("clear");
            sprintf(path," Пожалуйста, выберите свой текущий тариф %s", dir[b-1]);
            printf("%s", path);
            print1(b);
            scanf("%d", &c);
            if(c < 1 || c > 4) {
                error();
            }
            else {
                system("clear");
                data(b,c);
            }
        }
        else if(b == 3) {
            system("clear");
            sprintf(path," Пожалуйста, выберите свой текущий тариф %s", dir[b-1]);
            printf("%s", path);
            print1(b);
            scanf("%d", &c);
            if(c < 1 || c > 4) {
                error();
            }
            else {
                system("clear");
                data(b,c);
            }
        }
        else if(b == 4) {
            system("clear");
            sprintf(path," Пожалуйста, выберите свой текущий тариф %s", dir[b-1]);
            printf("%s", path);
            print1(b);
            scanf("%d", &c);
            if(c < 1 || c > 4) {
                error();
            }
            else {
                system("clear");
                data(b,c);
            }
        }
        else {
            error();
        }
    }
    else {
        error();
    }
}

int main()
{
    system("clear");
    hrs();
    greeting();
    printf(" Выберите пунт для продолжения\n1. Ознакомиться с операторами и тарифами\n2. Подобрать тариф на основе затрат\n");
    menu();
}
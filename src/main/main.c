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

int temp(int *a, int gb, int min, int sms, int price)
{
    switch(*a) {
        case 1: {
            printf("В вашем пакете: %d гигабайт\n", gb);
            printf("Сколько гигабайт из тарифа вы используете?\n");
            int gbe;
            scanf("%d", &gbe);
            if (gbe < 0 || gbe > gb) {
                system("clear");
                printf(" Вы ввели неккоректное значение гигабайт, давайте начнем с начала\n");
                temp(a, gb, min, sms, price);
            }
            *a = *a + 1;
            temp(a, gbe, min, sms, price);
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
                temp(a, gb, min, sms, price);
            }
            *a = *a + 1;
            temp(a, gb, mine, sms, price);
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
                temp(a, gb, min, sms, price);
            }
            *a = *a + 1;
            temp(a, gb, min, smse, price);
            break;
        }
        case 4: {
            //system("clear");
            comparison(&gb, &min, &sms);
        }
    }
    return 0;
}

int data(int b, int c)
{   
    if (b == 1 && c == 1) {
        FILE *f;
        struct tariffs pr;
        f = fopen("../csv_input/MTC/1.csv", "r");
        fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
        fclose(f);
        int b = 1, *a;
        a = &b;
        temp(a, pr.gb_value, pr.min_value, pr.sms_value, pr.price_value);
    }
    if (b == 1 && c == 2) {
        FILE *f;
        struct tariffs pr;
        f = fopen("../csv_input/MTC/2.csv", "r");
        fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
        fclose(f);
        int b = 1, *a;
        a = &b;
        temp(a, pr.gb_value, pr.min_value, pr.sms_value, pr.price_value);
    }
    if (b == 1 && c == 3) {
        FILE *f;
        struct tariffs pr;
        f = fopen("../csv_input/MTC/3.csv", "r");
        fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
        fclose(f);
        int b = 1, *a;
        a = &b;
        temp(a, pr.gb_value, pr.min_value, pr.sms_value, pr.price_value);
    }
    if (b == 1 && c == 4) {
        FILE *f;
        struct tariffs pr;
        f = fopen("../csv_input/MTC/4.csv", "r");
        fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
        fclose(f);
        int b = 1, *a;
        a = &b;
        temp(a, pr.gb_value, pr.min_value, pr.sms_value, pr.price_value);
    }
    if (b == 2 && c == 1) {
        FILE *f;
        struct tariffs pr;
        f = fopen("../csv_input/TELE2/1.csv", "r");
        fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
        fclose(f);
        int b = 1, *a;
        a = &b;
        temp(a, pr.gb_value, pr.min_value, pr.sms_value, pr.price_value);
    }
    if (b == 2 && c == 2) {
        FILE *f;
        struct tariffs pr;
        f = fopen("../csv_input/TELE2/2.csv", "r");
        fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
        fclose(f);
        int b = 1, *a;
        a = &b;
        temp(a, pr.gb_value, pr.min_value, pr.sms_value, pr.price_value);
    }
    if (b == 2 && c == 3) {
        FILE *f;
        struct tariffs pr;
        f = fopen("../csv_input/TELE2/3.csv", "r");
        fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
        fclose(f);
        int b = 1, *a;
        a = &b;
        temp(a, pr.gb_value, pr.min_value, pr.sms_value, pr.price_value);
    }
    if (b == 2 && c == 4) {
        FILE *f;
        struct tariffs pr;
        f = fopen("../csv_input/TELE2/4.csv", "r");
        fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
        fclose(f);
        int b = 1, *a;
        a = &b;
        temp(a, pr.gb_value, pr.min_value, pr.sms_value, pr.price_value);
    }
        if (b == 3 && c == 1) {
        FILE *f;
        struct tariffs pr;
        f = fopen("../csv_input/YOTA/1.csv", "r");
        fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
        fclose(f);
        int b = 1, *a;
        a = &b;
        temp(a, pr.gb_value, pr.min_value, pr.sms_value, pr.price_value);
    }
    if (b == 3 && c == 2) {
        FILE *f;
        struct tariffs pr;
        f = fopen("../csv_input/YOTA/2.csv", "r");
        fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
        fclose(f);
        int b = 1, *a;
        a = &b;
        temp(a, pr.gb_value, pr.min_value, pr.sms_value, pr.price_value);
    }
    if (b == 3 && c == 3) {
        FILE *f;
        struct tariffs pr;
        f = fopen("../csv_input/YOTA/3.csv", "r");
        fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
        fclose(f);
        int b = 1, *a;
        a = &b;
        temp(a, pr.gb_value, pr.min_value, pr.sms_value, pr.price_value);
    }
    if (b == 3 && c == 4) {
        FILE *f;
        struct tariffs pr;
        f = fopen("../csv_input/YOTA/4.csv", "r");
        fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
        fclose(f);
        int b = 1, *a;
        a = &b;
        temp(a, pr.gb_value, pr.min_value, pr.sms_value, pr.price_value);
    }
    if (b == 4 && c == 1) {
        FILE *f;
        struct tariffs pr;
        f = fopen("../csv_input/MEGAFON/1.csv", "r");
        fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
        fclose(f);
        int b = 1, *a;
        a = &b;
        temp(a, pr.gb_value, pr.min_value, pr.sms_value, pr.price_value);
    }
    if (b == 4 && c == 2) {
        FILE *f;
        struct tariffs pr;
        f = fopen("../csv_input/MEGAFON/2.csv", "r");
        fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
        fclose(f);
        int b = 1, *a;
        a = &b;
        temp(a, pr.gb_value, pr.min_value, pr.sms_value, pr.price_value);
    }
    if (b == 4 && c == 3) {
        FILE *f;
        struct tariffs pr;
        f = fopen("../csv_input/MEGAFON/3.csv", "r");
        fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
        fclose(f);
        int b = 1, *a;
        a = &b;
        temp(a, pr.gb_value, pr.min_value, pr.sms_value, pr.price_value);
    }
    if (b == 4 && c == 4) {
        FILE *f;
        struct tariffs pr;
        f = fopen("../csv_input/MEGAFON/4.csv", "r");
        fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
        fclose(f);
        int b = 1, *a;
        a = &b;
        temp(a, pr.gb_value, pr.min_value, pr.sms_value, pr.price_value);
    }
    return 0;
}

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
    return 0;
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
    remove("time.csv"); 
}

void operators()
{
    FILE *f;
    struct operators op[4];
    f = fopen("../csv_input/operators.csv", "r");
    fscanf(f,"%s", op[0].operator);
    fscanf(f,"%s", op[1].operator);
    fscanf(f,"%s", op[2].operator);
    fscanf(f,"%s", op[3].operator);
    fclose(f);
    printf("1. %s\n", op[0].operator);
    printf("2. %s\n", op[1].operator);
    printf("3. %s\n", op[2].operator);
    printf("4. %s\n", op[3].operator);
}

void print1(int a)
{
    switch(a) {
        case 1: {
            FILE *f;
            struct tariffs pr;
            f = fopen("../csv_input/MTC/1.csv", "r");
            fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
            fclose(f);
            printf("1: %s\n%s\n%d\n%s\n%d\n%s\n%d\n%s\n%d\n\n", pr.tf_name, pr.gb, pr.gb_value, pr.min, pr.min_value, pr.sms, pr.sms_value, pr.price, pr.price_value);
            f = fopen("../csv_input/MTC/2.csv", "r");
            fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
            fclose(f);
            printf("2: %s\n%s\n%d\n%s\n%d\n%s\n%d\n%s\n%d\n\n", pr.tf_name, pr.gb, pr.gb_value, pr.min, pr.min_value, pr.sms, pr.sms_value, pr.price, pr.price_value);
            f = fopen("../csv_input/MTC/3.csv", "r");
            fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
            fclose(f);
            printf("3: %s\n%s\n%d\n%s\n%d\n%s\n%d\n%s\n%d\n\n", pr.tf_name, pr.gb, pr.gb_value, pr.min, pr.min_value, pr.sms, pr.sms_value, pr.price, pr.price_value);
            f = fopen("../csv_input/MTC/4.csv", "r");
            fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
            fclose(f);
            printf("4: %s\n%s\n%d\n%s\n%d\n%s\n%d\n%s\n%d\n\n", pr.tf_name, pr.gb, pr.gb_value, pr.min, pr.min_value, pr.sms, pr.sms_value, pr.price, pr.price_value);
            break;
        }
        case 2: {
            FILE *f;
            struct tariffs pr;
            f = fopen("../csv_input/TELE2/1.csv", "r");
            fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
            fclose(f);
            printf("1: %s\n%s\n%d\n%s\n%d\n%s\n%d\n%s\n%d\n\n", pr.tf_name, pr.gb, pr.gb_value, pr.min, pr.min_value, pr.sms, pr.sms_value, pr.price, pr.price_value);
            f = fopen("../csv_input/TELE2/2.csv", "r");
            fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
            fclose(f);
            printf("2: %s\n%s\n%d\n%s\n%d\n%s\n%d\n%s\n%d\n\n", pr.tf_name, pr.gb, pr.gb_value, pr.min, pr.min_value, pr.sms, pr.sms_value, pr.price, pr.price_value);
            f = fopen("../csv_input/TELE2/3.csv", "r");
            fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
            fclose(f);
            printf("3: %s\n%s\n%d\n%s\n%d\n%s\n%d\n%s\n%d\n\n", pr.tf_name, pr.gb, pr.gb_value, pr.min, pr.min_value, pr.sms, pr.sms_value, pr.price, pr.price_value);
            f = fopen("../csv_input/TELE2/4.csv", "r");
            fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
            fclose(f);
            printf("4: %s\n%s\n%d\n%s\n%d\n%s\n%d\n%s\n%d\n\n", pr.tf_name, pr.gb, pr.gb_value, pr.min, pr.min_value, pr.sms, pr.sms_value, pr.price, pr.price_value);
            break;
        }
        case 3: {
            FILE *f;
            struct tariffs pr;
            f = fopen("../csv_input/YOTA/1.csv", "r");
            fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
            fclose(f);
            printf("1: %s\n%s\n%d\n%s\n%d\n%s\n%d\n%s\n%d\n\n", pr.tf_name, pr.gb, pr.gb_value, pr.min, pr.min_value, pr.sms, pr.sms_value, pr.price, pr.price_value);
            f = fopen("../csv_input/YOTA/2.csv", "r");
            fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
            fclose(f);
            printf("2: %s\n%s\n%d\n%s\n%d\n%s\n%d\n%s\n%d\n\n", pr.tf_name, pr.gb, pr.gb_value, pr.min, pr.min_value, pr.sms, pr.sms_value, pr.price, pr.price_value);
            f = fopen("../csv_input/YOTA/3.csv", "r");
            fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
            fclose(f);
            printf("3: %s\n%s\n%d\n%s\n%d\n%s\n%d\n%s\n%d\n\n", pr.tf_name, pr.gb, pr.gb_value, pr.min, pr.min_value, pr.sms, pr.sms_value, pr.price, pr.price_value);
            f = fopen("../csv_input/YOTA/4.csv", "r");
            fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
            fclose(f);
            printf("4: %s\n%s\n%d\n%s\n%d\n%s\n%d\n%s\n%d\n\n", pr.tf_name, pr.gb, pr.gb_value, pr.min, pr.min_value, pr.sms, pr.sms_value, pr.price, pr.price_value);
            break;
        }
        case 4: {
            FILE *f;
            struct tariffs pr;
            f = fopen("../csv_input/MEGAFON/1.csv", "r");
            fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
            fclose(f);
            printf("1: %s\n%s\n%d\n%s\n%d\n%s\n%d\n%s\n%d\n\n", pr.tf_name, pr.gb, pr.gb_value, pr.min, pr.min_value, pr.sms, pr.sms_value, pr.price, pr.price_value);
            f = fopen("../csv_input/MEGAFON/2.csv", "r");
            fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
            fclose(f);
            printf("2: %s\n%s\n%d\n%s\n%d\n%s\n%d\n%s\n%d\n\n", pr.tf_name, pr.gb, pr.gb_value, pr.min, pr.min_value, pr.sms, pr.sms_value, pr.price, pr.price_value);
            f = fopen("../csv_input/MEGAFON/3.csv", "r");
            fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
            fclose(f);
            printf("3: %s\n%s\n%d\n%s\n%d\n%s\n%d\n%s\n%d\n\n", pr.tf_name, pr.gb, pr.gb_value, pr.min, pr.min_value, pr.sms, pr.sms_value, pr.price, pr.price_value);
            f = fopen("../csv_input/MEGAFON/4.csv", "r");
            fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
            fclose(f);
            printf("4: %s\n%s\n%d\n%s\n%d\n%s\n%d\n%s\n%d\n\n", pr.tf_name, pr.gb, pr.gb_value, pr.min, pr.min_value, pr.sms, pr.sms_value, pr.price, pr.price_value);
            break;
        }
    }
}

void menu()
{
    int a;
    scanf("%d", &a);
    if(a == 1) {
        system("clear");
        printf(" Выберите оператора для просмотра тарифа\n");
        operators();
        int b;
        scanf("%d", &b);
        if(b == 1) {
            system("clear");
            printf(" Тарифы оператора MTC\n");
            print1(b);
        }
        else if(b == 2) {
            system("clear");
            printf(" Тарифы оператора TELE2\n");
            print1(b);
        }
        else if(b == 3) {
            system("clear");
            printf(" Тарифы оператора YOTA\n");
            print1(b);
        }
        else if(b == 4) {
            system("clear");
            printf(" Тарифы оператора MEGAFON\n");
            print1(b);
        }
        else {
            error();
        }
    }
    else if(a == 2) {
        system("clear");
        printf(" Пожалуйста, выберите своего текущего оператора\n");
        operators();
        int b;
        scanf("%d", &b);
        if(b == 1) {
            system("clear");
            printf(" Пожалуйста, выберите свой текущий тариф MTC\n");
            print1(b);
            int c;
            scanf("%d", &c);
            if(c != 1 && c != 2 && c != 3 && c != 4) {
                error();
            }
            else {
                system("clear");
                data(b,c);
            }
        }
        else if(b == 2) {
            system("clear");
            printf(" Пожалуйста, выберите свой текущий тариф TELE2\n");
            print1(b);
            int c;
            scanf("%d", &c);
            if(c != 1 && c != 2 && c != 3 && c != 4) {
                error();
            }
            else {
                system("clear");
                data(b,c);
            }
        }
        else if(b == 3) {
            system("clear");
            printf(" Пожалуйста, выберите свой текущий тариф YOTA\n");
            print1(b);
            int c;
            scanf("%d", &c);
            if(c != 1 && c != 2 && c != 3 && c != 4) {
                error();
            }
            else {
                system("clear");
                data(b,c);
            }
        }
        else if(b == 4) {
            system("clear");
            printf(" Пожалуйста, выберите свой текущий тариф MEGAFON\n");
            print1(b);
            int c;
            scanf("%d", &c);
            if(c != 1 && c != 2 && c != 3 && c != 4) {
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
    //system("clear");
    hrs();
    greeting();
    printf(" Выберите пунт для продолжения\n1. Ознакомиться с операторами и тарифами\n2. Подобрать тариф на основе затрат\n");
    menu();
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int comparison (int gbe, int mine, int smse) {
    struct compareTariffs
    {
        char notNeed1[25];

        char notNeed2[20];
        int gbValue;

        char notNeed3[20];
        int minValue;

        char notNeed4[20];
        int smsValue;

        char notNeed5[35];
        int priceValue;
    };

    float gbPercent;
    float minPercent;
    float smsPercent;

    FILE *mts1, *mts2, *mts3, *mts4, *mega1, *mega2, *mega3, *mega4,
    *tele1, *tele2, *tele3, *tele4, *yota1, *yota2, *yota3, *yota4;  

    struct compareTariffs checking[16];

    //МТС
    mts1 = fopen("csv_input/MTC/1.csv", "r");
    fscanf(mts1,"%s%s%d%s%d%s%d%s%d", checking[0].notNeed1, checking[0].notNeed2, &checking[0].gbValue, 
        checking[0].notNeed3, &checking[0].minValue, checking[0].notNeed4, &checking[0].smsValue, 
        checking[0].notNeed5, &checking[0].priceValue);
    fclose(mts1);

    mts2 = fopen("csv_input/MTC/2.csv", "r");
    fscanf(mts2,"%s%s%d%s%d%s%d%s%d", checking[1].notNeed1, checking[1].notNeed2, &checking[1].gbValue, 
        checking[1].notNeed3, &checking[1].minValue, checking[1].notNeed4, &checking[1].smsValue, 
        checking[1].notNeed5, &checking[1].priceValue);
    fclose(mts2);

    mts3 = fopen("csv_input/MTC/3.csv", "r");
    fscanf(mts3,"%s%s%d%s%d%s%d%s%d", checking[2].notNeed1, checking[2].notNeed2, &checking[2].gbValue, 
        checking[2].notNeed3, &checking[2].minValue, checking[2].notNeed4, &checking[2].smsValue, 
        checking[2].notNeed5, &checking[2].priceValue);
    fclose(mts3);

    mts4 = fopen("csv_input/MTC/4.csv", "r");
    fscanf(mts4,"%s%s%d%s%d%s%d%s%d", checking[3].notNeed1, checking[3].notNeed2, &checking[3].gbValue, 
        checking[3].notNeed3, &checking[3].minValue, checking[3].notNeed4, &checking[3].smsValue, 
        checking[3].notNeed5, &checking[3].priceValue);
    fclose(mts4);

    // МЕГАФОН 
    mega1 = fopen("csv_input/MEGAFON/1.csv", "r");
    fscanf(mega1,"%s%s%d%s%d%s%d%s%d", checking[4].notNeed1, checking[4].notNeed2, &checking[4].gbValue, 
        checking[4].notNeed3, &checking[4].minValue, checking[4].notNeed4, &checking[4].smsValue, 
        checking[4].notNeed5, &checking[4].priceValue);
    fclose(mega1);

    mega2 = fopen("csv_input/MEGAFON/2.csv", "r");
    fscanf(mega2,"%s%s%d%s%d%s%d%s%d", checking[5].notNeed1, checking[5].notNeed2, &checking[5].gbValue, 
        checking[5].notNeed3, &checking[5].minValue, checking[5].notNeed4, &checking[5].smsValue, 
        checking[5].notNeed5, &checking[5].priceValue);
    fclose(mega2);

    mega3 = fopen("csv_input/MEGAFON/3.csv", "r");
    fscanf(mega3,"%s%s%d%s%d%s%d%s%d", checking[6].notNeed1, checking[6].notNeed2, &checking[6].gbValue, 
        checking[6].notNeed3, &checking[6].minValue, checking[6].notNeed4, &checking[6].smsValue, 
        checking[6].notNeed5, &checking[6].priceValue);
    fclose(mega3);

    mega4 = fopen("csv_input/MEGAFON/4.csv", "r");
    fscanf(mega4,"%s%s%d%s%d%s%d%s%d", checking[7].notNeed1, checking[7].notNeed2, &checking[7].gbValue, 
        checking[7].notNeed3, &checking[7].minValue, checking[7].notNeed4, &checking[7].smsValue, 
        checking[7].notNeed5, &checking[7].priceValue);
    fclose(mega4);

    //ТЕЛЕ2
    tele1 = fopen("csv_input/TELE2/1.csv", "r");
    fscanf(tele1,"%s%s%d%s%d%s%d%s%d", checking[8].notNeed1, checking[8].notNeed2, &checking[8].gbValue, 
        checking[8].notNeed3, &checking[8].minValue, checking[8].notNeed4, &checking[8].smsValue, 
        checking[8].notNeed5, &checking[8].priceValue);
    fclose(tele1);

    tele2 = fopen("csv_input/TELE2/2.csv", "r");
    fscanf(tele2,"%s%s%d%s%d%s%d%s%d", checking[9].notNeed1, checking[9].notNeed2, &checking[9].gbValue, 
        checking[9].notNeed3, &checking[9].minValue, checking[9].notNeed4, &checking[9].smsValue, 
        checking[9].notNeed5, &checking[9].priceValue);
    fclose(tele2);

    tele3 = fopen("csv_input/TELE2/3.csv", "r");
    fscanf(tele3,"%s%s%d%s%d%s%d%s%d", checking[10].notNeed1, checking[10].notNeed2, &checking[10].gbValue, 
        checking[10].notNeed3, &checking[10].minValue, checking[10].notNeed4, &checking[10].smsValue, 
        checking[10].notNeed5, &checking[10].priceValue);
    fclose(tele3);

    tele4 = fopen("csv_input/TELE2/4.csv", "r");
    fscanf(tele4,"%s%s%d%s%d%s%d%s%d", checking[11].notNeed1, checking[11].notNeed2, &checking[11].gbValue, 
        checking[11].notNeed3, &checking[11].minValue, checking[11].notNeed4, &checking[11].smsValue, 
        checking[11].notNeed5, &checking[11].priceValue);
    fclose(tele4);

    //YOTA
    yota1 = fopen("csv_input/YOTA/1.csv", "r");
    fscanf(yota1,"%s%s%d%s%d%s%d%s%d", checking[12].notNeed1, checking[12].notNeed2, &checking[12].gbValue, 
        checking[12].notNeed3, &checking[12].minValue, checking[12].notNeed4, &checking[12].smsValue, 
        checking[12].notNeed5, &checking[12].priceValue);
    fclose(yota1);

    yota2 = fopen("csv_input/YOTA/2.csv", "r");
    fscanf(yota2,"%s%s%d%s%d%s%d%s%d", checking[13].notNeed1, checking[13].notNeed2, &checking[13].gbValue, 
        checking[13].notNeed3, &checking[13].minValue, checking[13].notNeed4, &checking[13].smsValue, 
        checking[13].notNeed5, &checking[13].priceValue);
    fclose(yota2);

    yota3 = fopen("csv_input/YOTA/3.csv", "r");
    fscanf(yota3,"%s%s%d%s%d%s%d%s%d", checking[14].notNeed1, checking[14].notNeed2, &checking[14].gbValue, 
        checking[14].notNeed3, &checking[14].minValue, checking[14].notNeed4, &checking[14].smsValue, 
        checking[14].notNeed5, &checking[14].priceValue);
    fclose(yota3);

    yota4 = fopen("csv_input/YOTA/4.csv", "r");
    fscanf(yota4,"%s%s%d%s%d%s%d%s%d", checking[15].notNeed1, checking[15].notNeed2, &checking[15].gbValue, 
        checking[15].notNeed3, &checking[15].minValue, checking[15].notNeed4, &checking[15].smsValue, 
        checking[15].notNeed5, &checking[15].priceValue);
    fclose(yota4);
    
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
            temp(a, gb, min, sms, price);
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
            temp(a, gb, min, sms, price);
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
            temp(a, gb, min, sms, price);
            break;
        }
        case 4: {
            system("clear");
        }
    }
}

int data(int b, int c)
{   
    if (b == 1 && c == 1) {
        FILE *f;
        struct tariffs pr;
        f = fopen("csv_input/MTC/1.csv", "r");
        fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
        fclose(f);
        int b = 1, *a;
        a = &b;
        temp(a, pr.gb_value, pr.min_value, pr.sms_value, pr.price_value);
    }
    if (b == 1 && c == 2) {
        FILE *f;
        struct tariffs pr;
        f = fopen("csv_input/MTC/2.csv", "r");
        fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
        fclose(f);
        int b = 1, *a;
        a = &b;
        temp(a, pr.gb_value, pr.min_value, pr.sms_value, pr.price_value);
    }
    if (b == 1 && c == 3) {
        FILE *f;
        struct tariffs pr;
        f = fopen("csv_input/MTC/3.csv", "r");
        fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
        fclose(f);
        int b = 1, *a;
        a = &b;
        temp(a, pr.gb_value, pr.min_value, pr.sms_value, pr.price_value);
    }
    if (b == 1 && c == 4) {
        FILE *f;
        struct tariffs pr;
        f = fopen("csv_input/MTC/4.csv", "r");
        fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
        fclose(f);
        int b = 1, *a;
        a = &b;
        temp(a, pr.gb_value, pr.min_value, pr.sms_value, pr.price_value);
    }
    if (b == 2 && c == 1) {
        FILE *f;
        struct tariffs pr;
        f = fopen("csv_input/TELE2/1.csv", "r");
        fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
        fclose(f);
        int b = 1, *a;
        a = &b;
        temp(a, pr.gb_value, pr.min_value, pr.sms_value, pr.price_value);
    }
    if (b == 2 && c == 2) {
        FILE *f;
        struct tariffs pr;
        f = fopen("csv_input/TELE2/2.csv", "r");
        fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
        fclose(f);
        int b = 1, *a;
        a = &b;
        temp(a, pr.gb_value, pr.min_value, pr.sms_value, pr.price_value);
    }
    if (b == 2 && c == 3) {
        FILE *f;
        struct tariffs pr;
        f = fopen("csv_input/TELE2/3.csv", "r");
        fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
        fclose(f);
        int b = 1, *a;
        a = &b;
        temp(a, pr.gb_value, pr.min_value, pr.sms_value, pr.price_value);
    }
    if (b == 2 && c == 4) {
        FILE *f;
        struct tariffs pr;
        f = fopen("csv_input/TELE2/4.csv", "r");
        fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
        fclose(f);
        int b = 1, *a;
        a = &b;
        temp(a, pr.gb_value, pr.min_value, pr.sms_value, pr.price_value);
    }
        if (b == 3 && c == 1) {
        FILE *f;
        struct tariffs pr;
        f = fopen("csv_input/YOTA/1.csv", "r");
        fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
        fclose(f);
        int b = 1, *a;
        a = &b;
        temp(a, pr.gb_value, pr.min_value, pr.sms_value, pr.price_value);
    }
    if (b == 3 && c == 2) {
        FILE *f;
        struct tariffs pr;
        f = fopen("csv_input/YOTA/2.csv", "r");
        fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
        fclose(f);
        int b = 1, *a;
        a = &b;
        temp(a, pr.gb_value, pr.min_value, pr.sms_value, pr.price_value);
    }
    if (b == 3 && c == 3) {
        FILE *f;
        struct tariffs pr;
        f = fopen("csv_input/YOTA/3.csv", "r");
        fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
        fclose(f);
        int b = 1, *a;
        a = &b;
        temp(a, pr.gb_value, pr.min_value, pr.sms_value, pr.price_value);
    }
    if (b == 3 && c == 4) {
        FILE *f;
        struct tariffs pr;
        f = fopen("csv_input/YOTA/4.csv", "r");
        fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
        fclose(f);
        int b = 1, *a;
        a = &b;
        temp(a, pr.gb_value, pr.min_value, pr.sms_value, pr.price_value);
    }
    if (b == 4 && c == 1) {
        FILE *f;
        struct tariffs pr;
        f = fopen("csv_input/MEGAFON/1.csv", "r");
        fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
        fclose(f);
        int b = 1, *a;
        a = &b;
        temp(a, pr.gb_value, pr.min_value, pr.sms_value, pr.price_value);
    }
    if (b == 4 && c == 2) {
        FILE *f;
        struct tariffs pr;
        f = fopen("csv_input/MEGAFON/2.csv", "r");
        fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
        fclose(f);
        int b = 1, *a;
        a = &b;
        temp(a, pr.gb_value, pr.min_value, pr.sms_value, pr.price_value);
    }
    if (b == 4 && c == 3) {
        FILE *f;
        struct tariffs pr;
        f = fopen("csv_input/MEGAFON/3.csv", "r");
        fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
        fclose(f);
        int b = 1, *a;
        a = &b;
        temp(a, pr.gb_value, pr.min_value, pr.sms_value, pr.price_value);
    }
    if (b == 4 && c == 4) {
        FILE *f;
        struct tariffs pr;
        f = fopen("csv_input/MEGAFON/4.csv", "r");
        fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
        fclose(f);
        int b = 1, *a;
        a = &b;
        temp(a, pr.gb_value, pr.min_value, pr.sms_value, pr.price_value);
    }
}

int hrs(void)
{
    struct tm *ptr;
    time_t It;
    It = time(NULL);
    ptr = localtime(&It);
    FILE *f;
    f = fopen("csv_input/time.csv", "w");
    fprintf(f, "%d", ptr->tm_hour);
    fclose(f);
}

void greeting()
{
    FILE *f;
    struct time tm;
    f = fopen("csv_input/time.csv", "r");
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

void operators()
{
    FILE *f;
    struct operators op[4];
    f = fopen("csv_input/operators.csv", "r");
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
            f = fopen("csv_input/MTC/1.csv", "r");
            fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
            fclose(f);
            printf("1: %s\n%s\n%d\n%s\n%d\n%s\n%d\n%s\n%d\n\n", pr.tf_name, pr.gb, pr.gb_value, pr.min, pr.min_value, pr.sms, pr.sms_value, pr.price, pr.price_value);
            f = fopen("csv_input/MTC/2.csv", "r");
            fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
            fclose(f);
            printf("2: %s\n%s\n%d\n%s\n%d\n%s\n%d\n%s\n%d\n\n", pr.tf_name, pr.gb, pr.gb_value, pr.min, pr.min_value, pr.sms, pr.sms_value, pr.price, pr.price_value);
            f = fopen("csv_input/MTC/3.csv", "r");
            fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
            fclose(f);
            printf("3: %s\n%s\n%d\n%s\n%d\n%s\n%d\n%s\n%d\n\n", pr.tf_name, pr.gb, pr.gb_value, pr.min, pr.min_value, pr.sms, pr.sms_value, pr.price, pr.price_value);
            f = fopen("csv_input/MTC/4.csv", "r");
            fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
            fclose(f);
            printf("4: %s\n%s\n%d\n%s\n%d\n%s\n%d\n%s\n%d\n\n", pr.tf_name, pr.gb, pr.gb_value, pr.min, pr.min_value, pr.sms, pr.sms_value, pr.price, pr.price_value);
            break;
        }
        case 2: {
            FILE *f;
            struct tariffs pr;
            f = fopen("csv_input/TELE2/1.csv", "r");
            fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
            fclose(f);
            printf("1: %s\n%s\n%d\n%s\n%d\n%s\n%d\n%s\n%d\n\n", pr.tf_name, pr.gb, pr.gb_value, pr.min, pr.min_value, pr.sms, pr.sms_value, pr.price, pr.price_value);
            f = fopen("csv_input/TELE2/2.csv", "r");
            fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
            fclose(f);
            printf("2: %s\n%s\n%d\n%s\n%d\n%s\n%d\n%s\n%d\n\n", pr.tf_name, pr.gb, pr.gb_value, pr.min, pr.min_value, pr.sms, pr.sms_value, pr.price, pr.price_value);
            f = fopen("csv_input/TELE2/3.csv", "r");
            fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
            fclose(f);
            printf("3: %s\n%s\n%d\n%s\n%d\n%s\n%d\n%s\n%d\n\n", pr.tf_name, pr.gb, pr.gb_value, pr.min, pr.min_value, pr.sms, pr.sms_value, pr.price, pr.price_value);
            f = fopen("csv_input/TELE2/4.csv", "r");
            fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
            fclose(f);
            printf("4: %s\n%s\n%d\n%s\n%d\n%s\n%d\n%s\n%d\n\n", pr.tf_name, pr.gb, pr.gb_value, pr.min, pr.min_value, pr.sms, pr.sms_value, pr.price, pr.price_value);
            break;
        }
        case 3: {
            FILE *f;
            struct tariffs pr;
            f = fopen("csv_input/YOTA/1.csv", "r");
            fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
            fclose(f);
            printf("1: %s\n%s\n%d\n%s\n%d\n%s\n%d\n%s\n%d\n\n", pr.tf_name, pr.gb, pr.gb_value, pr.min, pr.min_value, pr.sms, pr.sms_value, pr.price, pr.price_value);
            f = fopen("csv_input/YOTA/2.csv", "r");
            fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
            fclose(f);
            printf("2: %s\n%s\n%d\n%s\n%d\n%s\n%d\n%s\n%d\n\n", pr.tf_name, pr.gb, pr.gb_value, pr.min, pr.min_value, pr.sms, pr.sms_value, pr.price, pr.price_value);
            f = fopen("csv_input/YOTA/3.csv", "r");
            fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
            fclose(f);
            printf("3: %s\n%s\n%d\n%s\n%d\n%s\n%d\n%s\n%d\n\n", pr.tf_name, pr.gb, pr.gb_value, pr.min, pr.min_value, pr.sms, pr.sms_value, pr.price, pr.price_value);
            f = fopen("csv_input/YOTA/4.csv", "r");
            fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
            fclose(f);
            printf("4: %s\n%s\n%d\n%s\n%d\n%s\n%d\n%s\n%d\n\n", pr.tf_name, pr.gb, pr.gb_value, pr.min, pr.min_value, pr.sms, pr.sms_value, pr.price, pr.price_value);
            break;
        }
        case 4: {
            FILE *f;
            struct tariffs pr;
            f = fopen("csv_input/MEGAFON/1.csv", "r");
            fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
            fclose(f);
            printf("1: %s\n%s\n%d\n%s\n%d\n%s\n%d\n%s\n%d\n\n", pr.tf_name, pr.gb, pr.gb_value, pr.min, pr.min_value, pr.sms, pr.sms_value, pr.price, pr.price_value);
            f = fopen("csv_input/MEGAFON/2.csv", "r");
            fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
            fclose(f);
            printf("2: %s\n%s\n%d\n%s\n%d\n%s\n%d\n%s\n%d\n\n", pr.tf_name, pr.gb, pr.gb_value, pr.min, pr.min_value, pr.sms, pr.sms_value, pr.price, pr.price_value);
            f = fopen("csv_input/MEGAFON/3.csv", "r");
            fscanf(f,"%s%s%d%s%d%s%d%s%d", pr.tf_name, pr.gb, &pr.gb_value, pr.min, &pr.min_value, pr.sms, &pr.sms_value, pr.price, &pr.price_value);
            fclose(f);
            printf("3: %s\n%s\n%d\n%s\n%d\n%s\n%d\n%s\n%d\n\n", pr.tf_name, pr.gb, pr.gb_value, pr.min, pr.min_value, pr.sms, pr.sms_value, pr.price, pr.price_value);
            f = fopen("csv_input/MEGAFON/4.csv", "r");
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
    system("clear");
    hrs();
    greeting();
    printf(" Выберите пунт для продолжения\n1. Ознакомиться с операторами и тарифами\n2. Подобрать тариф на основе затрат\n");
    menu();
}
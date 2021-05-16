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
        char tname[25];

        char gbHead[20];
        int gbValue;

        char minHead[20];
        int minValue;

        char smsHead[20];
        int smsValue;

        char priceHead[35];
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
    fscanf(mts1,"%s%s%d%s%d%s%d%s%d", checking[0].tname, checking[0].gbHead, &checking[0].gbValue, 
        checking[0].minHead, &checking[0].minValue, checking[0].smsHead, &checking[0].smsValue, 
        checking[0].priceHead, &checking[0].priceValue);
    fclose(mts1);

    mts2 = fopen("csv_input/MTC/2.csv", "r");
    fscanf(mts2,"%s%s%d%s%d%s%d%s%d", checking[1].tname, checking[1].gbHead, &checking[1].gbValue, 
        checking[1].minHead, &checking[1].minValue, checking[1].smsHead, &checking[1].smsValue, 
        checking[1].priceHead, &checking[1].priceValue);
    fclose(mts2);

    mts3 = fopen("csv_input/MTC/3.csv", "r");
    fscanf(mts3,"%s%s%d%s%d%s%d%s%d", checking[2].tname, checking[2].gbHead, &checking[2].gbValue, 
        checking[2].minHead, &checking[2].minValue, checking[2].smsHead, &checking[2].smsValue, 
        checking[2].priceHead, &checking[2].priceValue);
    fclose(mts3);

    mts4 = fopen("csv_input/MTC/4.csv", "r");
    fscanf(mts4,"%s%s%d%s%d%s%d%s%d", checking[3].tname, checking[3].gbHead, &checking[3].gbValue, 
        checking[3].minHead, &checking[3].minValue, checking[3].smsHead, &checking[3].smsValue, 
        checking[3].priceHead, &checking[3].priceValue);
    fclose(mts4);

    // МЕГАФОН 
    mega1 = fopen("csv_input/MEGAFON/1.csv", "r");
    fscanf(mega1,"%s%s%d%s%d%s%d%s%d", checking[4].tname, checking[4].gbHead, &checking[4].gbValue, 
        checking[4].minHead, &checking[4].minValue, checking[4].smsHead, &checking[4].smsValue, 
        checking[4].priceHead, &checking[4].priceValue);
    fclose(mega1);

    mega2 = fopen("csv_input/MEGAFON/2.csv", "r");
    fscanf(mega2,"%s%s%d%s%d%s%d%s%d", checking[5].tname, checking[5].gbHead, &checking[5].gbValue, 
        checking[5].minHead, &checking[5].minValue, checking[5].smsHead, &checking[5].smsValue, 
        checking[5].priceHead, &checking[5].priceValue);
    fclose(mega2);

    mega3 = fopen("csv_input/MEGAFON/3.csv", "r");
    fscanf(mega3,"%s%s%d%s%d%s%d%s%d", checking[6].tname, checking[6].gbHead, &checking[6].gbValue, 
        checking[6].minHead, &checking[6].minValue, checking[6].smsHead, &checking[6].smsValue, 
        checking[6].priceHead, &checking[6].priceValue);
    fclose(mega3);

    mega4 = fopen("csv_input/MEGAFON/4.csv", "r");
    fscanf(mega4,"%s%s%d%s%d%s%d%s%d", checking[7].tname, checking[7].gbHead, &checking[7].gbValue, 
        checking[7].minHead, &checking[7].minValue, checking[7].smsHead, &checking[7].smsValue, 
        checking[7].priceHead, &checking[7].priceValue);
    fclose(mega4);

    //ТЕЛЕ2
    tele1 = fopen("csv_input/TELE2/1.csv", "r");
    fscanf(tele1,"%s%s%d%s%d%s%d%s%d", checking[8].tname, checking[8].gbHead, &checking[8].gbValue, 
        checking[8].minHead, &checking[8].minValue, checking[8].smsHead, &checking[8].smsValue, 
        checking[8].priceHead, &checking[8].priceValue);
    fclose(tele1);

    tele2 = fopen("csv_input/TELE2/2.csv", "r");
    fscanf(tele2,"%s%s%d%s%d%s%d%s%d", checking[9].tname, checking[9].gbHead, &checking[9].gbValue, 
        checking[9].minHead, &checking[9].minValue, checking[9].smsHead, &checking[9].smsValue, 
        checking[9].priceHead, &checking[9].priceValue);
    fclose(tele2);

    tele3 = fopen("csv_input/TELE2/3.csv", "r");
    fscanf(tele3,"%s%s%d%s%d%s%d%s%d", checking[10].tname, checking[10].gbHead, &checking[10].gbValue, 
        checking[10].minHead, &checking[10].minValue, checking[10].smsHead, &checking[10].smsValue, 
        checking[10].priceHead, &checking[10].priceValue);
    fclose(tele3);

    tele4 = fopen("csv_input/TELE2/4.csv", "r");
    fscanf(tele4,"%s%s%d%s%d%s%d%s%d", checking[11].tname, checking[11].gbHead, &checking[11].gbValue, 
        checking[11].minHead, &checking[11].minValue, checking[11].smsHead, &checking[11].smsValue, 
        checking[11].priceHead, &checking[11].priceValue);
    fclose(tele4);

    //YOTA
    yota1 = fopen("csv_input/YOTA/1.csv", "r");
    fscanf(yota1,"%s%s%d%s%d%s%d%s%d", checking[12].tname, checking[12].gbHead, &checking[12].gbValue, 
        checking[12].minHead, &checking[12].minValue, checking[12].smsHead, &checking[12].smsValue, 
        checking[12].priceHead, &checking[12].priceValue);
    fclose(yota1);

    yota2 = fopen("csv_input/YOTA/2.csv", "r");
    fscanf(yota2,"%s%s%d%s%d%s%d%s%d", checking[13].tname, checking[13].gbHead, &checking[13].gbValue, 
        checking[13].minHead, &checking[13].minValue, checking[13].smsHead, &checking[13].smsValue, 
        checking[13].priceHead, &checking[13].priceValue);
    fclose(yota2);

    yota3 = fopen("csv_input/YOTA/3.csv", "r");
    fscanf(yota3,"%s%s%d%s%d%s%d%s%d", checking[14].tname, checking[14].gbHead, &checking[14].gbValue, 
        checking[14].minHead, &checking[14].minValue, checking[14].smsHead, &checking[14].smsValue, 
        checking[14].priceHead, &checking[14].priceValue);
    fclose(yota3);

    yota4 = fopen("csv_input/YOTA/4.csv", "r");
    fscanf(yota4,"%s%s%d%s%d%s%d%s%d", checking[15].tname, checking[15].gbHead, &checking[15].gbValue, 
        checking[15].minHead, &checking[15].minValue, checking[15].smsHead, &checking[15].smsValue, 
        checking[15].priceHead, &checking[15].priceValue);
    fclose(yota4);

    struct compareTariffs out[16];
    unsigned int counter;
    unsigned int i;

    int j = -1;
    for (i = 0; i < 16; i++) {
        gbPercent = ((float) gbe / (float) checking[i].gbValue)*100;
        minPercent = ((float) mine / (float) checking[i].minValue)*100;
        smsPercent = ((float) smse / (float) checking[i].smsValue)*100;

        if ((gbPercent < 100) && (gbPercent > 50)) {
            counter++;
        }
        if ((minPercent < 100) && (minPercent > 10)) {
            counter++;
        }
        if ((smsPercent < 100)) {
            counter++;
        }
        if (counter == 3) {
            //need to fix
            j++;
            out[j] = checking[i];
        }

        //need to fix
        printf("Рекомендуем тарифы: \n");
        for (i = 0; i < j; i++) {
            printf("Тариф: %s\n Гигабайт: %d\n Минут: %d\n СМС: %d\n Цена: %d\n\n", out[i].tname, out[i].gbValue, 
                out[i].minValue, out[i].smsValue, out[i].priceValue);
        }
    }
    
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
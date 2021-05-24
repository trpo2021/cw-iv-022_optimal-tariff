#include "lib.h"

int temp(int* g, int gb, int min, int sms, int price)
{
    switch (*g) {
    case 1: {
        printf("В вашем пакете: %d гигабайт\n", gb);
        printf("Сколько гигабайт из тарифа вы используете?\n");
        int gbe;
        gbe = check(gb);
        if (gbe < 0 || gbe > gb) {
            system("clear");
            printf(" Вы ввели неккоректное значение гигабайт, давайте начнем с "
                   "начала\n");
            temp(g, gb, min, sms, price);
        }
        system("clear");
        *g = *g + 1;
        temp(g, gbe, min, sms, price);
        break;
    }
    case 2: {
        printf("В вашем пакете: %d минут звонков\n", min);
        printf("Сколько минут звонков из тарифа вы используете?\n");
        int mine;
        mine = check(min);
        if (mine < 0 || mine > min) {
            system("clear");
            printf(" Вы ввели неккоректное значение минут, давайте начнем с "
                   "начала\n");
            temp(g, gb, min, sms, price);
        }
        system("clear");
        *g = *g + 1;
        temp(g, gb, mine, sms, price);
        break;
    }
    case 3: {
        printf("В вашем пакете: %d смс\n", sms);
        printf("Сколько смс сообщений из тарифа вы используете?\n");
        int smse;
        smse = check(sms);
        if (smse < 0 || smse > sms) {
            system("clear");
            printf(" Вы ввели неккоректное значение смс, давайте начнем с "
                   "начала\n");
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
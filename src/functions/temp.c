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
            return 0;
        }
        system("clear");
        *g = *g + 1;
        temp(g, gbe, min, sms, price);
        return 0;
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
            return 0;
        }
        system("clear");
        *g = *g + 1;
        temp(g, gb, mine, sms, price);
        return 0;
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
            return 0;
        }
        *g = *g + 1;
        temp(g, gb, min, smse, price);
        return 0;
    }
    case 4: {
        printf("Стоимость вашего пакета: %d\n", price);
        printf("Какую стоимость вы предпочитаете?Максимальная возможная стоимость тарифа - 520р\n");
        int pricee = check(500);
        if(pricee == -1) {
            system("clear");
            printf(" Вы ввели неккоректное значение смс, давайте начнем с "
                   "начала\n");
            temp(g, gb, min, sms, price);
        }
        if (pricee == 0) {
            system("clear");
            printf("Бесплатных тарифов не найдено, давайте начнем заново\n");
            temp(g, gb, min, sms, price);
        }
        *g = *g + 1;
        temp(g, gb, min, sms, pricee);
        break;
    }
    case 5: {
        system("clear");
        comparison(&gb, &min, &sms, &price);
    }
    }
    return 0;
}
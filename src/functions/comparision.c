#include "lib.h"

int comparison(int* gbe, int* mine, int* smse, int* price)
{
    struct compareTariffs {
        char* operatorName[10];
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

    int i;
    float gbPercent, minPercent, smsPercent;

    FILE* tariff;

    struct compareTariffs checking[16];
    char path[50];
    char csv[4] = {1, 2, 3, 4};
    char operators[4][8] = {"MTC", "MEGAFON", "YOTA", "TELE2"};
    for (i = 0; i < 4; i++) {
        *checking[i].operatorName = operators[0];
        sprintf(path, "../csv_input/%s/%d.csv", operators[0], csv[i]);
        tariff = fopen(path, "r");
        fscanf(tariff,
               "%s%s%d%s%d%s%d%s%d",
               checking[i].tname,
               checking[i].gbHead,
               &checking[i].gbValue,
               checking[i].minHead,
               &checking[i].minValue,
               checking[i].smsHead,
               &checking[i].smsValue,
               checking[i].priceHead,
               &checking[i].priceValue);
        fclose(tariff);
    }

    for (i = 4; i < 8; i++) {
        *checking[i].operatorName = operators[1];
        sprintf(path, "../csv_input/%s/%d.csv", operators[1], csv[i - 4]);
        tariff = fopen(path, "r");
        fscanf(tariff,
               "%s%s%d%s%d%s%d%s%d",
               checking[i].tname,
               checking[i].gbHead,
               &checking[i].gbValue,
               checking[i].minHead,
               &checking[i].minValue,
               checking[i].smsHead,
               &checking[i].smsValue,
               checking[i].priceHead,
               &checking[i].priceValue);
        fclose(tariff);
    }
    for (i = 8; i < 12; i++) {
        *checking[i].operatorName = operators[2];
        sprintf(path, "../csv_input/%s/%d.csv", operators[2], csv[i - 8]);
        tariff = fopen(path, "r");
        fscanf(tariff,
               "%s%s%d%s%d%s%d%s%d",
               checking[i].tname,
               checking[i].gbHead,
               &checking[i].gbValue,
               checking[i].minHead,
               &checking[i].minValue,
               checking[i].smsHead,
               &checking[i].smsValue,
               checking[i].priceHead,
               &checking[i].priceValue);
        fclose(tariff);
    }

    for (i = 12; i < 16; i++) {
        *checking[i].operatorName = operators[3];
        sprintf(path, "../csv_input/%s/%d.csv", operators[3], csv[i - 12]);
        tariff = fopen(path, "r");
        fscanf(tariff,
               "%s%s%d%s%d%s%d%s%d",
               checking[i].tname,
               checking[i].gbHead,
               &checking[i].gbValue,
               checking[i].minHead,
               &checking[i].minValue,
               checking[i].smsHead,
               &checking[i].smsValue,
               checking[i].priceHead,
               &checking[i].priceValue);
        fclose(tariff);
    }

    struct compareTariffs minRecommend;
    struct compareTariffs minRecommendReserve;
    unsigned int counter;

    for (i = 0; i < 16; i++) {
        if (i == 0) {
            minRecommend.gbValue = 1000;
            minRecommend.smsValue = 1000;
            minRecommend.minValue = 1000;
            minRecommend.priceValue = 1000;
        }
        gbPercent = ((float)*gbe / (float)checking[i].gbValue) * 100;
        minPercent = ((float)*mine / (float)checking[i].minValue) * 100;
        smsPercent = ((float)*smse / (float)checking[i].smsValue) * 100;

        if ((gbPercent < 100) && (checking[i].gbValue < minRecommend.gbValue)) {
            counter++;
        }
        if ((minPercent < 100)
            && (checking[i].minValue < minRecommend.minValue)) {
            counter++;
        }
        if ((smsPercent < 100)
            && (checking[i].smsValue < minRecommend.smsValue)) {
            counter++;
        }
        if ((checking[i].priceValue <= *price + 30)
            && (checking[i].priceValue < minRecommend.priceValue)) {
            counter++;
        }

        if (counter == 4) {
            minRecommend = checking[i];
        } else if (
                (counter == 3) && (checking[i].priceValue <= *price + 90)
                && (checking[i].minValue < *mine)
                && (checking[i].gbValue < *gbe)
                && (checking[i].smsValue < *smse)) {
            minRecommendReserve = checking[i];
        }
        counter = 0;
        gbPercent = 0;
        minPercent = 0;
        smsPercent = 0;
    }

    if ((minRecommend.gbValue == 1000) && (minRecommend.minValue == 1000)
        && (minRecommend.smsValue == 1000) && (minRecommendReserve.gbValue < 51)
        && (minRecommendReserve.gbValue > 0)) {
        printf("Тариф: %s\n Гигабайт: %d\n Минут: %d\n СМС: %d\n "
               "Цена: %d\n\nОператор: %s\n",
               minRecommendReserve.tname,
               minRecommendReserve.gbValue,
               minRecommendReserve.minValue,
               minRecommendReserve.smsValue,
               minRecommendReserve.priceValue,
               *minRecommendReserve.operatorName);
    } else if (
            ((minRecommendReserve.gbValue > 51)
             || (minRecommendReserve.gbValue <= 0))
            && (minRecommend.gbValue == 1000)) {
        printf("Более подходящих тарифов в нашей базе не найдено. Возможно, "
               "стоит указать цену больше \n");
    } else {
        printf("Тариф: %s\n Гигабайт: %d\n Минут: %d\n СМС: %d\n Цена: "
               "%d\n\nОператор: %s\n",
               minRecommend.tname,
               minRecommend.gbValue,
               minRecommend.minValue,
               minRecommend.smsValue,
               minRecommend.priceValue,
               *minRecommend.operatorName);
    }
    return 0;
}
#include "lib.h"

int comparison(int* gbe, int* mine, int* smse, int* price)
{
    struct compareTariffs {
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
    char path[30];
    char csv[4] = {1, 2, 3, 4};
    for (i = 0; i < 4; i++) {
        sprintf(path, "../csv_input/MTC/%d.csv", csv[i]);
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
        sprintf(path, "../csv_input/TELE2/%d.csv", csv[i - 4]);
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
        sprintf(path, "../csv_input/MEGAFON/%d.csv", csv[i - 8]);
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
        sprintf(path, "../csv_input/YOTA/%d.csv", csv[i - 12]);
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

        int different = minRecommend.priceValue - checking[i].priceValue;
        if (different < 0) {
            different *= -1;
        }

        if ((gbPercent < 100) && (checking[i].gbValue < minRecommend.gbValue)) {
            counter++;
        }
        if ((minPercent = 100)
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
            counter = 0;
            gbPercent = 0;
            minPercent = 0;
            smsPercent = 0;
        } else if (counter == 3) {
            minRecommendReserve = checking[i];
            counter = 0;
            gbPercent = 0;
            minPercent = 0;
            smsPercent = 0;
        } else {
            counter = 0;
            gbPercent = 0;
            minPercent = 0;
            smsPercent = 0;
        }
    }

    if ((minRecommend.gbValue == 1000) || (minRecommend.minValue == 1000)
        || (minRecommend.smsValue == 1000)) {
        printf("Тариф (резерв): %s\n Гигабайт: %d\n Минут: %d\n СМС: %d\n Цена: %d\n\n",
               minRecommendReserve.tname,
               minRecommendReserve.gbValue,
               minRecommendReserve.minValue,
               minRecommendReserve.smsValue,
               minRecommendReserve.priceValue);
    } else {
        printf("Тариф: %s\n Гигабайт: %d\n Минут: %d\n СМС: %d\n Цена: %d\n\n",
               minRecommend.tname,
               minRecommend.gbValue,
               minRecommend.minValue,
               minRecommend.smsValue,
               minRecommend.priceValue);
    }
    return 0;
}
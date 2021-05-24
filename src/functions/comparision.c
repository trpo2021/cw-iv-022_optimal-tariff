#include "lib.h"

int comparison(int* gbe, int* mine, int* smse)
{
    printf("gbe = %d", *gbe);
    printf("mine = %d", *mine);
    printf("smse = %d", *smse);
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
    float gbPercent;
    float minPercent;
    float smsPercent;

    FILE* tariff;

    struct compareTariffs checking[16];
    //char operators[4] = {"MTC", "TELE2", "YOTA", "MEGAFON"};
    int csv[4] = {1, 2, 3, 4};
    char path[50];
    //MTC
    for (i = 0; i < 4; i++) {
            sprintf(path, "../csv_input/MTC/%c", csv[i]);
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
    //TELE2
    for (i = 4; i < 8; i++) {
            sprintf(path, "../csv_input/TELE2/%c", csv[i-4]);
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
            sprintf(path, "../csv_input/YOTA/%c", csv[i-8]);
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
            sprintf(path, "../csv_input/MEGAFON/%c", csv[i-12]);
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
    unsigned int counter;

    for (i = 0; i < 16; i++) {
        if (i == 0) {
            minRecommend.gbValue = 1000;
            minRecommend.smsValue = 1000;
            minRecommend.minValue = 1000;
        }
        gbPercent = ((float)*gbe / (float)checking[i].gbValue) * 100;
        minPercent = ((float)*mine / (float)checking[i].minValue) * 100;
        smsPercent = ((float)*smse / (float)checking[i].smsValue) * 100;
        if ((gbPercent < 100) && (checking[i].gbValue < minRecommend.gbValue)
            && (gbPercent > 20)) {
            counter++;
        }
        if ((minPercent < 100) && (checking[i].minValue < minRecommend.minValue)
            && (minPercent > 20)) {
            counter++;
        }
        if ((smsPercent < 100) && (checking[i].smsValue < minRecommend.smsValue)
            && (smsPercent > 20)) {
            counter++;
        }

        if (counter == 3) {
            minRecommend = checking[i];
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

    printf("Тариф: %s\n Гигабайт: %d\n Минут: %d\n СМС: %d\n Цена: %d\n\n",
           minRecommend.tname,
           minRecommend.gbValue,
           minRecommend.minValue,
           minRecommend.smsValue,
           minRecommend.priceValue);

    return 0;
}
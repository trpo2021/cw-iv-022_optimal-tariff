#include "lib.h"

int comparison(int* gbe, int* mine, int* smse)
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
    float gbPercent;
    float minPercent;
    float smsPercent;

    FILE* tariff;

    struct compareTariffs checking[16];
    char operators[4] = {"MTC", "TELE2", "YOTA", "MEGAFON"};
    char csv[4] = {"1.csv", "2.csv", "3.csv", "4.csv"};
    char path[50];
    //MTC
    for (i = 0; i < 4; i++) {
            sprintf(path, "../csv_input/%s/%c", operators[1], csv[i]);
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
            sprintf(path, "../csv_input/%s/%c", operators[2], csv[i-4]);
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
            sprintf(path, "../csv_input/%s/%c", operators[3], csv[i-8]);
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
            sprintf(path, "../csv_input/%s/%c", operators[4], csv[i-12]);
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

   /* //МТС
    tariff = fopen("../csv_input/MTC/1.csv", "r");
    fscanf(tariff,
           "%s%s%d%s%d%s%d%s%d",
           checking[0].tname,
           checking[0].gbHead,
           &checking[0].gbValue,
           checking[0].minHead,
           &checking[0].minValue,
           checking[0].smsHead,
           &checking[0].smsValue,
           checking[0].priceHead,
           &checking[0].priceValue);
    fclose(tariff);

    tariff = fopen("../csv_input/MTC/2.csv", "r");
    fscanf(tariff,
           "%s%s%d%s%d%s%d%s%d",
           checking[1].tname,
           checking[1].gbHead,
           &checking[1].gbValue,
           checking[1].minHead,
           &checking[1].minValue,
           checking[1].smsHead,
           &checking[1].smsValue,
           checking[1].priceHead,
           &checking[1].priceValue);
    fclose(tariff);

    tariff = fopen("../csv_input/MTC/3.csv", "r");
    fscanf(tariff,
           "%s%s%d%s%d%s%d%s%d",
           checking[2].tname,
           checking[2].gbHead,
           &checking[2].gbValue,
           checking[2].minHead,
           &checking[2].minValue,
           checking[2].smsHead,
           &checking[2].smsValue,
           checking[2].priceHead,
           &checking[2].priceValue);
    fclose(tariff);

    tariff = fopen("../csv_input/MTC/4.csv", "r");
    fscanf(tariff,
           "%s%s%d%s%d%s%d%s%d",
           checking[3].tname,
           checking[3].gbHead,
           &checking[3].gbValue,
           checking[3].minHead,
           &checking[3].minValue,
           checking[3].smsHead,
           &checking[3].smsValue,
           checking[3].priceHead,
           &checking[3].priceValue);
    fclose(tariff);

    // МЕГАФОН
    tariff = fopen("../csv_input/MEGAFON/1.csv", "r");
    fscanf(tariff,
           "%s%s%d%s%d%s%d%s%d",
           checking[4].tname,
           checking[4].gbHead,
           &checking[4].gbValue,
           checking[4].minHead,
           &checking[4].minValue,
           checking[4].smsHead,
           &checking[4].smsValue,
           checking[4].priceHead,
           &checking[4].priceValue);
    fclose(tariff);

    tariff = fopen("../csv_input/MEGAFON/2.csv", "r");
    fscanf(tariff,
           "%s%s%d%s%d%s%d%s%d",
           checking[5].tname,
           checking[5].gbHead,
           &checking[5].gbValue,
           checking[5].minHead,
           &checking[5].minValue,
           checking[5].smsHead,
           &checking[5].smsValue,
           checking[5].priceHead,
           &checking[5].priceValue);
    fclose(tariff);

    tariff = fopen("../csv_input/MEGAFON/3.csv", "r");
    fscanf(tariff,
           "%s%s%d%s%d%s%d%s%d",
           checking[6].tname,
           checking[6].gbHead,
           &checking[6].gbValue,
           checking[6].minHead,
           &checking[6].minValue,
           checking[6].smsHead,
           &checking[6].smsValue,
           checking[6].priceHead,
           &checking[6].priceValue);
    fclose(tariff);

    tariff = fopen("../csv_input/MEGAFON/4.csv", "r");
    fscanf(tariff,
           "%s%s%d%s%d%s%d%s%d",
           checking[7].tname,
           checking[7].gbHead,
           &checking[7].gbValue,
           checking[7].minHead,
           &checking[7].minValue,
           checking[7].smsHead,
           &checking[7].smsValue,
           checking[7].priceHead,
           &checking[7].priceValue);
    fclose(tariff);

    //ТЕЛЕ2
    tariff = fopen("../csv_input/TELE2/1.csv", "r");
    fscanf(tariff,
           "%s%s%d%s%d%s%d%s%d",
           checking[8].tname,
           checking[8].gbHead,
           &checking[8].gbValue,
           checking[8].minHead,
           &checking[8].minValue,
           checking[8].smsHead,
           &checking[8].smsValue,
           checking[8].priceHead,
           &checking[8].priceValue);
    fclose(tariff);

    tariff = fopen("../csv_input/TELE2/2.csv", "r");
    fscanf(tariff,
           "%s%s%d%s%d%s%d%s%d",
           checking[9].tname,
           checking[9].gbHead,
           &checking[9].gbValue,
           checking[9].minHead,
           &checking[9].minValue,
           checking[9].smsHead,
           &checking[9].smsValue,
           checking[9].priceHead,
           &checking[9].priceValue);
    fclose(tariff);

    tariff = fopen("../csv_input/TELE2/3.csv", "r");
    fscanf(tariff,
           "%s%s%d%s%d%s%d%s%d",
           checking[10].tname,
           checking[10].gbHead,
           &checking[10].gbValue,
           checking[10].minHead,
           &checking[10].minValue,
           checking[10].smsHead,
           &checking[10].smsValue,
           checking[10].priceHead,
           &checking[10].priceValue);
    fclose(tariff);

    tariff = fopen("../csv_input/TELE2/4.csv", "r");
    fscanf(tariff,
           "%s%s%d%s%d%s%d%s%d",
           checking[11].tname,
           checking[11].gbHead,
           &checking[11].gbValue,
           checking[11].minHead,
           &checking[11].minValue,
           checking[11].smsHead,
           &checking[11].smsValue,
           checking[11].priceHead,
           &checking[11].priceValue);
    fclose(tariff);

    // YOTA
    tariff = fopen("../csv_input/YOTA/1.csv", "r");
    fscanf(tariff,
           "%s%s%d%s%d%s%d%s%d",
           checking[12].tname,
           checking[12].gbHead,
           &checking[12].gbValue,
           checking[12].minHead,
           &checking[12].minValue,
           checking[12].smsHead,
           &checking[12].smsValue,
           checking[12].priceHead,
           &checking[12].priceValue);
    fclose(tariff);

    tariff = fopen("../csv_input/YOTA/2.csv", "r");
    fscanf(tariff,
           "%s%s%d%s%d%s%d%s%d",
           checking[13].tname,
           checking[13].gbHead,
           &checking[13].gbValue,
           checking[13].minHead,
           &checking[13].minValue,
           checking[13].smsHead,
           &checking[13].smsValue,
           checking[13].priceHead,
           &checking[13].priceValue);
    fclose(tariff);

    tariff = fopen("../csv_input/YOTA/3.csv", "r");
    fscanf(tariff,
           "%s%s%d%s%d%s%d%s%d",
           checking[14].tname,
           checking[14].gbHead,
           &checking[14].gbValue,
           checking[14].minHead,
           &checking[14].minValue,
           checking[14].smsHead,
           &checking[14].smsValue,
           checking[14].priceHead,
           &checking[14].priceValue);
    fclose(tariff);

    tariff = fopen("../csv_input/YOTA/4.csv", "r");
    fscanf(tariff,
           "%s%s%d%s%d%s%d%s%d",
           checking[15].tname,
           checking[15].gbHead,
           &checking[15].gbValue,
           checking[15].minHead,
           &checking[15].minValue,
           checking[15].smsHead,
           &checking[15].smsValue,
           checking[15].priceHead,
           &checking[15].priceValue);
    fclose(tariff);*/

    struct compareTariffs minRecommend;
    unsigned int counter;
    unsigned int i;

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
#include "lib.h"

int check(int check)
{
    char* start = malloc(sizeof(char) * 10);
    int launch;
    scanf(" %[^\n]", start);
    if (isdigit(start[0]) == 0) {
        system("clear");
        printf("Неверный ввод, повторите попытку\n");
        sleep(3);
        free(start);
        return 10;
    }
    launch = start[0] - '0';
    if (start[1] != 0) {
        system("clear");
        printf("Неверный ввод, повторите попытку\n");
        sleep(3);
        free(start);
        return 10;
    }
    if (launch > 0 && launch <= check) {
        free(start);
        return launch;
    } else {
        system("clear");
        printf("Неверный ввод, повторите попытку\n");
        sleep(3);
        free(start);
        return 10;
    }
    free(start);
}
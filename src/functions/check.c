#include "lib.h"

int check(int check)
{
    char* start = malloc(sizeof(char) * 10);
    int launch = 0;
    ;
    scanf(" %[^\n]", start);
    if ((isdigit(start[0]) != 0) && (isdigit(start[1]) != 0)
        && (isdigit(start[2]) != 0) && (start[4] == 0)) {
        launch = 100 * (start[0] - '0');
        launch = launch + 10 * (start[1] - '0');
        launch = launch + (start[2] - '0');
        if (launch > 0 && launch <= check) {
            free(start);
            return launch;
        } else {
            system("clear");
            printf("Неверный ввод, повторите попытку\n");
            sleep(3);
            free(start);
            return -1;
        }
    }
    if ((isdigit(start[0]) != 0) && (isdigit(start[1]) != 0)
        && (start[2] == 0)) {
        launch = launch + 10 * (start[0] - '0');
        launch = launch + (start[1] - '0');
        if (launch > 0 && launch <= check) {
            free(start);
            return launch;
        } else {
            system("clear");
            printf("Неверный ввод, повторите попытку\n");
            sleep(3);
            free(start);
            return -1;
        }
    }

    if ((isdigit(start[0]) == 0) || start[1] != 0) {
        system("clear");
        printf("Неверный ввод, повторите попытку\n");
        sleep(3);
        free(start);
        return -1;
    }
    launch = start[0] - '0';
    if (launch > 0 && launch <= check) {
        free(start);
        return launch;
    } else {
        system("clear");
        printf("Неверный ввод, повторите попытку\n");
        sleep(3);
        free(start);
        return -1;
    }
    free(start);
}
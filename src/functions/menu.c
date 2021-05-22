#include "lib.h"

void menu(int a)
{
    char dir[4][10] = {{"MTC\n"}, {"TELE2\n"}, {"YOTA\n"}, {"MEGAFON\n"}};
    char path[86];
    if (a == 1) {
        system("clear");
        printf(" Выберите оператора для просмотра тарифа\n");
        operators();
        printf("5. Назад\n");
        int b;
        scanf("%d", &b);
        if ((check(b, 5)) == 0) {
            system("clear");
            printf("Неверный ввод, повторите попытку%d\n", b);
            sleep(3);
            menu(1);
        }
        if (b == 5)
            main();
        else {
            system("clear");
            sprintf(path, " Тарифы оператора %s", dir[b - 1]);
            printf("%s", path);
            print1(b);
        }
    } else if (a == 2) {
        system("clear");
        printf(" Пожалуйста, выберите своего текущего оператора\n");
        operators();
        printf("5. Назад\n");
        int b, c;
        scanf("%d", &b);
        if (b == 5)
            main();
        if (b == 1) {
            system("clear");
            sprintf(path,
                    " Пожалуйста, выберите свой текущий тариф %s",
                    dir[b - 1]);
            printf("%s", path);
            print1(b);
            scanf("%d", &c);
            if (c < 1 || c > 4) {
                printf("error");
            } else {
                system("clear");
                data(b, c);
            }
        } else if (b == 2) {
            system("clear");
            sprintf(path,
                    " Пожалуйста, выберите свой текущий тариф %s",
                    dir[b - 1]);
            printf("%s", path);
            print1(b);
            scanf("%d", &c);
            if (c < 1 || c > 4) {
                printf("error");
            } else {
                system("clear");
                data(b, c);
            }
        } else if (b == 3) {
            system("clear");
            sprintf(path,
                    " Пожалуйста, выберите свой текущий тариф %s",
                    dir[b - 1]);
            printf("%s", path);
            print1(b);
            scanf("%d", &c);
            if (c < 1 || c > 4) {
                printf("error");
            } else {
                system("clear");
                data(b, c);
            }
        } else if (b == 4) {
            system("clear");
            sprintf(path,
                    " Пожалуйста, выберите свой текущий тариф %s",
                    dir[b - 1]);
            printf("%s", path);
            print1(b);
            scanf("%d", &c);
            if (c < 1 || c > 4) {
                printf("error");
            } else {
                system("clear");
                data(b, c);
            }
        }
    }
}
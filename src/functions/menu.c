#include "lib.h"

void menu(int a)
{
    int command, error = 1;
    char dir[4][10] = {{"MTC\n"}, {"TELE2\n"}, {"YOTA\n"}, {"MEGAFON\n"}};
    char path[86];
    if (a == 1) {
        system("clear");
        printf(" Выберите оператора для просмотра тарифа\n");
        operators();
        printf("5. Назад\n");
        command = check(5);
        if (command == 10)
            menu(1);
        if (command == 5)
            main();
        else {
            while (error != 0) {
                system("clear");
                sprintf(path, " Тарифы оператора %s", dir[command - 1]);
                print1(command);
                printf("1. Назад\n2. Выход\n");
                int tar = check(2);
                if (tar == 1) {
                    error = 0;
                    menu(1);
                }
                if (tar == 2) {
                    system("clear");
                    return;
                }
            }
        }
    } else if (a == 2) {
        int command, choice;
        system("clear");
        printf(" Пожалуйста, выберите своего текущего оператора\n");
        operators();
        printf("5. Назад\n");
        command = check(5);
        if (command == 10)
            menu(2);
        if (command == 5)
            main();
        if (command == 1) {
            while (1) {
                system("clear");
                sprintf(path,
                        " Пожалуйста, выберите свой текущий тариф %s",
                        dir[command - 1]);
                printf("%s", path);
                print1(command);
                printf("5. Назад\n");
                choice = check(5);
                if (choice == 5) {
                    menu(2);
                    return;
                }
                if (choice != 10) {
                    system("clear");
                    data(command, choice);
                    return;
                }
            }
        } else if (command == 2) {
            while (1) {
                system("clear");
                sprintf(path,
                        " Пожалуйста, выберите свой текущий тариф %s",
                        dir[command - 1]);
                printf("%s", path);
                print1(command);
                printf("5. Назад\n");
                choice = check(5);
                if (choice == 5) {
                    menu(2);
                    return;
                }
                if (choice != 10) {
                    system("clear");
                    data(command, choice);
                    return;
                }
            }
        } else if (command == 3) {
            while (1) {
                system("clear");
                sprintf(path,
                        " Пожалуйста, выберите свой текущий тариф %s",
                        dir[command - 1]);
                printf("%s", path);
                print1(command);
                printf("5. Назад\n");
                choice = check(5);
                if (choice == 5) {
                    menu(2);
                    return;
                }
                if (choice != 10) {
                    system("clear");
                    data(command, choice);
                    return;
                }
            }
        } else if (command == 4) {
            while (1) {
                system("clear");
                sprintf(path,
                        " Пожалуйста, выберите свой текущий тариф %s",
                        dir[command - 1]);
                printf("%s", path);
                print1(command);
                printf("5. Назад\n");
                choice = check(5);
                if (choice == 5) {
                    menu(2);
                    return;
                }
                if (choice != 10) {
                    system("clear");
                    data(command, choice);
                    return;
                }
            }
        }
    }
}
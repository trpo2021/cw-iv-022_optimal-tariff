#include "lib.h"

void menu(int a)
{
    char dir[4][10] = {{"MTC\n"}, {"TELE2\n"}, {"YOTA\n"}, {"MEGAFON\n"}};
    char path[86];
    if (a == 1) {
        int command;
        system("clear");
        printf(" Выберите оператора для просмотра тарифа\n");
        operators();
        printf("5. Назад\n");
        command = check(5);
        if (command == -1) {
            menu(1);
            return;
        }
        if (command == 5) {
            main();
            return;
        } else {
            while (1) {
                system("clear");
                sprintf(path, " Тарифы оператора %s", dir[command - 1]);
                print1(command);
                printf("1. Назад\n2. Выход\n");
                int tar = check(2);
                if (tar == 1) {
                    menu(1);
                    return;
                }
                if (tar == 2) {
                    system("clear");
                    printf("Всего хорошего!\n");
                    sleep(3);
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
        if (command == -1) {
            menu(2);
            return;
        }
        if (command == 5) {
            main();
            return;
        }
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
                if (choice != -1) {
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
                if (choice != -1) {
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
                if (choice != -1) {
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
                if (choice != -1) {
                    system("clear");
                    data(command, choice);
                    return;
                }
            }
        }
    }
}
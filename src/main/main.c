#include "functions/lib.h"

int main()
{
    int start, ch;
    system("clear");
    hrs();
    greeting();
    printf("Нажмите любую клавишу для запуска программы\n");
    if ((ch = getchar()) != EOF) {
        system("clear");
        printf(" Выберите пунт для продолжения\n1. Ознакомиться с операторами "
               "и тарифами\n2. Подобрать тариф на основе затрат\n3. Выход\n");
        scanf("%d", &start);
        if ((check(start, 3)) == 0) {
            system("clear");
            printf("Неверный ввод, повторите попытку\n");
            sleep(3);
            main();
        }
        if (start == 3) {
            system("clear");
            return 0;
        }
    }
    menu(start);
}
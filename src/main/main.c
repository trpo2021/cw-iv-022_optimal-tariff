#include "functions/lib.h"

int main()
{
    int start;
    system("clear");
    hrs();
    greeting();
    printf(" Выберите пункт для начала работы с программой\n1. Ознакомиться с операторами "
            "и тарифами\n2. Подобрать тариф на основе затрат\n3. Выход\n");
    start = check(3);
    if (start == 10)
        main();
    if (start == 3) {
        system("clear");
        printf("Всего хорошего!\n");
        sleep(3);
        system("clear");
        return 0;
    }
    menu(start);
}
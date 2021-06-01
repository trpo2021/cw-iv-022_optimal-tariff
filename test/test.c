#include "ctest.h"
#include "functions/lib.h"

CTEST(check_main, check_1)
{
    const int expected = -1;
    const int result = check(3);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_main, check_2)
{
    const int expected = 3;
    const int result = check(3);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_menu, check_3)
{
    const int expected = -1;
    const int result = check(4);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_menu, check_4)
{
    const int expected = 4;
    const int result = check(4);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_temp, check_gb1)
{
    const int expected = -1;
    const int result = check(10);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_temp, check_gb2)
{
    const int expected = 20;
    const int result = check(50);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_temp, check_sms)
{
    const int expected = -1;
    const int result = check(200);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_temp, check_sms2)
{
    const int expected = 100;
    const int result = check(100);
    ASSERT_EQUAL(expected, result);
}

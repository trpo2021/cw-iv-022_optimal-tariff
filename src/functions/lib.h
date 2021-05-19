#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "comparision.h"
#include "data.h"
#include "menu.h"
#include "operators.h"
#include "print1.h"
#include "temp.h"
#include "time.h"

struct operators
{
    char operator[25];
};

struct tariffs
{
    char tf_name[25];

    char gb[20];
    int gb_value;
    
    char min[20];
    int min_value;

    char sms[20];
    int sms_value;

    char price[35];
    int price_value;
};

struct time
{
    int hours;
};

int comparison (int *gbe, int *mine, int *smse);

int data(int b, int c);

void menu();

void operators();

void print1(int a);

int temp(int *g, int gb, int min, int sms, int price);

int hrs(void);

void greeting();
//
// Created by zeus on 02.07.2020.
//

#include "options.h"


int         space_count     (int all_line, int high)
{
    int span;

    all_line -= 1;
    span      = 0;
    while (high > 1)
    {
        span += ((high / 2) + 1);   //(2 level) == 2 / 2 = 1
        high -= 1;                 //(3 level) == 3 / 2 = 1
    }                             //(4 level) == 4 / 2 = 2
    return  (all_line + span);   //(5 level) == 5 / 2 = 2
}

///create array which have sum of current level and pre...
int         *spans          (int high)
{
    int *levels;
    int       i;

    levels = (int *)malloc(sizeof(int) * (high + 2));
    i      = 0;
    while (i < high)
    {
        levels[i] = ((i + 1) + 2) + levels[i - 1];         // i + 1 -- it is current level (1,2,3 ... etc)
        i++;                                              // i + 2 -- (first level 1 + 2) (second level 2 + 2) ... etc
    }                                                    // i + (prev val) -- (second level 4 + (first level) == 3) (4 + 3) (5 + 7) (12 + 8)
    return  (levels);

}
int koef(int high)                                    //(2 high) == 2 / 2 = 1
{                                                    //(3 high) == 3 / 2 = 1
    return high / 2;                                //(4 high) == 4 / 2 = 2
}                                                  //(5 high) == 5 / 2 = 2

options cr_opt(int high)
{
    options param;

    param.high   = high;
    param.levels = spans(param.high);
    param.all_e  = param.levels[high - 1] - 1;
    param.space  = space_count(param.levels[param.high - 1], param.high); // -1 becouse from zero, not from 1
    param.stars  = 1;
    param.k_f    = koef;                                                       //taking function koef and from input data count koef

    return param;
}
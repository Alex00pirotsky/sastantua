//
// Created by zeus on 02.07.2020.
//

#ifndef SASTANTUA_OPTIONS_H
#define SASTANTUA_OPTIONS_H

#include "stdlib.h"

typedef struct param
{
    int   (*k_f) (int);
    int  *levels;
    int    space;
    int    stars;
    int    all_e;
    int     high;

}options;

int         space_count     (int all_line, int high); //count spaces
int         *spans          (int high);              //counting levels between spans
int         koef            (int high);             //count koef (high / 2)
options     cr_opt          (int high);            //creat main options for sastantua





#endif //SASTANTUA_OPTIONS_H

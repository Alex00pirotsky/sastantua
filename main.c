#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "options.h"

typedef struct sast
{
    char *line;
}pyramid;


int         ft_strlen       (char const *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return  (i);
}

int ft_atoi(char *s)
{
    int res;
    int neg;
    res = 0;
    neg = (*s == '-') ? -1 : 1;

    while (*s)
    {
        (*s <= '9' && *s >= '0') ? res *= 10 , res += (*s - '0') : 0;
        s++;
    }
    return (res * neg);
}

void        append          (char *line, int till, char what, int from)
{
    int i;

    i        = (from) ? from : ft_strlen(line);
    while (till > 0)
    {
        line[i] = what;
        till--;
        i++;
    }
}
void pr_sas(pyramid *root)
{
    int i;

    i = 0;
    while (root[i].line)
    {
        write(1, root[i].line, ft_strlen(root[i].line));
        write(1,"\n",1);
        i++;
    }
}




///creat line from stars // space and /
char        *creat_line     (int stars, int space)
{
    char *n_line;

    n_line = (char *)malloc(sizeof(char) * (stars + space + 5));

    append  (n_line, space,  ' ',0);
    n_line  [ft_strlen(n_line)] = '/';
    append  (n_line, stars,  '*',0);
    n_line  [ft_strlen(n_line)] = '\\';
    n_line  [ft_strlen(n_line)] = '\0';

    return  (n_line);
}

pyramid     *doors          (pyramid *root, options op)
{
    int door_len;
    int door_beg;
    int loop_con;

    door_len = op.k_f(op.high - 1) * 2 + 1;
    door_beg = (ft_strlen(root[op.all_e].line)) / 2;
    door_beg = door_beg - op.k_f(op.high - 1);
    loop_con = door_len;

    while (loop_con > 0)
    {
        append(root[op.all_e].line,door_len,'|',door_beg);
        op.all_e  -= 1;
        loop_con  -= 1;
    }
    op.all_e += op.high;
    (door_len > 3) ?
        append(root[op.all_e - op.k_f(op.high)].line,1,'$',door_beg + door_len - 2) : 0;
    return root;

}

/// fulfil each level in main struct , by string
pyramid     *fulfil         (options op)
{
    pyramid   *main;
    int           i;

    op.high   = 2;                                                     // im start from this high
    main      = malloc(sizeof(pyramid) * (op.space) + 10);
    i         = 0;                                                   // iterator for main

    while (op.space  >= 0)
    {
        main[i].line = creat_line(op.stars, op.space);
        if (i + 1 == op.levels[op.high - 2])
        {
            op.stars   += (op.k_f(op.high) * 2) + 2;
            op.space   -= (op.k_f(op.high) + 1);               // we have space only in the begin, so we should add only one
            op.high    += 1;                                  // going in to next high
        }
        op.stars += 2;                                      // one start from one side, and one in another
        op.space -= 1;                                     // one side, one space
        i        += 1;                                    // iterate on main
    }
    return  (main);
}

pyramid     *paln_kapkan    (int high)
{
    pyramid *root;
    options op;

    op = cr_opt(high);
    root = fulfil(op);
    doors(root,op);

    return  (root);
}


int main(int argc, char **argv)
{
    pyramid *root;
    if (argc < 2 && argv[2])
    {
        printf("Please you should enter Only one number, or at least one number");
    }
    else
    {
        root = paln_kapkan(ft_atoi(argv[1]));
        pr_sas(root);
    }








//




    return 0;
}
//Kizumonogatari
//Anime: Killing Bites
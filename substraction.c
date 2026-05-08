#include <stdio.h>
#include <stdlib.h>
#include "types.h"

int Substraction(Dlist **head1, Dlist **tail1,
                Dlist **head2, Dlist **tail2,
                Dlist **resh,  Dlist **rest)
{
    Dlist *t1 = *tail1;
    Dlist *t2 = *tail2;
    int borrow = 0, diff;

    while (t1 || t2)
    {
        int d1 = t1 ? t1->data : 0;
        int d2 = t2 ? t2->data : 0;

        d1 = d1 - borrow;

        if (d1 < d2)
        {
            d1 += 10;
            borrow = 1;
        }
        else
            borrow = 0;

        diff = d1 - d2;

        Dlist *new = malloc(sizeof(Dlist));
        if (!new)
            return FAILURE;

        new->data = diff;
        new->prev = NULL;
        new->next = *resh;

        if (*resh)
            (*resh)->prev = new;
        else
            *rest = new;

        *resh = new;

        if (t1) t1 = t1->prev;
        if (t2) t2 = t2->prev;
    }

    return SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>
#include "types.h"

/* Function to perform big number division */
int Division(Dlist **head1, Dlist **tail1,
             Dlist **head2, Dlist **tail2,
             Dlist **resh,  Dlist **rest)
{
    Dlist *h1 = *head1;
    Dlist *t1 = *tail1;
    int count = 0;

    while (compare_lists(h1, *head2) >= 0)
    {
        Dlist *temp_h = NULL, *temp_t = NULL;

        Substraction(&h1, &t1,
                     head2, tail2,
                     &temp_h, &temp_t);

        h1 = temp_h;
        t1 = temp_t;

        /* count every successful subtraction */
        count++;

        /* REMOVE leading zeros */
        while (h1 && h1->data == 0)
            h1 = h1->next;

        /* dividend became zero */
        if (h1 == NULL)
            break;
    }

    /* store quotient */
    while (count)
    {
        dl_insert_first(resh, rest, count % 10);
        count /= 10;
    }

    return SUCCESS;
}

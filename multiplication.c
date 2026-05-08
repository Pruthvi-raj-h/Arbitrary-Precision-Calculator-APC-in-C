#include <stdio.h>
#include <stdlib.h>
#include "types.h"

int Multiplication(Dlist **head1, Dlist **tail1,
                   Dlist **head2, Dlist **tail2,
                   Dlist **resh,  Dlist **rest)
{
    Dlist *temp2 = *tail2;   /* traverse number2 */
    int shift = 0;

    *resh = NULL;
    *rest = NULL;

    while (temp2)
    {
        Dlist *temp1 = *tail1;   /* traverse number1 */
        Dlist *temp_h = NULL, *temp_t = NULL;
        int carry = 0;

        /* positional shift */
        for (int i = 0; i < shift; i++)
        {
            dl_insert_first(&temp_h, &temp_t, 0);
        }

        /* digit by digit multiplication */
        while (temp1)
        {
            int prod = (temp1->data * temp2->data) + carry;
            carry = prod / 10;
            dl_insert_first(&temp_h, &temp_t, prod % 10);
            temp1 = temp1->prev;
        }

        if (carry)
        {
            dl_insert_first(&temp_h, &temp_t, carry);
        }

        /* accumulate result */
        if (*resh == NULL)
        {
            *resh = temp_h;
            *rest = temp_t;
        }
        else
        {
            Dlist *new_h = NULL, *new_t = NULL;
            Addition(resh, rest, &temp_h, &temp_t, &new_h, &new_t);
            *resh = new_h;
            *rest = new_t;
        }

        temp2 = temp2->prev;
        shift++;
    }

    return SUCCESS;
}

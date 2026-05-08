#include<stdio.h>
#include<stdlib.h>
#include"types.h"

int Addition(Dlist **head1, Dlist **tail1,
             Dlist **head2, Dlist **tail2,
             Dlist **resh,  Dlist **rest)
{
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;
    int sum, carry = 0, data;

    while (temp1 != NULL || temp2 != NULL || carry)
    {
        sum = carry;

        if (temp1)
        {
            sum += temp1->data;
            temp1 = temp1->prev;
        }

        if (temp2)
        {
            sum += temp2->data;
            temp2 = temp2->prev;
        }

        carry = sum / 10;
        data  = sum % 10;

        Dlist *new = malloc(sizeof(Dlist));
        if (new == NULL)
            return FAILURE;

        new->data = data;
        new->prev = NULL;
        new->next = *resh;

        if (*resh)
            (*resh)->prev = new;
        else
            *rest = new;   // first node becomes tail

        *resh = new;
    }

    return SUCCESS;
}

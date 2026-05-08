/*=====================================================================================================================================
Project name    : APC - Arbitary Precision Control
Name            : Pruthvi Raj H
Date            : 03/02/2025
Description     : The APC project is based on Advanced C Programming in DSA and is used to perform arithmetic operations on large 
numbers that cannot be handled by normal C data types. It uses linked lists and dynamic memory allocation to store and process numbers.
 ======================================================================================================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "types.h"

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Invalid count of argument count\n");
        return FAILURE;
    }

    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;
    Dlist *resh  = NULL, *rest  = NULL;

    int i = 0;

    /* create list for first number (skip '-') */
    if (argv[1][0] == '-')
    {
        i = 1;
    }

    while (argv[1][i])
    {
        dl_insert_last(&head1, &tail1, argv[1][i] - '0');
        i++;
    }

    /* create list for second number (skip '-') */
    i = 0;
    if (argv[3][0] == '-')
    {
        i = 1;
    }

    while (argv[3][i])
    {
        dl_insert_last(&head2, &tail2, argv[3][i] - '0');
        i++;
    }

    switch (argv[2][0])
    {
        case '+':
        {
            Addition(&head1, &tail1,
                     &head2, &tail2,
                     &resh,  &rest);

            Dlist *temp = resh;

            while (temp)
            {
                printf("%d", temp->data);
                temp = temp->next;
            }
            printf("\n");
            break;
        }

        case '-':
        {
            /* handle: -a - b = -(a + b) */
            if (argv[1][0] == '-')
            {
                printf("-");
                Addition(&head1, &tail1,
                         &head2, &tail2,
                         &resh,  &rest);
            }
            else
            {
                int cmp = compare_lists(head1, head2);

                if (cmp == 0)
                {
                    printf("0\n");
                    break;
                }

                if (cmp < 0)
                {
                    Dlist *th = head1;
                    Dlist *tt = tail1;

                    head1 = head2;
                    tail1 = tail2;
                    head2 = th;
                    tail2 = tt;

                    printf("-");
                }

                Substraction(&head1, &tail1,
                             &head2, &tail2,
                             &resh,  &rest);
            }

            Dlist *temp = resh;

            while (temp && temp->data == 0)
            {
                temp = temp->next;
            }

            while (temp)
            {
                printf("%d", temp->data);
                temp = temp->next;
            }
            printf("\n");
            break;
        }

        case 'x':
        {
            Multiplication(&head1, &tail1,
                           &head2, &tail2,
                           &resh,  &rest);

            Dlist *temp = resh;

            while (temp && temp->data == 0)
            {
                temp = temp->next;
            }

            while (temp)
            {
                printf("%d", temp->data);
                temp = temp->next;
            }
            printf("\n");
            break;
        }

        case '/':
        {
            /* division by zero check */
            Dlist *t = head2;
            while (t && t->data == 0)
            {
                t = t->next;
            }

            if (t == NULL)
            {
                printf("Error: Division by zero\n");
                break;
            }

            int cmp = compare_lists(head1, head2);

            if (cmp < 0)
            {
                printf("0\n");
                break;
            }

            if (cmp == 0)
            {
                printf("1\n");
                break;
            }

            Division(&head1, &tail1,
                     &head2, &tail2,
                     &resh,  &rest);

            Dlist *temp = resh;

            while (temp && temp->data == 0)
            {
                temp = temp->next;
            }

            while (temp)
            {
                printf("%d", temp->data);
                temp = temp->next;
            }
            printf("\n");
            break;
        }

        default:
        {
            printf("Invalid operator\n");
        }
    }

    return SUCCESS;
}

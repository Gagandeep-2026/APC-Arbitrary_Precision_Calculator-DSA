// #include "apc.h"
// int division(Dlist head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **headR, Dlist **tailR)
// {
//     Dlist *head3=NULL;
//     Dlist *tail3=NULL;

//     insert_at_last(&head3, &tail3, head1->data);

//     head3->data=head1->data;
//     head1=head1->next;

//     while(1)
//     {   int count=0;
//         if(Compare_list(head3, head2) == 1)
//         {
//             int Asubtraction(tail2, tail3, **headR, **tailR);
//             count++;
//         }
//         else
//         {
//             break;
//         }
//     }
//     insert_at_first(&headR,&tailR,count);//update result into result list based on the count.
    
// }

// Initialize List 3 as empty
// Initialize quotient as empty

// For each digit in List 1, from left to right:

//     Append the digit to List 3
//     count = 0

//     While List 3 >= List 2:
//         Subtract List 2 from List 3
//         Replace List 3 with the subtraction result
//         count++

//     Insert count at the end of the quotient list

// Return quotient


#include "apc.h"

static void free_list(Dlist *head)
{
    Dlist *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

static void trim_zeros(Dlist **head, Dlist **tail)
{
    while (*head != NULL && *head != *tail &&
           (*head)->data == 0)
    {
        Dlist *temp = *head;
        *head = temp->next;
        (*head)->prev = NULL;
        free(temp);
    }
}

int division(Dlist *head1, Dlist *tail1,
             Dlist *head2, Dlist *tail2,
             Dlist **headR, Dlist **tailR)
{
    Dlist *temp = head1;
    Dlist *head3 = NULL, *tail3 = NULL;
    Dlist *check = head2;
    int count;

    (void)tail1;

    *headR = NULL;
    *tailR = NULL;

    /* Check division by zero */
    while (check != NULL && check->data == 0)
        check = check->next;

    if (head1 == NULL || head2 == NULL ||
        tail2 == NULL || check == NULL)
    {
        printf("Invalid input or division by zero\n");
        return FAILURE;
    }

    while (temp != NULL)
    {
        /* Bring down the next dividend digit */
        if (insert_at_last(&head3, &tail3,
                           temp->data) == FAILURE)
            goto error;

        trim_zeros(&head3, &tail3);
        count = 0;

        /* Repeated subtraction */
        while (head3 != NULL &&
               Compare_list(head3, head2) == 1)
        {
            Dlist *subHead = NULL, *subTail = NULL;

            if (Asubtraction(tail3, tail2,
                             &subHead, &subTail) == FAILURE)
            {
                free_list(subHead);
                goto error;
            }

            free_list(head3);

            head3 = subHead;
            tail3 = subTail;

            trim_zeros(&head3, &tail3);
            count++;
        }

        /* Store quotient digit */
        if (insert_at_last(headR, tailR, count) == FAILURE)
            goto error;

        temp = temp->next;
    }

    trim_zeros(headR, tailR);
    free_list(head3);

    return SUCCESS;

error:
    free_list(head3);
    free_list(*headR);

    *headR = NULL;
    *tailR = NULL;

    return FAILURE;
}
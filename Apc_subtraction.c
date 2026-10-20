#include "apc.h"

int Asubtraction(Dlist **tail1, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    Dlist *head1 = *tail1;
    Dlist *head2 = *tail2;

    /* Find the heads of both operand lists */
    while (head1 != NULL && head1->prev != NULL)
        head1 = head1->prev;

    while (head2 != NULL && head2->prev != NULL)
        head2 = head2->prev;

    /* Step 1: Compare the number of digits */
    int len1 = 0, len2 = 0;
    Dlist *temp = head1;

    while (temp != NULL)
    {
        len1++;
        temp = temp->next;
    }

    temp = head2;

    while (temp != NULL)
    {
        len2++;
        temp = temp->next;
    }

    int cmp = 0;

    if (len1 > len2)
        cmp = 1;
    else if (len2 > len1)
        cmp = -1;
    else
    {
        /* Equal lengths: compare digits from the head */
        Dlist *p = head1;
        Dlist *q = head2;

        while (p != NULL && q != NULL)
        {
            if (p->data > q->data)
            {
                cmp = 1;
                break;
            }
            else if (p->data < q->data)
            {
                cmp = -1;
                break;
            }

            p = p->next;
            q = q->next;
        }
    }

    /* Step 2: If numbers are equal, result is zero */
    if (cmp == 0)
        return insert_at_first(headR, tailR, 0);

    /* Step 3: Select the larger and smaller operands */
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;

    if (cmp < 0)
    {
        temp1 = *tail2;
        temp2 = *tail1;
    }

    /* Step 4: Subtract from right to left */
    int borrow = 0;
    int res;

    while (temp1 != NULL)
    {
        res = temp1->data - borrow;

        if (temp2 != NULL)
        {
            res = res - temp2->data;
            temp2 = temp2->prev;
        }

        if (res < 0)
        {
            res = res + 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        /* Insert each digit at the beginning */
        if (insert_at_first(headR, tailR, res) == FAILURE)
            return FAILURE;

        temp1 = temp1->prev;
    }

    /* Step 5: Remove leading zeros */
    while (*headR != NULL && (*headR)->data == 0 && (*headR)->next != NULL)
    {
        Dlist *del = *headR;
        *headR = del->next;
        (*headR)->prev = NULL;
        free(del);
    }

    /* Print minus sign if operand 2 was larger */
    if (cmp < 0)
        printf("-");

    return SUCCESS;
}

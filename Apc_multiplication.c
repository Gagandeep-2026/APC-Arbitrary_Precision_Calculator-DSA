// #include "apc.h"
// int multiplication(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR)
// {
//     Dlist *temp1=NULL;
//     Dlist *temp2=NULL;

//     Dlist *headr1=NULL;
//     Dlist *tailr1=NULL;

//     Dlist *headr2=NULL;
//     Dlist *tailr2=NULL;

//     Dlist *headr=NULL;
//     Dlist *tailr=NULL;

//     Dlist *temp1=tail1;
//     Dlist *temp2=tail2;
//     int count=0;
//     int carry=0;
//     int res=0;

//     while(temp2!=NULL)
//     {
//         count++;
//         //temp1=*tail1;
//         while(temp1!=NULL)
//         {
//             res=(temp2 X temp1)+carry;
//             if(res>9)
//             {
//                 carry=res / 10;
//                 res=res % 10;
//             }
//             if(count==1)
//             {
//                 insert_at_first(headr1,tailr1,res);  
//             }
//             else if(count>1)
//             {

//                 insert_at_first(headr2,tailr2,res);
//             }
//             addition(tail1, tail2, &headR, &tailR);
//             headr1=*headR;
//             tailt1=*tailR;

//             temp1=temp1->prev;
//         }
//         temp2=temp2->prev;
//     }
// }

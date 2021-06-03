#include <stdio.h>
#include <stdlib.h>
#include <status.h>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef struct
{
    Elemtype * elem;
    int length;
    int listsize;
}Sqlist;

Status InitList_Sq(Sqlist *pL);
Status ListInsert_Sq(Sqlist *pL, int i, Elemtype e);
Status ListDelete_Sq(Sqlist *pL, int i, Elemtype *e);
Status ListMerge_Sq(Sqlist La, Sqlist Lb, Sqlist *p_Lc);

int main(void)
{
    int i = 0;

    //test InitList_Sq()
    Sqlist L, *pL = &L;
    InitList_Sq(pL);

    //test ListInsert_Sq()
    printf("test ListInsert_Sq()\n");
    ListInsert_Sq(pL, 1, 1);
    ListInsert_Sq(pL, 2, 3);
    ListInsert_Sq(pL, 3, 5);
    printf("L:");
    for (i = 0; i < L.length;i++)
    {
        printf("%d ", L.elem[i]);
    }
    printf("\n");

    //test ListDelete_Sq()
    printf("test ListDelete_Sq()\n");
    i = 0;
    Elemtype e = 0, *pe = &e;
    ListDelete_Sq(pL, 1, pe);
    printf("the value of e is %d\n", e);
    printf("after ListDelete(), L:");
    for (i = 0; i < L.length;i++)
    {
        printf("%d ", L.elem[i]);
    }
    printf("\n");

    //test ListMerge_Sq()
    printf("test ListMerge_Sq()");
    Sqlist La, Lb, Lc, *p_La = &La, *p_Lb = &Lb, *p_Lc = &Lc;
    //La=(1,2,3)
    InitList_Sq(p_La);
    ListInsert_Sq(p_La, 1, 1);
    ListInsert_Sq(p_La, 2, 3);
    ListInsert_Sq(p_La, 3, 5);
    printf("La:");
    for (i = 0; i < La.length;i++)
    {
        printf("%d ",La.elem[i]);
    }
    printf("\n");

    //Lb=(2,4,6)
    InitList_Sq(p_Lb);
    ListInsert_Sq(p_Lb, 1, 2);
    ListInsert_Sq(p_Lb, 2, 4);
    ListInsert_Sq(p_Lb, 3, 6);
    printf("Lb:");
    for (i = 0; i < Lb.length;i++)
    {
        printf("%d ", Lb.elem[i]);
    }
    printf("\n");

    //Lc=();
    InitList_Sq(p_Lc);
    ListMerge_Sq(La, Lb, p_Lc);
    printf("Lc:");
    for (i = 0; i < Lc.length;i++)
    {
        printf("%d ", Lc.elem[i]);
    }
    printf("\n");
    return 0;
}

Status InitList_Sq(Sqlist *pL)
{
    pL->elem=(Elemtype *)malloc(LIST_INIT_SIZE*sizeof(Elemtype));
    if (!pL->elem) exit(OVERFLOW);
    pL->length=0;
    pL->listsize=LIST_INIT_SIZE;
    return(OK);
}
Status ListInsert_Sq(Sqlist *pL, int i, Elemtype e)
{
    if(i<1||i>pL->length+1) return(ERROR); //i最大可以等于（pL->length）+1 ，即插入到最后一个位置
    if(pL->length >= pL->listsize)
    {
        Elemtype * newbase=NULL;
        newbase=(Elemtype *)realloc(pL->elem, (pL->listsize+LISTINCREMENT)*sizeof(Elemtype));
        if(!newbase) exit(OVERFLOW);
        pL->elem = newbase;
        pL->listsize += LISTINCREMENT;
    }
    Elemtype *q = NULL, *p = NULL;
    p = & pL->elem[i - 1];
    for (q = &pL->elem[pL->length - 1]; q >= p;q--)
    {
        *(q + 1) = *q;
    }
    *p = e;
    pL->length++;
    return (OK);
}
Status ListDelete_Sq(Sqlist *pL, int i, Elemtype *e)
{
    if(i<1||i>pL->length) return(ERROR); //i最大可以等于 pL->length ，即删除最后一个位置的元素
    Elemtype *p = NULL, *q = NULL;
    p = &pL->elem[i - 1];
    *e = *p;
    for (q = & pL->elem[pL->length - 1]; p < q;p++)
    {
        *p = *(p + 1);
    }
    pL->length--;
    return (OK);
}
Status ListMerge_Sq(Sqlist La, Sqlist Lb, Sqlist *p_Lc)
{
    p_Lc->length = La.length + Lb.length;
    p_Lc->elem = (Elemtype *)malloc(p_Lc->length * sizeof(Elemtype));
    if(!p_Lc)
        exit(OVERFLOW);
    Elemtype *pa = La.elem, *pb = Lb.elem, *pc = p_Lc->elem;
    Elemtype *pa_last = La.elem + La.length - 1, *pb_last = Lb.elem + Lb.length - 1;
    while (pa<=pa_last&&pa<=pb_last)
    {
        if(*pa<=*pb)
        {
            *pc = *pa;
            pc++;
            pa++;
        }
        else
        {
            *pc = *pb;
            pc++;
            pb++;
        }
    }
    while (pa<=pa_last)
    {
        *pc = *pa;
        pc++;
        pa++;
    }
    while (pb<=pb_last)
    {
        *pc = *pb;
        pc++;
        pb++;
    }
    return (OK);
}
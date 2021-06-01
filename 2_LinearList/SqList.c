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

int main(void)
{
    int i = 0;

    //test InitList_Sq()
    Sqlist L, *pL = &L;
    InitList_Sq(pL);

    //test ListInsert_Sq()
    ListInsert_Sq(pL, 1, 1);
    ListInsert_Sq(pL, 2, 3);
    ListInsert_Sq(pL, 3, 5);
    for (i = 0; i < L.length;i++)
    {
        printf("the %dth element is %d\n", i+1, L.elem[i]);
    }

    //test ListDelete_Sq()
    i = 0;
    Elemtype e = 0, *pe = &e;
    ListDelete_Sq(pL, 1, pe);
    printf("the value of e is %d\n", e);
    for (i = 0; i < L.length;i++)
    {
        printf("the %dth element is %d\n", i+1, L.elem[i]);
    }

    
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
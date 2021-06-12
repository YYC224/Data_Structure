#include <stdio.h>
#include <stdlib.h>
#include <status.h>

#define INIT_LIST_SIZE 10

typedef struct SqList
{
    Elemtype *base;
    int length;
    int listsize;
}SqList;

int Init_by_pointer(SqList *pL, Elemtype e1, Elemtype e2);
int Init_by_reference(SqList &L, Elemtype e1, Elemtype e2);

int main(void)
{
    SqList L1;
    SqList *pL1 = &L1;
    Init_by_pointer(pL1, 1, 2);
    printf("L1 = (%d, %d)\n", L1.base[0], L1.base[1]);

    SqList L2;
    Init_by_reference(L2, 3, 4);
    printf("L2 = (%d, %d)\n", L2.base[0], L2.base[1]);
    return 0;
}

int Init_by_pointer(SqList *pL, Elemtype e1, Elemtype e2)
{
    //Initial sequence list L = (e1, e2) by using pointer pL
    (*pL).base = (Elemtype *)malloc(INIT_LIST_SIZE * sizeof(Elemtype));
    if(!(*pL).base) exit(-1);
    (*pL).length = 2;
    (*pL).listsize = INIT_LIST_SIZE;
    (*pL).base[0] = e1;
    (*pL).base[1] = e2;
    return 0;
}

int Init_by_reference(SqList &L, Elemtype e1, Elemtype e2)
{
    //Initial sequence list L = (e1, e2) by using reference &L
    L.base = (Elemtype *)malloc(INIT_LIST_SIZE * sizeof(Elemtype));
    if(!L.base) exit(-1);
    L.length = 2;
    L.listsize = INIT_LIST_SIZE;
    L.base[0] = e1;
    L.base[1] = e2;
    return 0;
}

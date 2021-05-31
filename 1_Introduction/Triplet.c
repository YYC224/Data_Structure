# include <stdio.h>
# include <stdlib.h>
# include <status.h>

//dynamic store
typedef Elemtype Triplet;

//operation expression
Status InitTriplet(Triplet **pT, Elemtype v1, Elemtype v2, Elemtype v3);
Status DestroyTriplet(Triplet **pT);
Status Get(Triplet *T, int i, Elemtype *e);
Status Put(Triplet *T, int i, Elemtype e);
Status IsAscending (Triplet *T);
Status IsDescending(Triplet *T);
Status Max(Triplet *T, Elemtype *e);
Status Min(Triplet *T, Elemtype *e);

int main(void)
{
    Triplet * T_test;
    Triplet ** pT_test;
    pT_test = &T_test;
    InitTriplet(pT_test,2,4,6);
    printf("The address of T is %p, the elements of T are %d %d %d\n",
     T_test, T_test[0], T_test[1], T_test[2]);
    
    Elemtype e=0, * pe;
    pe=&e;
    printf("before Get function, e = %d\n", e);
    Get(T_test, 2, pe);
    printf("after Get function, e = %d\n", e);

    printf("before Put function, T_test[2] = %d\n", T_test[2]);
    Put(T_test, 3, e);
    printf("after Put function, T_test[2] = %d\n", T_test[2]);

    Min(T_test,pe);
    printf("%d\n",e);

    DestroyTriplet(pT_test);
    printf("The address of T is %p\n", T_test);
    return 0;
}

//operation realization
Status InitTriplet(Triplet **pT, Elemtype v1, Elemtype v2, Elemtype v3)
{
    //initialize a triplet, the elements of it are v1, v2, v3(in the same order)
    *pT = (Elemtype * )malloc(3 * sizeof(Elemtype));
    if(!(*pT))exit(OVERFLOW);
    (*pT)[0] = v1;
    (*pT)[1] = v2;
    (*pT)[2] = v3;
    return OK;
}

Status DestroyTriplet(Triplet **pT)
{
    free(*pT);
    *pT = NULL;
    return OK;
}

Status Get(Triplet * T, int i, Elemtype *e)
{
    //1<=i<=3, e=T[i-1];
    if(i<1 || i>3) return(ERROR);
    *e = T[i-1];
    return OK;
}

Status Put(Triplet *T, int i, Elemtype e)
{
    //1<=i<=3, T[i-1]=e
    if(i<1 ||i>3) return(ERROR);
    T[i-1] = e;
    return OK;
}

Status IsAscending (Triplet *T)
{
    //if the elements in T are ascending, then return 1, otherwise return 0
    return (T[0]<=T[1])&&(T[1]<=T[2]);
}

Status IsDescending(Triplet *T)
{
    //if the elements in T are descending, then return 1, otherwise return 0
    return (T[0]>=T[1])&&(T[1]>=T[2]);
}

Status Max(Triplet *T, Elemtype *e)
{
    *e=(T[0]>=T[1])?((T[0]>=T[2])?T[0]:T[2]):((T[1]>=T[2])?T[1]:T[2]);
    return OK;
}

Status Min(Triplet *T, Elemtype *e)
{
    *e=(T[0]<=T[1])?(T[0]<=T[2]?T[0]:T[2]):(T[1]<=T[2]?T[1]:T[2]);
    return OK;
}
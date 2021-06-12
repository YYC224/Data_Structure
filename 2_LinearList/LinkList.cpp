#include <stdio.h>
#include <stdlib.h>
#include <status.h>

typedef struct LNode
{
    Elemtype data;
    struct LNode *next;
} LNode, *LinkList;

Status CreateList_L(LinkList *pL, int n);
Status PrintList_L(LinkList L);
Status MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc);

int main(void)
{
    LinkList La = NULL, *pLa = &La;
    LinkList Lb = NULL, *pLb = &Lb;
    LinkList Lc = NULL, *pLc = &Lc;
    CreateList_L(pLa, 3);
    CreateList_L(pLb, 3);
    PrintList_L(La);
    PrintList_L(Lb);
    MergeList_L(La, Lb, Lc);
    PrintList_L(Lc);
    return 0;
}


Status CreateList_L(LinkList *pL,int n)
{
    (*pL) = (LNode *)malloc(sizeof(LNode));
    if(!(*pL))
        exit(OVERFLOW);
    (*pL)->data = 0;
    (*pL)->next = NULL;
    for (int i = 0; i < n;i++)
    {
        LNode *s;
        s = (LNode *)malloc(sizeof(LNode));
        scanf("%d", &s->data);
        s->next = (*pL)->next;
        (*pL)->next = s;
    }
    return (OK);
}
Status PrintList_L(LinkList L)
{
    LNode *p = L;
    while(p->next!=NULL)
    {
        p = p->next;
        printf("%d", p->data);   
    }
    printf("\n");
    return (OK);
}
Status MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc)
{
    //La、Lb按照值非降序排列，将La、Lb归并为Lc且Lc非降序排列
    Lc = (LNode *)malloc(sizeof(LNode));
    if(!Lc)
        exit(OVERFLOW);
    Lc->next = NULL;
    Lc->data = 0;
    LNode *pa = La->next, *pb = Lb->next, *pc = Lc;
    while (pa&&pb)
    {
        if(pa->data<=pb->data)
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;
    free(La);
    free(Lb);
    return OK;
}
#include <stdio.h>
#include <stdlib.h>
#include <status.h>

typedef struct LNode
{
    Elemtype data;
    struct LNode *next;
} LNode, *LinkList;

Status InitList_L(LinkList *pL);
Status CreateList_L(LinkList *pL, int n);
Status PrintList_L(LinkList L);

int main(void)
{
    LinkList L = NULL, *pL = &L;
    InitList_L(pL);
    CreateList_L(pL, 3);
    PrintList_L(L);
    return 0;
}

Status InitList_L(LinkList *pL)
{
    (*pL) = (LNode *)malloc(sizeof(LNode));
    if(!(*pL))
        exit(OVERFLOW);
    (*pL)->data = 0;
    (*pL)->next = NULL;
    return (OK);
}
Status CreateList_L(LinkList *pL,int n)
{
    
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
    return (OK);
}

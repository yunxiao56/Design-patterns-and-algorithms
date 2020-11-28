#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}Lnode;


Lnode* GreateLinklist(int n)//建立一个长度为n的链表
{
    Lnode *p;
    Lnode *List = NULL;
    Lnode *r;
    int x;
    for(int i=0;i<n;i++)
    {
        cout<<"input list data";
        cin>>x;
        p = (Lnode *)malloc(sizeof(Lnode));
        p->data = x;
        if(!List)
        {
            List = p;
        }
        else
        {
            r->next = p;
        }
        r = p;

    }
    return List;
}

void insertnode(Lnode* List,Lnode* m,int e)
{
    Lnode *p ;
    p= (Lnode *)malloc(sizeof(Lnode));
}
int main()
{
    printf("Hello world!\n");
    return 0;
}

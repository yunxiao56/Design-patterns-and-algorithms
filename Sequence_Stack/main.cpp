#include <iostream>
#include "stdlib.h"
#define Maxsize 100
#define StackAdd 10
#include "math.h"
using namespace std;
typedef struct
{
   int *base;
   int *top;
   int satcksize;
}sqStack;

void initStack(sqStack *s)
{
    s->base = (int*)malloc(Maxsize*sizeof(int));
    if(!(s->base)) return;
    s->top=s->base;
    s->satcksize=Maxsize;
}


void pushStack(sqStack* s,int elem)
{
    if((s->top-s->base)>(s->satcksize))
    {
        s->base = (int *)realloc(s->base,(s->satcksize+StackAdd)*sizeof(int));
        s->top = s->base + s->satcksize;
        s->satcksize = s->satcksize+StackAdd;
    }
    *(s->top)=elem;
    s->top++;
}

void Popstack(sqStack* s,int *elem)
{
    if(s->base==s->top) return;
    *elem = *(--(s->top));

}

void ClearStack(sqStack *s)
{
    s->top = s->base;
}

void DistroyStack(sqStack *s)
{
    delete(s->base);
    s->base = s->top =NULL;
    s->satcksize =0;
}

int StackLen(sqStack *s)
{
    return(s->top - s->base);
}
int main()
{
    int temp;
    sqStack s;
    int len,sum=0;
    cout << "Please input a Binary digit" << endl;
    initStack(&s);

    while(temp!=2)
    {
        cin>>temp;
        pushStack(&s,temp);
    }
    len = StackLen(&s);
    for(int i=0;i<len;i++)
    {
        Popstack(&s,&temp);
        sum =sum+temp*pow(2,i);
    }
    cout<<sum;
    DistroyStack(&s);
    return 0;
}

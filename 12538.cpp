#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 50005
using namespace std;
struct TREAP
{
    TREAP *L,*R;
    int r,sz;
    char c;
    void update()
    {
        sz=L->sz+R->sz+1;
    }
}*_null,*root[MAXN],*now;
int dlt;
void newnode(TREAP* &tr,char c=0)
{
    tr=new TREAP();
    tr->c=c;
    tr->sz=1;
    tr->r=rand();
    tr->L=tr->R=_null;
}
void copy(TREAP* &a,TREAP* b)
{
    if(b==_null)a=_null;
    else a=new TREAP(),*a=*b;
}
void build(TREAP* &tr,char _s[],int l,int r)
{
   
    if(l>r)return; 
   // printf("%d %d\n",l,r);
    //system("pause");
    int mid=(l+r)>>1;
    newnode(tr,_s[mid]);
    build(tr->L,_s,l,mid-1);
    build(tr->R,_s,mid+1,r);
    tr->update();
}
void merge(TREAP* &tr,TREAP* l,TREAP* r)
{
    if(r==_null)copy(tr,l);
    else if(l==_null)copy(tr,r);
    else
    {
        if(l->r<r->r)
        {
            copy(tr,l);
            merge(tr->R,l->R,r);
            tr->update();
        }
        else
        {
            copy(tr,r);
            merge(tr->L,l,r->L);
            tr->update();
        }
    }
}
void split(TREAP* tr,TREAP* &l,TREAP* &r,int k)
{
    //printf(" %d\n",k);
    if(k==0)
    {
        copy(r,tr);
        l=_null;
    }
    if(tr->sz<=k)
    {
        copy(l,tr);
        r=_null;
    }
    else if(tr->L->sz>=k)
    {
        copy(r,tr);
        split(tr->L,l,r->L,k);
        r->update();
    }
    else 
    {
        copy(l,tr);
        split(tr->R,l->R,r,k-tr->L->sz-1);
        l->update();
    }
}
void init()
{
    _null=new TREAP();
    _null->sz=0;
    dlt=0;
    for(int i=0;i<MAXN;i++)root[i]=_null;
    now=_null;
}
void go(TREAP* tr)
{
    if(tr==_null)return;
    go(tr->L);
    if(tr->c=='c')dlt++;
    printf("%c",tr->c);
    go(tr->R);
}
void go2(TREAP* tr)
{
    if(tr==_null)return;
    go2(tr->L);
    //if(tr->c=='c')dlt++;
    printf("%c",tr->c);
    go2(tr->R);
}
void ins(TREAP* &tr,TREAP* p,char _s[],int pos)
{
    int len=strlen(_s);
    TREAP *a,*b,*c;
    split(p,a,b,pos);
    build(c,_s,0,len-1);
    merge(a,a,c);
    merge(tr,a,b);
}
void del(TREAP* &tr,TREAP *p,int pos,int len)
{
    TREAP *a,*b,*c;
    split(p,a,b,pos-1);
    //putchar(' ');go2(a);puts("");putchar(' ');go2(b);puts("");
    split(b,b,c,len);
    merge(tr,a,c);
}
void outp(TREAP *tr,int pos,int len)
{
    TREAP *a,*b;
    split(tr,a,b,pos-1);
    split(b,a,b,len);
    go(a);puts("");
}
int main()
{
    init();
    int N,p,v,c;
    char s[110];
    scanf("%d",&N);
    int cnt=1;
    while(N--)
    {
        int op;
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d %s",&p,s);
            p-=dlt;
            ins(now,now,s,p);
            copy(root[cnt++],now);
        }
        else if(op==2)
        {
            scanf("%d %d",&p,&c);
            p-=dlt;c-=dlt;
            del(now,now,p,c);
            copy(root[cnt++],now);
        }
        else if(op==3)
        {
            scanf("%d %d %d",&v,&p,&c);
            p-=dlt;c-=dlt;v-=dlt;
            outp(root[v],p,c);
        }
        //putchar(' ');go2(now);
        //puts("");
    }
    //while(1);
}

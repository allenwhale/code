#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#define MS(s,v) memset(s,v,sizeof(s))
#define foreach(it,x) for(__typeof(x.begin()) it=x.begin(),eit=x.end();it!=eit;it++)
#define SIZE(x) ((int)x.size())
#define INF 0x3f3f3f3f
#ifdef __ALLEN
 #define __lld "%I64d"
#else
 #define __lld "%lld"
#endif
using namespace std;
struct Trie
{
	Trie *l[27],*suffix,*dictsuffix;
	int index;
	Trie(int _i=-1)
	{
		index=_i;
		MS(l,0);
		suffix=dictsuffix=NULL;
	}
}*root;
int Tx,Ty,Px,Py,Pnum;
char T[1010][1010],P[110][110];
int pn[110],failure[110];
int M[1010][1010];
int cnt;
void init()
{
	MS(T,0);
	MS(P,0);
	MS(pn,-1);
	MS(failure,-1);
	MS(M,-1);
	Pnum=cnt=0;
	root=new Trie();
}
int add(char *s,int index)
{
	Trie *tr=root;
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		if(tr->l[s[i]-'a']==NULL)
		{
			tr->l[s[i]-'a']=new Trie();
		}
		tr=tr->l[s[i]-'a'];
	}
	if(tr->index==-1)
	{
		return tr->index=index;
	}
	else return tr->index;
}
void build()
{
	queue<Trie*>q;
	q.push(root);
	while(!q.empty())
	{
		Trie *tr=q.front();q.pop();
		for(int i=0;i<26;i++)
		{
			if(tr->l[i])
			{
				Trie *tmp=tr->suffix;
				while(tmp&&!tmp->l[i])tmp=tmp->suffix;
				if(tmp)tr->l[i]->suffix=tmp->l[i];
				else tr->l[i]->suffix=root;
				tmp=tr->l[i]->suffix;
				if(tmp->index!=-1)tr->l[i]->dictsuffix=tmp;
				else tr->l[i]->dictsuffix=tmp->dictsuffix;
				q.push(tr->l[i]);
			}
		}
	}
}
void match(char *s,int index)
{
	Trie *tr=root;
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		while(tr&&!tr->l[s[i]-'a'])tr=tr->suffix;
		if(tr)tr=tr->l[s[i]-'a'];
		else tr=root;
		for(Trie *tmp=tr;tmp;tmp=tmp->dictsuffix)
		{
			if(tmp->index!=-1)
			{
				M[index][i-Py+1]=tmp->index;
			}
		}
	}
}
void KMP()
{
	for(int i=1,j=failure[0]=-1;i<Px;i++)
	{
		while(j>0&&pn[i]!=pn[j+1])j=failure[j];
		if(pn[i]==pn[j+1])j++;
		failure[i]=j;
	}
	for(int i=0;i<Ty;i++)
	{
		for(int j=0,k=-1;j<Tx;j++)
		{
			while(k>0&&!pn[k+1]!=M[j][i])k=failure[k];
			if(pn[k+1]==M[j][i])k++;
			if(k==Px-1)
			{
				cnt++;
				k=failure[k];
			}
		}
	}
}
void freetrie()
{
	queue<Trie*>q;
	q.push(root);
	while(!q.empty())
	{
		Trie *tr=q.front();q.pop();
		for(int i=0;i<26;i++)
		{
			if(tr->l[i])q.push(tr->l[i]);
		}
		delete tr;
	}
}
int main()
{
	int TT;
	scanf("%d",&TT);
	while(TT--)
	{
		init();
		scanf("%d %d",&Tx,&Ty);
		for(int i=0;i<Tx;i++)
		{
			scanf("%s",T[i]);
		}
		scanf("%d %d",&Px,&Py);
		for(int i=0;i<Px;i++)
		{
			scanf("%s",P[i]);
		}
		for(int i=0;i<Px;i++)
		{
			if((pn[i]=add(P[i],Pnum))==Pnum)Pnum++;
		}
		build();
		for(int i=0;i<Tx;i++)
		{
			match(T[i],i);
		}
		KMP();
		printf("%d\n",cnt);
		freetrie();
	}
	return 0;
}


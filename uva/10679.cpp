#include <stdio.h>
#include <string.h>

struct Trie
{
	Trie *l[52],*suffix,*d_suffix;
	int index;
	Trie()
	{
		memset(l,0,sizeof(l));
		suffix=d_suffix=0;
		index=-1;
	}
}*root;
bool exist[1010];
int equ[1010];
int change(char c)
{
	if('a'<=c&&'z'>=c)
	{
		return c-'a';
	}
	else
	{
		return c-'A'+26;
	}
}
void add(char s[],int index)
{
	Trie *p=root;
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		int c=change(s[i]);
		if(!p->l[c])p->l[c]=new Trie();
		p=p->l[c];
	}
	if(p->index==-1) p->index=index;
	else equ[index]=p->index;
}
void free(Trie *p)
{
	for(int i=0;i<52;i++)
	{
		if(p->l[i]) free(p->l[i]);
	}
	delete p;
}
void build()
{
	Trie *q[1000000],**qf,**qb;
	qf=qb=q;
	*qb++=root;
	while(qf<qb)
	{
		Trie *p=*qf++;
		for(int i=0;i<52;i++)
		{
			if(p->l[i])
			{
				Trie *qq=p->suffix;
				while(qq&&!qq->l[i])qq=qq->suffix;
				if(qq) p->l[i]->suffix=qq->l[i];
				else p->l[i]->suffix=root;
				Trie *r=p->l[i]->suffix;
				if(r->index!=-1) p->l[i]->d_suffix=r;
				else p->l[i]->d_suffix=r->d_suffix;
				*qb++=p->l[i];
			}
		}
	}
}
void match(char t[])
{
	int len=strlen(t);
	Trie *p=root;
	for(int i=0;i<len;i++)
	{
		while(p&&!p->l[change(t[i])])p=p->suffix;
		if(p) p=p->l[change(t[i])];
		else p=root;
		for(Trie *q=p;q;q=q->d_suffix)
		{
			if(q->index!=-1)
			{
				//printf(" %d\n",q->index);
				exist[q->index]=true;
			}
		}
	}
}
void init()
{
	memset(exist,false,sizeof(exist));
	memset(equ,-1,sizeof(equ));
	root=new Trie();
}
int main()
{
	int t;
	char s[100010];
	char p[1010];
	scanf("%d%*c",&t);
	//getchar();
	for(int i=0;i<t;i++)
	{
		init();
		gets(s);
		int n;
		scanf("%d%*c",&n);
		for(int j=0;j<n;j++)
		{
		//	memset(p,0,sizeof(p));
			gets(p);
			add(p,j);
		}
		build();
		match(s);
		free(root);
		for(int j=0;j<n;j++)
		{
			printf("%c\n",exist[j]||(equ[j]!=-1&&exist[equ[j]])?'y':'n');
		}
	}
	return 0;
}


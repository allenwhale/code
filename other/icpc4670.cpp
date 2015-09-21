#include <iostream>
#include <cstdio>
#include <string.h>
#include <queue>
using namespace std;
struct TRIE
{
	TRIE *l[27],*suff,*dict;
	int index;
	TRIE()
	{
		memset(l,0,sizeof(l));
		suff=dict=NULL;
		index=-1;
	}
}*root;
char P[160][80];
char T[1000010];
int occur[160];
int N;
int CNT=0;
void add(char s[],int idx)
{
	TRIE *tr=root;
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		//printf("in %c\n",s[i]);
		if(tr->l[s[i]-'a']==NULL)
			tr->l[s[i]-'a']=new TRIE();
		tr=tr->l[s[i]-'a']; 
	}
	tr->index=idx;
}
void build()
{
	queue<TRIE*>q;
	q.push(root);
	while(!q.empty())
	{
		TRIE *tr=q.front();q.pop();
		for(int i=0;i<26;i++)
		{
			if(tr->l[i])
			{
				TRIE *p=tr->suff;
				while(p&&!p->l[i])p=p->suff;
				if(p)tr->l[i]->suff=p->l[i];
				else tr->l[i]->suff=root;
				
				TRIE *qq=tr->l[i]->suff;
				if(qq->index>0)tr->l[i]->dict=qq;
				else tr->l[i]->dict=qq->dict;
				q.push(tr->l[i]);
			}
		}
	}
}
void match()
{
	int len=strlen(T);
	TRIE *tr=root;
	for(int i=0;i<len;i++)
	{
		//printf("%c\n",T[i]);
		while(tr&&!tr->l[T[i]-'a'])
			tr=tr->suff;
		//printf("%d\n",tr==root);
		if(tr)tr=tr->l[T[i]-'a'];
		else tr=root;
		//printf(" %d %d\n",tr->index,tr==root);
		for(TRIE *p=tr;p;p=p->dict)
		{
			if(p->index!=-1)
			{
				//if(occur[p->index]==false)
				occur[p->index]++;
			}			
		}
	}
}
void print(TRIE *tr)
{
	for(int i=0;i<26;i++)
	{
		if(tr->l[i])
		{
			//printf("   %c%d\n",i+'a',tr->l[i]->index);
			print(tr->l[i]);
		}
	}
}
void freeTRIE(TRIE *tr)
{
	for(int i=0;i<26;i++)
	{
		if(tr->l[i])
			freeTRIE(tr->l[i]);
	}
	delete tr;
}
int main()
{
	while(~scanf("%d",&N)&&N)
	{
		memset(P,0,sizeof(P));
		memset(T,0,sizeof(T));
		root=new TRIE();
		for(int i=1;i<=N;i++)
		{
			scanf("%s",P[i]);
			add(P[i],i);
		}
		print(root);
		scanf("%s",T);
		build();
		CNT=0;
		memset(occur,0,sizeof(occur));
		match();
		vector<string>vc;
		int mx=0;
		for(int i=1;i<=N;i++)
		{
			if(occur[i]==mx)vc.push_back(P[i]);
			else if(occur[i]>mx)
			{
				vc.clear();
				mx=occur[i];
				vc.push_back(P[i]);
			}
		}
		printf("%d\n",mx);
		int sz=vc.size();
		for(int i=0;i<sz;i++)
		{
			printf("%s\n",vc[i].c_str());
		}
		freeTRIE(root);
	}
}


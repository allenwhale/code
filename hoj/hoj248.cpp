#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <ctype.h>
#include <complex>
#define FF first
#define SS second
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define PPB() pop_back()
#define PPF(a) push_front(a)
#define PF() pop_front()
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
typedef long long ll;
typedef complex<int> cI;
typedef complex<double> cD;
typedef pair<int,int> pI;
typedef pair<double,double>pD;
vector<char>res;
int print=0;
int N;
struct TRIE
{
	TRIE *l[26];
	bool tf;
	int cnt;
	char c;
	TRIE()
	{
		MS(l,0);
		cnt=0;c=0;
		tf=false;
	}
}*root;

void add(char *in)
{
	int len=strlen(in);
	TRIE *tr=root;
	for(int i=0;i<len;i++)
	{
		if(tr->l[in[i]-'a']==NULL)
		{
			tr->l[in[i]-'a']=new TRIE();
			tr->l[in[i]-'a']->c=in[i];
		}
		tr=tr->l[in[i]-'a'];
	}
	tr->tf=true;
}
int cnt=0;
void predfs(TRIE *tr)
{
	tr->cnt=1;
	for(int i=0;i<26;i++)
	{
		if(tr->l[i]!=NULL)
		{
			predfs(tr->l[i]);
			tr->cnt=max(tr->cnt,tr->l[i]->cnt+1);
		}
	}
}
void dfs(TRIE *tr)
{
	if(tr->c)res.PB(tr->c);
	if(tr->tf)
	{
		print++;
		res.PB('P');
	}
	for(int i=0;i<26;i++)
	{
		if(tr->l[i]!=NULL&&tr->cnt-1!=tr->l[i]->cnt)
		{
			dfs(tr->l[i]);
		}
	}
	for(int i=0;i<26;i++)
	{
		if(tr->l[i]!=NULL&&tr->cnt-1==tr->l[i]->cnt)
		{
			dfs(tr->l[i]);
		}
	}
	if(print<=N-1)
	{
		res.PB('-');
	}
}

int main()
{
	scanf("%d%*c",&N);
	char s[30];
	root=new TRIE();
	for(int i=0;i<N;i++)
	{
		//scanf("%s",s);
		gets(s);
		add(s);
	}
	predfs(root);
	dfs(root);
	printf("%d\n",SIZE(res));
	foreach(it,res)
	{
		printf("%c\n",*it);
	}
	return 0;
}


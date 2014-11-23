#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define MS(s,v) memset(s,v,sizeof(s))
#ifdef __ALLEN
 #define __lld "%I64d"
#else
 #define __lld "%lld"
#endif
using namespace std;
int result[1010];
int s[10000];
int idx;
struct node
{
	int n;
	node *left,*right;
	node(){n=-1,left=right=NULL;}
	node(int _n){n=_n,left=right=NULL;}
};
node *root;
void init()
{
	root=NULL;
	MS(result,0);
}
node* create()
{
	//printf("  %d\n",n);
	if(s[idx]==-1)return NULL;
	node *tr=new node(s[idx]);
	idx++;
	tr->left=create();
	idx++;
	tr->right=create();
	return tr;
}
void count(node *tr,int ptr)
{
	if(tr==NULL)return;
	//printf("%d\n",tr->n);
	result[ptr]+=tr->n;
	count(tr->left,ptr-1);
	count(tr->right,ptr+1);
}
int main()
{
	int N=0;
	while(~scanf("%d",&s[1])&&s[1]!=-1)
	{
		init();
		idx=1;
		int cnt1=1,cnt2=0;
		int sz=2;
		while(1)
		{
			scanf("%d",&s[sz++]);
			if(s[sz-1]==-1)cnt2++;
			else cnt1++;
			if(cnt1+1==cnt2)break;
		}
		root=create();
		//puts("done");
		count(root,500);
		printf("Case %d:\n",++N);
		int i=0;
		while(result[i]==0)i++;
		printf("%d",result[i++]);
		for(;result[i]!=0;i++)
		{
			printf(" %d",result[i]);
		}
		puts("\n");
	}
	return 0;
}


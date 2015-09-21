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
struct node
{
	char n;
	node *right,*left;
	node()
	{
		n=0;
		right=NULL;
		left=NULL;
	}
	node(char _n)
	{
		n=_n;
		right=NULL;
		left=NULL;
	}
}*root;
node* create(char *pre,char *mid,int len)
{
	if(len==0)
	{
		return NULL;
	}
	int k=0;
	while(pre[0]!=mid[k])k++;
	node *tr=new node(pre[0]);
	tr->left=create(pre+1,mid,k);
	tr->right=create(pre+1+k,mid+1+k,len-1-k);
	return tr;
}
void output(node *tr)
{
	if(tr->left!=NULL)output(tr->left);
	if(tr->right!=NULL)output(tr->right);
	printf("%c",tr->n);
}
int main()
{
	char pre[30],mid[30];
	while(~scanf("%s %s",pre,mid))
	{
		root=NULL;
		root=create(pre,mid,strlen(pre));
		output(root);
		puts("");
	}
	return 0;
}


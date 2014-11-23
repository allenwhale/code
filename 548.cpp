#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#define MS(s,v) memset(s,v,sizeof(s))
#ifdef __ALLEN
 #define __lld "%I64d"
#else
 #define __lld "%lld"
#endif
using namespace std;
vector<pair<int,int> >vc;
struct node
{
	int n;
	node *left,*right;
	node()
	{
		n=-1;
		left=right=NULL;
	}
	node(int _n)
	{
		n=_n;
		left=right=NULL;
	}
}*root;
node* create(int *suf,int *mid,int len)
{
	if(len==0)return NULL;
	int k=0;
	while(suf[len-1]!=mid[k])k++;
	node *tr=new node(suf[len-1]);
	tr->left=create(suf,mid,k);
	tr->right=create(suf+k,mid+1+k,len-1-k);
	return tr;
}
void count(node *tr,int now)
{
	if(tr->left==NULL&&tr->right==NULL)vc.push_back(make_pair(now+tr->n,tr->n));
	if(tr->left!=NULL)count(tr->left,now+tr->n);
	if(tr->right!=NULL)count(tr->right,now+tr->n);
}

int main()
{
	char suf[1000010],mid[1000010];
	int s[100010],m[100010];
	while(gets(mid)!=NULL)
	{
		vc.clear();
		gets(suf);
		int i=0;
		char *ptr=strtok(mid," ");
		while(ptr!=NULL)
		{
			sscanf(ptr,"%d",&m[i++]);
			ptr=strtok(NULL," ");
		}
		i=0;
		ptr=strtok(suf," ");
		while(ptr!=NULL)
		{
			sscanf(ptr,"%d",&s[i++]);
			ptr=strtok(NULL," ");
		}
		root=create(s,m,i);
		count(root,0);
		sort(vc.begin(),vc.end());
		printf("%d\n",vc[0].second);
	}
	return 0;
}


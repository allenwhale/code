#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
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
struct node
{
	node *left,*right;
	int num;
	node()
	{
		num=-1;
		left=right=NULL;
	}
	node(int _n)
	{
		num=_n;
		left=right=NULL;
	}
};
bool tf=false;
int N;
node *root;
char s[10000];
int sn=0;
inline bool ok(char c)
{
	return c!='\n'&&c!=' ';
}
inline char Getchar()
{
	char c;
	while(!ok((c=getchar())));
	return c;
}
inline int Getint(char *ss)
{
	int x=0;
	int d;
	if(*ss=='-')d=-1,ss++;
	else d=1;
	while(*ss>='0'&&*ss<='9')
	{
		x=x*10+(*ss)-'0';
		ss++;
	}
	return x*d;
}
node* create(char *ss,int len)
{
	/*
	printf("%d   ",len);
	for(int i=0;i<len;i++)
		printf("%c",ss[i]);
	puts("");
	system("pause");
	*/
	if(len==2)return NULL;
	ss++;
	int num=Getint(ss);
	//printf("%d\n",num);
	while((*ss=='-')||(*ss>='0'&&*ss<='9'))ss++,len--;
	/*
	printf("  %d\n",num);
	for(int i=0;i<len;i++)
		printf("%c",ss[i]);
	puts("");	
	*/
	node *tr=new node(num);
	int l=0,r=0,cnt=0;
	while(true)
	{
		if(ss[cnt]=='(')l++;
		else if(ss[cnt]==')')r++;
		cnt++;
		if(l==r)break;
	}
	//printf("%d\n",cnt);
	tr->left=create(ss,cnt);
	tr->right=create(ss+cnt,len-2-cnt);
	return tr;
}
void go(node *tr,int now)
{
	if(tr==NULL)return;
	//printf("%d %d %d\n",tr->num,now,tr->num+now);
	now+=tr->num;

	if(tr->left==NULL&&tr->right==NULL)
	{
		//printf("   %d %d\n",tr->num,now);
		if(now==N)tf=true;
		return;
	}
	
	if(tr->left!=NULL)go(tr->left,now);
	if(tr->right!=NULL)go(tr->right,now);
}
int main()
{
	while(~scanf("%d",&N))
	{
		root=new node();
		tf=false;
		sn=0;
		MS(s,0);
		int l=0,r=0;
		while(true)
		{
			s[sn++]=Getchar();
			if(s[sn-1]=='(')l++;
			else if(s[sn-1]==')')r++;
			//printf("%d %c\n",sn,s[sn-1]);
			if(l==r)break;
		}
		//puts(s);
		root=create(s,strlen(s));
		//puts("done");
		go(root,0);
		if(root==NULL)
		{
			puts("no");
			continue;
		}
		if(tf)puts("yes");
		else puts("no");
	}
	return 0;
}


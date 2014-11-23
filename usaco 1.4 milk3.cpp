/*
ID: allenwh1
PROG: milk3
LANG: C++
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
int a,b,c,p=0;
bool data[50][50][50];
int d[50];
void DFS(int aa,int bb,int cc)
{
	if(data[aa][bb][cc])return;
	//printf("%d %d %d\n",aa,bb,cc);
	data[aa][bb][cc]=true;
	if(aa==0)d[p++]=cc;
	if(aa<a&&bb!=0)
	{
		int f=min(a-aa,bb);
		DFS(aa+f,bb-f,cc);
	}
	if(aa<a&&cc!=0)
	{
		int f=min(a-aa,cc);
		DFS(aa+f,bb,cc-f);
	}
	if(bb<b&&aa!=0)
	{
		int f=min(b-bb,aa);
		DFS(aa-f,bb+f,cc);
	}
	if(bb<b&&cc!=0)
	{
		int f=min(b-bb,cc);
		DFS(aa,bb+f,cc-f);
	}
	if(cc<c&&aa!=0)
	{
		int f=min(c-cc,aa);
		DFS(aa-f,bb,cc+f);
	}
	if(cc<c&&bb!=0)
	{
		int f=min(c-cc,bb);
		DFS(aa,bb-f,cc+f);
	}
}
int main()
{	
	freopen("milk3.in","r",stdin);
	freopen("milk3.out","w",stdout);
	memset(data,false,sizeof(data));
	scanf("%d %d %d",&a,&b,&c);
	DFS(0,0,c);
	sort(d,d+p);
	int c=p;
	for(int i=0;i<p;i++)
	{
		printf("%d%c",d[i],--c?' ':'\n');
	}
    return 0;
}

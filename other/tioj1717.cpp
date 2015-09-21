#include <string.h>
#include <stdio.h>
#include <iostream>
#include <deque>

using namespace std;
deque < int > dq[1010];
int work[1010];
int fini[1010];
bool vis[1010];
int in[1010];
int out[1010];
int deg[1010];
int t=0;

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		t=0;
		for(int j=0;j<1010;j++)dq[j].clear();
		memset(deg,0,sizeof(deg));
		memset(in,0,sizeof(in));
		int w;
		scanf("%d",&w);
		for(int j=0;j<w;j++)
		{
			int need;
			int num;
			scanf("%d",&work[j]);
			scanf("%d",&num);
			for(int k=0;k<num;k++)
			{
				int a;
				scanf("%d",&a);
				dq[j].push_back(a-1);
				deg[a-1]++;
			}
		}
		for(int j=0;j<w;j++)
		{
			int s=0;
			while(deg[s]!=0)s++;
			out[s]=in[s]+work[s];
			t=max(t,out[s]);
			deg[s]=-1;
			int size=dq[s].size();
			for(int k=0;k<size;k++)
			{
				deg[dq[s][k]]--;
				in[dq[s][k]]=max(in[dq[s][k]],out[s]);
			}
		}
		printf("%d\n",t);
		
	}
//	while(1);
}

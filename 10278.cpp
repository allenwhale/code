#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;
int maxx,minn;
int mxs,mns;
int f[110];
int d[510];
struct state
{
	//int fr;
	int to;
	int ct;
	state(int tto,int tct)
	{
		//fr=tfr;
		to=tto;
		ct=tct;
	}
	bool operator < (const state &n) const
	{
		if(ct<n.ct)return false;
		return true;
	}
};
struct vis
{
	bool fire;
	bool home;
	
}vis[510];
int main()
{
	int N;
	int i,j,p,k,l,z,x,b,st;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		int fire,ins;
		scanf("%d %d",&fire,&ins);
		for(j=0;j<fire;j++)
		{
			scanf("%d",&f[j]);
		}
		vector<state>gra[ins+1];
		char s[30];
		getchar();
		int fr,to,ct;
		while(gets(s)!=NULL && s[0]!='\0')
		{
			sscanf(s,"%d %d %d",&fr,&to,&ct);
			gra[fr].push_back(state(to,ct));
			gra[to].push_back(state(fr,ct));
		}
		bool ck=true;
		for(int h=1;h<=ins&&ck!=false;h++)
		{
			if(gra[h].empty())ck=false;
		}
		if(ck==false)
		{
			printf("1\n\n");
			continue;
		}
		minn=999999;
		for(k=1;k<=ins;k++)
		{
			maxx=0;
			for(l=1;l<=ins;l++)
			{
				memset(vis,false,sizeof(vis));
				memset(d,0,sizeof(d));
				priority_queue<state>PQ;
				for(p=0;p<fire;p++)
				{
					vis[f[p]].fire=true;
				}
				vis[k].fire=true;
				st=l;
				d[st]=0;
				vis[st].home=true;
				int size_st=gra[st].size();
				for(x=0;x<size_st;x++)
				{
					PQ.push(gra[st][x]);
				}
				if(vis[st].fire==true)continue;
				while(!PQ.empty())
				{
					state u=PQ.top();
					b=u.to;
					PQ.pop();
					d[u.to]=u.ct;
					if(vis[u.to].fire==true)break;
					if(vis[u.to].home==true)continue;
					vis[u.to].home=true;
					int size=gra[u.to].size();
					for(z=0;z<size;z++)
					{
						state tmp=gra[u.to][z];
						if(vis[tmp.to].home==true)continue;
						PQ.push(state(tmp.to,tmp.ct+d[u.to]));
					}
				}
				if(maxx<d[b])
				{
					maxx=d[b];
					mxs=k;
				}
			}
			if(minn>maxx)
			{
				minn=maxx;
				mns=mxs;
			}
		}
		if(mns==0)printf("1\n");
		else printf("%d\n",mns);
		if(i<N)printf("\n");
	}
    return 0;
}

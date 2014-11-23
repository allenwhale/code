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
vector<int>vc,vc2;
int main()
{
	char s[1000];
	while(gets(s)!=NULL)
	{
		vc.clear();
		char *ptr=strtok(s," ");
		while(ptr!=NULL)
		{
			int tmp;
			sscanf(ptr,"%d",&tmp);
			vc.push_back(tmp);
			ptr=strtok(NULL," ");
		}
		vc2=vc;
		reverse(vc.begin(),vc.end());
		vector<int>::iterator it=vc.begin();
		vector<int>ans;
		while(it!=vc.end())
		{
			vector<int>::iterator tmp=max_element(it,vc.end());
			//printf("  %d %d\n",*it,*tmp);
			if(tmp==it);
			else if(tmp==vc.end()-1)
			{
				ans.push_back((int)(it-vc.begin()+1));
				reverse(it,vc.end());
			}
			else
			{
				ans.push_back((int)(tmp-vc.begin()+1));
				reverse(tmp,vc.end());
				ans.push_back((int)(it-vc.begin()+1));
				reverse(it,vc.end());
			}
			it++;
		}
		foreach(tmp,vc2)
		{
			printf("%d%c",*tmp,tmp==vc2.end()-1?'\n':' ');
		}
		foreach(tmp,ans)
		{
			printf("%d ",*tmp);
		}
		printf("0\n");
	}
	return 0;
}


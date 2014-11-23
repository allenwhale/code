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
char s1[1010],s2[1010];
vector<string>vc1,vc2;
int id=0;
char tmp[100];
void spilt(char s[])
{
	//puts("in");
	while(s[id]&&!(('A'<=s[id]&&'Z'>=s[id])||
			('a'<=s[id]&&'z'>=s[id])||
			('0'<=s[id]&&'9'>=s[id])))id++;
	MS(tmp,0);
	int cnt=0;
	while(s[id]&&(('A'<=s[id]&&'Z'>=s[id])||
			('a'<=s[id]&&'z'>=s[id])||
			('0'<=s[id]&&'9'>=s[id])))tmp[cnt++]=s[id],id++;
}
int main()
{
	int t=1;
	while(gets(s1)!=NULL)
	{
		gets(s2);
		if(strcmp(s1,"")==0||strcmp(s2,"")==0)
		{
			printf("%2d. Blank!\n",t++);
			continue;
		}
		vc1.clear();vc2.clear();
		id=0;
		while(true)
		{
			spilt(s1);
			//puts(tmp);
			if(tmp[0]==0)break;
			vc1.push_back(tmp);
		}
		id=0;
		while(true)
		{
			spilt(s2);
			if(tmp[0]==0)break;
			vc2.push_back(tmp);
		}
		int sz1=SIZE(vc1),sz2=SIZE(vc2);
		int dp[1010][1010];
		for(int i=0;i<sz1;i++)
		{
			for(int j=0;j<sz2;j++)
			{
				//cout << vc1[i] <<" "<< vc2[j]<<"\n";
				if(!i||!j)dp[i][j]=0;
				if(vc1[i]==vc2[j])dp[i][j]=dp[i-1][j-1]+1;
				else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
		printf("%2d. Length of longest match: %d\n",t++,dp[sz1-1][sz2-1]);
	}
	return 0;
}


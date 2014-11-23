#include <stdio.h>
#include <iostream>
#include <deque>
#include <string.h>
using namespace std;
deque<int>DQ[30];
deque<int>QD[30];
int fin[30];
int sd[30];
int con;
int day[30];
bool ex[30];
int num[30];
void init()
{
	con=0;	
	memset(fin,0,sizeof(fin));
	memset(num,0,sizeof(num));
	memset(day,0,sizeof(day));
	memset(ex,false,sizeof(ex));
	int i;
	for(i=0;i<=26;i++)
	{
		sd[i]=9999999;
		QD[i].clear();
		DQ[i].clear();
	}
}
int N;
int main()
{
	scanf("%d",&N);
	getchar();
	getchar();
	char s[40];
	int i,j,size,k;
	for(i=1;i<=N;i++)
	{
		if(i>1)printf("\n");
		init();
		while(gets(s)!=NULL)
		{
			if(s[0]=='\0')break;
			char w[2];
			int c;
			sscanf(s,"%s %d",w,&c);
			ex[w[0]-'A']=true;
			day[w[0]-'A']=c;
			int len=strlen(s);
			j=len-1;
			while(s[j]!=' ')
			{
				if('Z'<s[j]||s[j]<'A')break;		
				num[w[0]-'A']++;
				ex[s[j]-'A']=true;
				DQ[s[j]-'A'].push_back(w[0]-'A');
				QD[w[0]-'A'].push_back(s[j]-'A');
				j--;
			}
		}
		for(j=0;j<26;j++)
		{
			if(ex[j])con++;
		}
		int ans=0,done=0;
		bool tf=true;
		while(tf)
		{
			for(j=0;j<26;j++)
			{
				if(ex[j]&&num[j]==0)
				{
					ex[j]=false;
					size=DQ[j].size();
					for(k=0;k<size;k++)
					{
						num[DQ[j][k]]--;
					}
					size=QD[j].size();
					for(k=0;k<size;k++)
					{
						fin[j]=max(fin[j],fin[QD[j][k]]);
					}
					fin[j]+=day[j];
					ans=max(ans,fin[j]);
					done++;
					if(done>=con)
					{
						tf=false;
						break;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
    return 0;
}

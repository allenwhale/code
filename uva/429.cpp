#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
int vis[210];
int nvis=0;
int last[10000];
int main()
{
	char dic[210][12],s[24];
	int t,i,j,dc;
	scanf("%d",&t);
	getchar();
	
	for(i=1;i<=t;i++)
	{
		getchar();
		dc=0;
		while(gets(s))
		{
			if(s[0]=='*')break;
			strcpy(dic[i],s);
			i++;
		}
		char s1[12],s2[12];
		int st,ed;
		//getchar();
		while(gets(s))
		{
			queue<int>Q;
			if(s[0]=='\0')break;
			sscanf(s,"%s %s",s1,s2);
			
			for(j=0;j<i;j++)
			{
				if(strcmp(dic[j],s1)==0)
				{
					st=j;
				}
				else if(strcmp(dic[j],s2)==0)
				{
					ed=j;
				}
			}
				nvis++;
				vis[st]=nvis;
				Q.push(st);
				int p_1=0,p_2=1;
				last[p_1]=0;
				while(!Q.empty())
				{
					//printf("in");
					int u=Q.front();
					Q.pop();
					if(u==ed)
					{
						//printf("12344");
						break;
					}
					for(j=0;j<i;j++)
					{
						//printf("for");
						if(strlen(dic[u])!=strlen(dic[j]))
						{
							//printf("%d %d",strlen(dic[u]),strlen(dic[j])),
							//printf("con1");
							continue;
						}
						if(vis[j]==nvis)
						{
							//printf("con2");
							continue;
						}
						int dcwr=0;
						for(int k=0;k<strlen(dic[u]);k++)
						{
							if(dic[u][k]!=dic[j][k])
							{
								dcwr++;
							}
							//printf("\t%d",dcwr);
						}
						if(dcwr==1)
						{
							last[p_2]=last[p_1]+1;
							vis[j]=nvis;
							p_2++;
							Q.push(j);
						}
					}
					p_1++;
				}
				printf("%s %s %d\n",s1,s2,last[p_1]);
			}
		}
	
    return 0;
}

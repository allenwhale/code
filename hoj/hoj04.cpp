#include<cstdio>
#include<algorithm>
#include<cstring>
#define SIZE 100001
int N;
int data[100001];
int pos[100001];
int bt[100001]={0};

inline void add(int i)
{
    while(i<=N)
    {
        bt[i]++;
        i+=(i&-i);
    }
}
 
inline int sum(int i)
{
    int a=0;
    while(i)
    {
        a+=bt[i];
        i-=(i&-i);
    }
    return a;
}
 
int main()
{
    long long int ans,dp;
    scanf("%d",&N);
    dp=0;
    for(int i=0;i<N;++i)
    {
        scanf("%d",&data[i]);
        dp+=i-sum(data[i]);
        add(data[i]);
        pos[data[i]]=i+1;
    }
    ans=dp;
    for(int i=1;i<N;++i)
    {
        dp=dp+N-2*pos[i]+1;
        ans=std::min(ans,dp);
    }
    printf("%lld\n",ans);
    //while(1);
}

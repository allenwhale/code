#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
struct Bnum
{
    int n;
    vector<int>d;
    Bnum()
    {
        n=0;d.clear();
    }
    void update()
    {
        int sz=d.size();
        for(int i=0;i<sz-1;i++)
        {
            if(d[i]>=10)
            {
                d[i+1]+=d[i]/10;
                d[i]%=10;
            }
        }
        if(d[sz-1]>=10)
        {
            d.push_back(d[sz-1]/10);
            d[sz-1]%=10;
        }
        n=d.size();
    }
    void show()
    {
        for(int i=n-1;i>=0;i--)
        {
            printf("%d",d[i]);
        }
        puts("");
    }
};
void equal(Bnum &a,Bnum b)
{
    a.n=b.n;
    a.d=b.d;
}
Bnum add(Bnum a,Bnum b)
{
    Bnum res;
    if(a.n<b.n)swap(a,b);
    res.d=a.d;
    for(int i=0;i<b.n;i++)
    {
        res.d[i]+=b.d[i];
    }
    res.update();
    return res;
}
Bnum dp[1010];
int main()
{
    dp[1].n=1;
    dp[1].d.push_back(2);
    dp[2].n=1;
    dp[2].d.push_back(5);
    dp[3].n=2;
    dp[3].d.push_back(3);
    dp[3].d.push_back(1);
 
    for(int i=4;i<=1000;i++)
    {
        equal(dp[i],add(add(dp[i-1],dp[i-1]),add(dp[i-2],dp[i-3])));
    }
    int N;
    while(~scanf("%d",&N))
    {
        dp[N].show();
    }
}

#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int N;
    while(~scanf("%d",&N)&&N)
    {
        int sum=0,ans=0;
        while(N--)
        {
            int idx;scanf("%d",&idx);
            sum+=idx;
            if(sum<0)sum=0;
            if(sum>ans)ans=sum;
        }
        if(ans)printf("The maximum winning streak is %d.\n",ans);
        else printf("Losing streak.\n");
    }
}

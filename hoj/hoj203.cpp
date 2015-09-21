#include<stdio.h>
#include<set>

using std::multiset;

const int MAXN=100000+9;

int h[MAXN],s[MAXN],w[MAXN];
long long f[MAXN];
int main()
{
        int n,l,i;
        int sum=0,head=1,tail=0;
        multiset<long long> val;
        scanf("%d%d",&n,&l);
        for(i=1;i<=n;++i)
        {
                scanf("%d%d",h+i,w+i);

                for(s[++tail]=i-1;head<tail && h[i]>=h[s[tail]];--tail)
                        val.erase(val.find(f[s[tail-1]]+h[s[tail]]));
                val.insert(f[s[tail]]+h[i]);
                s[tail+1]=i;
				for(sum+=w[i];sum>l;sum-=w[s[head]])
                {
                        val.erase(val.find(f[s[head]]+h[s[head+1]]));
                        if(++s[head]==s[head+1])
                                ++head;
                        else val.insert(f[s[head]]+h[s[head+1]]);
                }
                f[i]=*val.begin();
        }
        printf("%lld\n",f[n]);
        return 0;
}

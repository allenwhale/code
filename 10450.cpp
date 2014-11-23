#include <stdio.h>
typedef long long ll;
ll fib[60];
ll f(int a)
{
	if(fib[a]!=-1)return fib[a];
	if(a==1||a==2)return fib[a]=1;
	return fib[a]=f(a-1)+f(a-2);
}
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<60;i++)fib[i]=-1;
	for(int i=1;i<=N;i++)
	{
		int t;
		scanf("%d",&t);
		printf("Scenario #%d:\n",i);
		printf("%lld\n\n",f(t+2));
	}
    return 0;
}

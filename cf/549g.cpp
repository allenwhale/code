#include <bits/stdc++.h>
using namespace std;
int N;
int s[200010];
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d",&s[i]),s[i]+=i;
    sort(s,s+N);
    for(int i=0;i<N;i++)
        s[i]-=i;
    bool ans=true;
    for(int i=0;i<N-1;i++)
        if(s[i]>s[i+1])
            ans=false;
    if(ans==false)puts(":(");
    else{
        for(int i=0;i<N;i++)
            printf("%d ",s[i]);
        puts("");
    }
    return 0;
}

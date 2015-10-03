#include <bits/stdc++.h>
using namespace std;
int s[1010];
int v[1010]={0};
int main(){
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d",&s[i]);
    
    int c=0;
    int ans=0;
    while(c<N){
        for(int i=0;i<N;i++)
            if(!v[i])
                if(s[i]<=c)
                    v[i]=1,c++;
        if(c==N)break;
        ans++;
        for(int i=N-1;i>=0;i--)
            if(!v[i])
                if(s[i]<=c)
                    v[i]=1,c++;
        if(c==N)break;
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int s[500*500+100];
map<int,int>mp;
int b[510];
int main(){
    int N;
    scanf("%d",&N);
    for(int i=0;i<N*N;i++){
        scanf("%d",&s[i]);
        mp[s[i]]++;
    }
    sort(s,s+N*N);
    reverse(s,s+N*N);
    int now=0;
    for(int i=0;i<N;i++){
        while(mp[s[now]]==0)now++;
        b[i]=s[now];
        mp[s[now]]--;
        for(int j=0;j<i;j++){
            mp[__gcd(s[now],b[j])]-=2;
        }
        now++;
    }
    for(int i=0;i<N;i++)
        printf("%d ",b[i]);
    puts("");
    return 0;
}

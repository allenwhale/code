#include <bits/stdc++.h>
using namespace std;
int s[110];
vector<int>vc;
int N,T;
void make(){
    for(int i=0;i<N;i++){
        if(vc.back()<=s[i])
            vc.push_back(s[i]);
        else{
            int pos=upper_bound(vc.begin(),vc.end(),s[i])-vc.begin();
            vc[pos]=s[i];
        }
    }
}
int main(){
    scanf("%d%d",&N,&T);
    for(int i=0;i<N;i++)
        scanf("%d",&s[i]);
    vc.push_back(-1);
    int time=min(N,T);
    for(int t=0;t<time;t++){
        make();
    }
    int ans=vc.size()-1;
    make();
    int d=vc.size()-(ans+1);
    ans+=(T-time)*d;
    printf("%d\n",ans);
    return 0;
}

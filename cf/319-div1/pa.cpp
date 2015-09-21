#include <bits/stdc++.h>
using namespace std;
int p[1000], pn=0;
int main(){
    vector<int>vc;
    p[pn++]=2;
    for(int i=3;i<=1000;i+=2){
        bool tf=true;
        for(int j=0;j<pn&&p[j]*p[j]<=i;j++){
            if(i%p[j]==0){
                tf=false;break;
            }
        }
        if(tf)
            p[pn++]=i;
    }
    for(int i=0;i<pn;i++){
        int tmp=p[i];
        while(tmp<=1000){
            vc.push_back(tmp);
            tmp*=p[i];
        }
    }
    sort(vc.begin(),vc.end());
    int cnt=0;
    int N;
    scanf("%d",&N);
    for(int i=0;i<(int)vc.size();i++){
        if(vc[i]<=N)
            cnt++;
        else
            break;
    }
    printf("%d\n", cnt);
    for(int i=0;i<cnt;i++)
        printf("%d%c", vc[i],(i==cnt-1)?'\n':' ');
    return 0;
}

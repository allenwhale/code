#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
#define N 80005
vector<int> arr;
int p[N*2],add[N*2];
int _find(int k){
    if(p[k]==k) return k;
    return p[k]=_find(p[k]);
}
int main(){
    int t,n,m,x,y,i,j,k,X,Y;
    long long int all,tmp,r;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        memset(add,0,sizeof(add));
        arr.clear();
        for(i=0;i<n*2;i++)
            p[i]=i;
        tmp=r=0;
        for(i=0;i<m;i++){
            scanf("%d%d%d",&x,&y,&k);
            if(k==0){
                X=_find(x*2);
                Y=_find(y*2);
                if(x!=y){
                    if(X>Y) swap(X,Y);
                    p[Y]=X;
                    X=_find(x*2+1);
                    Y=_find(y*2+1);
                    if(X>Y) swap(X,Y);
                    p[Y]=X;;
                }
            }
            else{
                r++;
                X=_find(x*2+1);
                Y=_find(y*2);
                if(x!=y){
                    if(X>Y) swap(X,Y);
                    p[Y]=X;
                    X=_find(x*2);
                    Y=_find(y*2+1);
                    if(X>Y) swap(X,Y);
                    p[Y]=X;;
                }
            }
        }
        for(i=0;i<n*2;i++){
            X=_find(i);
            if(i%2==0) add[X]++;
            if(X!=i) add[i]=-1;
        }
        for(i=0;i<n*2;i+=2){
            if(add[i]!=-1){
                tmp+=min(add[i],add[i+1]);
                if(add[i]!=add[i+1])
                    arr.push_back(abs(add[i]-add[i+1]));
            }
        }
        sort(arr.begin(),arr.end());
        for(i=0;i<arr.size();i++){
            if(tmp+arr[i]>n/2) break;
            tmp+=arr[i];
        }
        printf("%lld\n",tmp*(n-tmp)-r);
    }
}

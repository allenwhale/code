#include <bits/stdc++.h>
using namespace std;
int N, K;

//int sg(int x){
    //if(x == 0)return 0;
    //vector<int> res;
    //res.push_back(sg(x - 1));
    //if(K % 2 == 0){
        //if(x % 2 == 0)
            //res.push_back(0);
    //}else{
        //if(x % 2 == 0)
            //res.push_back(sg(x / 2));
    //}
    //sort(res.begin(), res.end());
    //int ans = 0;
    //for(int x : res){
        //if(x == ans)
            //ans++;
        //else break;
    //}
    //return ans;
//}
//
int sg(int x){
    if(x == 0)return 0;
    if(K % 2 == 0){
        if(x == 2)return 2;
        if(x == 1 || x == 4 || x == 6)return 1;
        if(x == 3 || x == 5)return 0;
        return (x % 2) == 1 ? 0 : 1;
    }else{
        if(x == 1 || x == 3 || x == 8)return 1;
        if(x == 2 || x == 5 || x == 7)return 0;
        if(x == 4 || x == 6)return 2;
        if(x % 2 != 0)return 0;
        return sg(x / 2) == 1 ? 2 : 1;
    }
}

int main(){
    scanf("%d%d", &N, &K);
    int ans = 0;
    for(int i=0;i<N;i++){
        int x;
        scanf("%d", &x);
        ans ^= sg(x);
    }
    printf("%s\n", ans ? "Kevin" : "Nicky");
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
char in[100];
int num[100010];
int sta[100010];
int occ[100010];
int hetero = 0, homo = 0;
int main(){
    freopen("homo.in", "r", stdin);
    freopen("homo.out", "w", stdout);
    int N;
    scanf("%d", &N);
    vector<int> vc;
    for(int i=0;i<N;i++){
        scanf("%s", in);
        if(in[0] == 'i'){
            sta[i] = 1;
        }else{
            sta[i] = 0;
        }
        scanf("%d", &num[i]);
        vc.push_back(num[i]);
    }
    sort(vc.begin(), vc.end());
    memset(occ, 0, sizeof(occ));
    vc.erase(unique(vc.begin(), vc.end()), vc.end());
    for(int i=0;i<N;i++)
        num[i] = lower_bound(vc.begin(), vc.end(), num[i]) - vc.begin();
    for(int i=0;i<N;i++){
        //printf("num %d %d\n", sta[i], num[i]);
        if(sta[i]){
            occ[num[i]]++;
            //printf("occ %d\n", occ[num[i]]);
            if(occ[num[i]] == 1)
                hetero++;
            if(occ[num[i]] == 2)
                homo++;
        }else{
            if(occ[num[i]]){
                occ[num[i]]--;
                if(occ[num[i]] == 0)
                    hetero--;
                if(occ[num[i]] == 1)
                    homo--;
            }
        }
        //printf("%d %d\n", hetero, homo);
        if(hetero > 1 && homo)
            printf("both\n");
        else if(hetero > 1)
            printf("hetero\n");
        else if(homo)
            printf("homo\n");
        else printf("neither\n");
    }
    return 0;
}

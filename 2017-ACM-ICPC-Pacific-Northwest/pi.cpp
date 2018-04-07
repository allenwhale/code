#include <bits/stdc++.h>
using namespace std;
enum type {I, D};
typedef long long ll;
struct OP{
    type t;
    ll p;
    char c;
    bool operator == (const OP &x) const {
        return t == x.t && p == x.p && c == x.c;
    }
};
void clean(vector<OP> &ops){
    for(int i = 1 ; i < (int)ops.size() ; i++){
        for(int j = i ; j > 0 ; j--){
            if(ops[j - 1].t == I && ops[j].t == I){
                if(ops[j - 1].p >= ops[j].p){
                    swap(ops[j - 1], ops[j]);
                    ops[j].p++;
                }else{
                }
            } else if(ops[j - 1].t == D && ops[j].t == D){
                if(ops[j - 1].p <= ops[j].p){
                    swap(ops[j - 1], ops[j]);
                    ops[j - 1].p++;
                }else{
                }
            } else if(ops[j - 1].t == I && ops[j].t == D){
                if(ops[j - 1].p == ops[j].p){
                    ops.erase(ops.begin() + j - 1, ops.begin() + j + 1);
                    i -= 2;
                    break;
                }else if(ops[j - 1].p < ops[j].p){
                    swap(ops[j - 1], ops[j]);
                    ops[j - 1].p--;
                }else{
                    swap(ops[j - 1], ops[j]);
                    ops[j].p--;
                }
            } else if(ops[j - 1].t == D && ops[j].t == I){
            }
        }
    }
}
int main(){
    char in[1010];
    vector<OP> op[2];
    for(int i = 0 ; i < 2 ; i++){
        while(scanf("%s", in)){
            if(in[0] == 'E')break;
            if(in[0] == 'D'){
                ll p;
                scanf("%lld", &p);
                op[i].push_back({D, p, ' '});
            }else if(in[0] == 'I'){
                ll p;
                char x[5];
                scanf("%lld%s", &p, x);
                op[i].push_back({I, p, x[0]});
            }
        }
        clean(op[i]);
    }
    printf("%d\n", op[0] != op[1]);
    return 0;
}

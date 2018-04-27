#include <bits/stdc++.h>
using namespace std;

struct cmp{
    bool operator() (const pair<double, double> &a, const pair<double, double> &b) const {
        return a.first > b.first;
    }
};

int N, P, W[110], H[110];
double D[110];
void Solve(){
    scanf("%d%d", &N, &P);
    int total = 0;
    for(int i = 0 ; i < N ; i++){
        scanf("%d%d", &W[i], &H[i]);
        if(W[i] > H[i])
            swap(W[i], H[i]);
        total += 2 * (W[i] + H[i]);
        D[i] = sqrt(W[i] * W[i] + H[i] * H[i]);
    }
    P -= total;
    set<pair<double, double>, cmp> st;
    st.insert({W[0] * 2, D[0] * 2});
    for(int i = 1 ; i < N ; i++){
        vector<pair<double, double>> tmp;
        for(auto &r : st){
            tmp.push_back({r.first + W[i] * 2., r.second + D[i] * 2.});
        }
        for(auto &r : tmp){
            auto it = st.lower_bound({r.first, r.first});
            if(it != st.end() && it->first <= r.first && r.first <= it->second){
                r.first = min(it->first, r.first);
                r.second = max(it->second, r.second);
                st.erase(it);
            }
            it = st.lower_bound({r.second, r.second});
            if(it != st.end() && it->second <= r.second && r.second <= it->second){
                r.first = min(it->first, r.first);
                r.second = max(it->second, r.second);
                st.erase(it);
            }
            st.insert(r);
        }
    }
    auto it = st.lower_bound({P, P});
    if(it->first <= P && P <= it->second){
        printf("%d\n", P + total);
    }else if(it->first > P){
        printf("%d\n", total);
    }else{
        printf("%.10f\n", it->second + total);
    }

}

int main(){
    int T;
    scanf("%d", &T);
    for(int i = 1 ; i <= T ; i++){
        printf("Case #%d: ", i);
        Solve();
    }
    return 0;
}

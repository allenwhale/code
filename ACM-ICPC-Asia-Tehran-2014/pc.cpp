#include <bits/stdc++.h>
using namespace std;
    int T, P, S;
int team_ac[200];
bool team_ac_problem[200][20];
int problem_ac[200];
char in[2000];
struct Sub{
    int t, p, h, m, s;
    bool ac;
    Sub(){}
    Sub(int _t, int _p, int _h, int _m, int _s, bool _ac): t(_t), p(_p), h(_h), m(_m), s(_s), ac(_ac){}
    bool operator < (const Sub &n) const{
        if(h == n.h){
            if(m == n.m)
                return s< n.s;
            return m < n.m;
        }
        return h < n.h;
    }
};
bool ideal(){
    for(int i=1;i<=T;i++)
        if(team_ac[i] <= 0)
            return false;
    for(int i=1;i<=T;i++)
        if(team_ac[i] == P)
            return false;
    for(int i=0;i<P;i++)
        if(problem_ac[i] <= 0)
            return false;
    for(int i=0;i<P;i++)
        if(problem_ac[i] == T)
            return false;
    return true;
}
bool Solve(){
    scanf("%d%d%d%*c", &T, &P, &S);
    if(T == 0)return false;
    memset(team_ac, 0, sizeof(team_ac));
    memset(team_ac_problem, false, sizeof(team_ac_problem));
    memset(problem_ac, 0, sizeof(problem_ac));
    vector<Sub> subs;
    for(int i=0;i<S;i++){
        fgets(in, 200, stdin);
        int t, h, m, s;
        char p[10];
        char status[20];
        sscanf(in, "%d%s%d:%d:%d%s", &t, p, &h, &m, &s, status);
        subs.push_back(Sub(t, p[0]-'A', h, m, s, strcmp(status, "Yes") == 0));
    }
    sort(subs.begin(), subs.end());
    int sh = -1, sm, ss, eh = -1, em, es;
    bool is_ideal = false;
    for(auto sub: subs){
        if(sub.ac){
            if(team_ac_problem[sub.t][sub.p] == false){
                team_ac_problem[sub.t][sub.p] = true;
                team_ac[sub.t]++;
                problem_ac[sub.p]++;
                bool now_ideal = ideal();
                if(is_ideal == false && now_ideal == true){
                    sh = sub.h, sm = sub.m, ss = sub.s;
                    is_ideal = true;
                }else if(is_ideal == true && now_ideal == false){
                    eh = sub.h, em = sub.m, es = sub.s;
                    is_ideal = false;
                }
            }
        }
    }
    if(sh == -1){
        printf("--:--:--");
    }else{
        printf("%02d:%02d:%02d", sh, sm, ss);
    }
    printf(" ");
    if(eh == -1){
        printf("--:--:--");
    }else{
        printf("%02d:%02d:%02d", eh, em, es);
    }
    puts("");
    return true;
}
int main(){
    while(Solve());
    return 0;
}

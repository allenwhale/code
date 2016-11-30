#include <bits/stdc++.h>
using namespace std;
char in[10010][100];
vector<int>vc[10010];
void Solve(){
    int cnt = 1;
    while(fgets(in[cnt], 100, stdin)){
        if(in[cnt][0] == 'E')break;
        vc[cnt].clear();
        cnt++;
    }
    for(int i=1;i<cnt;i++){
        //printf("%d %s\n",i, in[i]);
        if(in[i][0] == 'l')continue;
        char *ptr = strstr(in[i], "line_");
        ptr += 5;
        int lineno = 0;
        while(isdigit(*ptr)){
            lineno = lineno * 10 + (*ptr) - '0';
            ++ptr;
        }
        vc[lineno].push_back(-lineno);
        vc[i].push_back(lineno);
        if(lineno >= i){
            printf("bad\n");
            return;
        }
    }
    vector<int> test;
    for(int i=1;i<cnt;i++)
        for(int x : vc[i])
            test.push_back(x);
    stack<int> stk;
    for(int x : test){
        if(x < 0)
            stk.push(-x);
        else{
            if(stk.size() == 0 || stk.top() != x){
                printf("bad\n");
                return ;
            }
            stk.pop();
        }
    }

    printf("good\n");
}
int main(){
    int T;
    scanf("%d%*c", &T);
    while(T--)
        Solve();
    return 0;
}

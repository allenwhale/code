#include <bits/stdc++.h>
using namespace std;

typedef array<int, 3> state;
void print(const state &a, const state &b){
    printf("(%d %d %d) (%d %d %d)\n", a[0], a[1], a[2], b[0], b[1], b[2]);
}

int main(){
    state s[2], e[2];
    for(int i = 0 ; i < 2 ; i++){
        for(int j = 0 ; j < 3 ; j++)
            scanf("%d", &s[i][j]);
        for(int j = 0 ; j < 3 ; j++)
            scanf("%d", &e[i][j]);
    }
    print(s[0], s[1]);
    int dir[2] = {0, 0};
    while(s[0] != e[0] || s[1] != e[1]){
        for(int i = 0 ; i < 2 ; i++){
            if(s[i] != e[i])
                while(s[i][dir[i]] == e[i][dir[i]])
                    dir[i] = (dir[i] + 1) % 3;
        }
        if(s[1] == e[1]){
            //puts("mode 1");
            state n = s[0];
            n[dir[0]] += e[0][dir[0]] > s[0][dir[0]] ? 1 : -1;
            if(n == e[1]){
                n[dir[0]] -= e[0][dir[0]] > s[0][dir[0]] ? 1 : -1;
                n[(dir[0] + 1) % 3] += 1;
            } 
            s[0] = n;
        }else if(s[0] == e[0]){
            //puts("mode 2");
            state n = s[1];
            n[dir[1]] += e[1][dir[1]] > s[1][dir[1]] ? 1 : -1;
            if(n == e[0]){
                n[dir[1]] -= e[1][dir[1]] > s[1][dir[1]] ? 1 : -1;
                n[(dir[1] + 1) % 3] += 1;
            } 
            s[1] = n;
        }else{
            //puts("mode 3");
            state n[2] = {s[0], s[1]};
            n[0][dir[0]] += e[0][dir[0]] > s[0][dir[0]] ? 1 : -1;
            n[1][dir[1]] += e[1][dir[1]] > s[1][dir[1]] ? 1 : -1;
            if(n[0] == n[1]){
                n[0][dir[0]] -= e[0][dir[0]] > s[0][dir[0]] ? 1 : -1;
            }else if(n[0] == s[1] && n[1] == s[0]){
                n[0][dir[0]] -= e[0][dir[0]] > s[0][dir[0]] ? 1 : -1;
                n[0][(dir[0] + 1) % 3] += 1;
                print(n[0], n[1]);
                n[0][dir[0]] += e[0][dir[0]] > s[0][dir[0]] ? 1 : -1;
                print(n[0], n[1]);
                n[0][(dir[0] + 1) % 3] -= 1;
            }
            s[0] = n[0], s[1] = n[1];
        }
        print(s[0], s[1]);
    }
    return 0;
}

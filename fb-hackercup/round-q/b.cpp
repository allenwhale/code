#include <bits/stdc++.h>
using namespace std;
char s[2][1010];
int Solve(){
    int N;
    scanf("%d", &N);
    scanf("%s", s[0] + 1);
    scanf("%s", s[1] + 1);
    s[0][0] = s[0][N + 1] = s[1][0] = s[1][N + 1] = 'X';
    for(int k=0;k<2;k++){
        int i = 1;
        int start, end;
        while(i <= N){
            if(s[k][i] == '.'){
                start = i;
                while(s[k][i] == '.') end = i++;
                for(int j=start;j<=end;j++){
                    if(s[k ^ 1][j] == '.' && s[k ^ 1][j - 1] == 'X' && s[k ^ 1][j + 1] == 'X'){
                        s[k ^ 1][j] = 'X';
                        break;
                    }
                }
            }else i++;
        }
    }
    int ans = 0;
    for(int k=0;k<2;k++){
        int i = 1;
        int start, end;
        while(i <= N){
            if(s[k][i] == '.'){
                start = i;
                while(s[k][i] == '.') end = i++;
                ans++;
            }else i++;
        }
    }
    return ans;
}
int main(){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++)
        printf("Case #%d: %d\n", t, Solve());
    return 0;
}

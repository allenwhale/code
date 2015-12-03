#include <bits/stdc++.h>
using namespace std;
char name[110][1010];
int mp[30][30];
int sz[110];
int deg[30];
bool vis[30];
int main(){
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++)
        scanf("%s", name[i]), sz[i] = strlen(name[i]);
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            int len = min(sz[i], sz[j]);
            for(int k=0;k<len;k++){
                if(name[i][k] != name[j][k]){
                    mp[name[i][k]-'a'][name[j][k]-'a'] = 1;
                    break;
                }else if(k == len-1){
                    if(sz[i] > sz[j]){
                        printf("Impossible\n");
                        return 0;
                    }
                }
            }
        }
    }
    for(int k=0;k<26;k++)
        for(int i=0;i<26;i++)
            for(int j=0;j<26;j++)
                mp[i][j] |= mp[i][k] & mp[k][j];
    for(int i=0;i<26;i++)
        if(mp[i][i]){
            printf("Impossible\n");
            return 0;
        }
    for(int i=0;i<26;i++)
        for(int j=0;j<26;j++)
            deg[j] += mp[i][j];
    for(int i=0;i<26;i++){
        int n;
        for(n=0;n<26;n++)
            if(deg[n] == 0 && vis[n] == false)
                break;
        printf("%c", n + 'a');
        vis[n] = true;
        for(int j=0;j<26;j++)
            if(mp[n][j] && vis[j] == false)
                deg[j]--;
    }
    puts("");
    return 0;
}

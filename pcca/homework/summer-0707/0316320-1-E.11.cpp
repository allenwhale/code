#include <bits/stdc++.h>
using namespace std;
char s[3][100010];
int cnt[4][30];
int calc(int cnt_1){
    for(int i=0;i<26;i++)
        cnt[4][i]=cnt[0][i];
    for(int i=0;i<26;i++){
        cnt[4][i]-=cnt[1][i]*cnt_1;
        if(cnt[4][i]<0)return -9999999;
    }
    int mx_b=9999999;
    for(int i=0;i<26;i++){
        if(cnt[2][i]!=0){
            mx_b=min(mx_b, cnt[4][i]/cnt[2][i]);
        }
    }
    return mx_b;
}
int main(){
    scanf("%s%s%s",s[0],s[1],s[2]);
    for(int i=0;i<3;i++){
        int len=strlen(s[i]);
        for(int j=0;j<len;j++)
            cnt[i][s[i][j]-'a']++;
    }
    int mx_1=strlen(s[0])/strlen(s[1]);
    int ans=0,cnt_a=0,cnt_b=0;
    for(int i=0;i<mx_1;i++){
        int mx_b=calc(i);
        if(ans<i+mx_b){
            ans=i+mx_b;
            cnt_a=i;
            cnt_b=mx_b;
        }
    }
    for(int i=0;i<cnt_a;i++){
        printf("%s",s[1]);
    }
    for(int i=0;i<cnt_b;i++){
        printf("%s",s[2]);
    }
    for(int i=0;i<26;i++){
        cnt[0][i]-=(cnt_a*cnt[1][i]+cnt_b*cnt[2][i]);
    }
    for(int i=0;i<26;i++){
        for(int j=0;j<cnt[0][i];j++)
            printf("%c",'a'+i);
    }
    puts("");
    return 0;
}

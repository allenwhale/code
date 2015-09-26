#include <bits/stdc++.h>
using namespace std;
int main(){
    char s[100010];
    scanf("%s",s);
    bool tf=false;
    int len=strlen(s);
    for(int i=0;i<len-1;i++){
        if(tf==false){
            if(s[i]=='A'&&s[i+1]=='B')
                tf=true,i++;
        }else{
            if(s[i]=='B'&&s[i+1]=='A'){
                printf("YES\n");
                return 0;
            }
        }
    }
    tf=false;
    for(int i=0;i<len-1;i++){
        if(tf==false){
            if(s[i]=='B'&&s[i+1]=='A')
                tf=true,i++;
        }else{
            if(s[i]=='A'&&s[i+1]=='B'){
                printf("YES\n");
                return 0;
            }
        }
    }
    puts("NO");
    return 0;
}

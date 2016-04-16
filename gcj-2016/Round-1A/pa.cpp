#include <bits/stdc++.h>
using namespace std;
char in[1010];
int main(){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        scanf("%s", in);
        deque<char> dq;
        dq.push_back(in[0]);
        int len = strlen(in);
        for(int i=1;i<len;i++){
            if(in[i] >= dq.front())
                dq.push_front(in[i]);
            else 
                dq.push_back(in[i]);
        }
        printf("Case #%d: ", t);
        for(int i=0;i<len;i++)
            printf("%c", dq[i]);
        puts("");
    }
    return 0;
}

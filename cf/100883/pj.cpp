#include <bits/stdc++.h>
using namespace std;
int prime[1000000], pn = 0;
int pal_prime[1000000], pal_pn = 0;
void make_prime(){
    prime[pn++] = 2;
    int l = 1 << 12;
    for(int i=3;i<=l;i+=2){
        bool tf = true;
        for(int j=0;j<pn;j++)
            if(i % prime[j] == 0){
                tf = false;
                break;
            }
        if(tf) prime[pn++] = i;
    }
}
int tmp[30];
bool is_pal(int n){
    int len = 0;
    while(n){
        tmp[len++] = n&1;
        n >>= 1;
    }
    for(int i=0;i<len;i++)
        if(tmp[i] != tmp[len - i - 1])
            return false;
    return true;
}
bool is_prime(int n){
    for(int i=0;i<pn&&prime[i]*prime[i]<=n;i++)
        if(n % prime[i] == 0)
            return false;
    return true;
}
void find_pal(){
    pal_prime[pal_pn++] = 2;
    for(int i=3;i<=(1<<22);i+=2){
        if(is_pal(i) && is_prime(i)){
            pal_prime[pal_pn++] = i;
        }
    }
}
char s[30];
void print(int n){
    vector<int> x;
    while(n){
        x.push_back(n&1);
        n >>= 1;
    }
    for(int i=x.size()-1;i>=0;i--)
        printf("%d", x[i]);
}
int main(){
    make_prime();
    find_pal();
    while(~scanf("%s", s)){
        int len = strlen(s);
        int N = 0;
        for(int i=0;i<len;i++)
            N = (N << 1) + (s[i] - '0');
        int ans = *upper_bound(pal_prime, pal_prime+pal_pn, N);
        print(ans);
        puts("");
    }
    return 0;
}

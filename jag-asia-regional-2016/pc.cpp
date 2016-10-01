#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
#define FRONT(n) ((size_t)((n)/5))
#define BACK(n) ((size_t)((n)-FRONT(n)))
struct S{
    int m, t, name;
    bool operator < (const S &n) const{
        if(m == n.m)
            return t < n.t;
        return m < n.m;
    }
    bool operator > (const S &n) const{
        if(m == n.m)
            return t > n.t;
        return m > n.m;
    }
    bool operator == (const S &n) const{
        return name == n.name;
    }
};
map<string, int> name2i;
map<int, string> i2name;
map<int, S> i2S;
int status[70020];
int sn = 0, t = 0;
int find(string str){
    if(name2i.find(str) == name2i.end()){
        name2i[str] = sn;
        i2name[sn++] = str;
    }
    return name2i[str];
}
struct cmp{
    bool operator () (const S &a, const S &b){
        return a > b;
    }
};
char in[100];
int main(){
    set<S, cmp> st[2];
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        int m;
        scanf("%s%d", in, &m);
        S s= S{m, t++, find(in)};
        status[s.name] = 0;
        i2S[s.name] = s;
        st[0].insert(s);
    }
    while(st[0].size() > FRONT(N)){
        auto end = --st[0].end();
        status[(*end).name] = 1;
        st[1].insert(*end);
        st[0].erase(end);
    }
    int M ;
    scanf("%d", &M);
    while(M--){
        scanf("%s", in);
        if(in[0] == '+'){
            N++;
            int m;
            scanf("%s%d", in, &m);
            S s = S{m, t++, find(in)}, c;
            i2S[s.name] = s;
            bool other = false;
            if(s > *st[1].begin()){
                st[0].insert(s);
                status[s.name] = 0;
                while(st[0].size() > FRONT(N)){
                    S o = *(--st[0].end());
                    if(!(o == s)){
                        c = o, other = true;
                    }
                    status[o.name] = 1;
                    st[0].erase(--st[0].end());
                    st[1].insert(o);
                }
            }else{
                st[1].insert(s);
                status[s.name] = 1;
                while(st[1].size() > BACK(N)){
                    S o = *st[1].begin();
                    if(!(o == s)){
                        c = o, other = true;
                    }
                    status[o.name] = 0;
                    st[1].erase(st[1].begin());
                    st[0].insert(o);
                }
            }
            if(status[s.name] == 0){
                printf("%s is working hard now.\n", i2name[s.name].c_str());
            }else{
                printf("%s is not working now.\n", i2name[s.name].c_str());
            }
            if(other){
                if(status[c.name] == 0){
                    printf("%s is working hard now.\n", i2name[c.name].c_str());
                }else{
                    printf("%s is not working now.\n", i2name[c.name].c_str());
                }
            }
        }else{
            N--;
            scanf("%s", in);
            int name = find(in);
            //printf("name %d\n", name);
            if(status[name] == 0){
                //puts("front");
                st[0].erase(st[0].find(i2S[name]));
                while(st[0].size() < FRONT(N)){
                    S s = *st[1].begin();
                    st[0].insert(s);
                    st[1].erase(st[1].begin());
                    status[s.name] = 0;
                    if(status[s.name] == 0){
                        printf("%s is working hard now.\n", i2name[s.name].c_str());
                    }else{
                        printf("%s is not working now.\n", i2name[s.name].c_str());
                    }
                }
            }else{
                //puts("back");
                //printf("   %d\n", i2S[name].name);
                //for(auto x:st[1])
                    //printf("   %d %d %d\n", x.m, x.t, x.name);
                //printf("%d\n", st[1].end() == st[1].find(i2S[name]));
                st[1].erase(st[1].find(i2S[name]));
                //puts("done");
                while(st[1].size() < BACK(N)){
                    S s = *(--st[0].end());
                    st[1].insert(s);
                    st[0].erase(--st[0].end());
                    status[s.name] = 1;
                    if(status[s.name] == 0){
                        printf("%s is working hard now.\n", i2name[s.name].c_str());
                    }else{
                        printf("%s is not working now.\n", i2name[s.name].c_str());
                    }
                }
            }
        }
    }
}

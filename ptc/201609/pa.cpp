#include <bits/stdc++.h>
using namespace std;
char s[40010][300];
int cnt = 0;
vector<int> desc;
map<int, int> refer;
map<int, int> new_ref;
int get_ref_num(char *ptr){
    int res = 0;
    while(isdigit(*ptr)){
        res = res * 10 + (*ptr - '0');
        ptr++;
    }
    return res;
}
void output_desc(int x){
    char *ptr = s[x];
    while(*ptr){
        if(*ptr == '['){
            putchar('[');
            int old = get_ref_num(ptr + 1);
            int n = new_ref[get_ref_num(ptr + 1)];
            printf("%d", n);
            ptr += 1 + to_string(old).size();
        }else{
            putchar(*ptr);
            ptr++;
        }
    }
}
void output_ref(int x){
    char *ptr = s[x];
    while(*ptr){
        if(*ptr == '['){
            putchar('[');
            int old = get_ref_num(ptr + 1);
            int n = new_ref[get_ref_num(ptr + 1)];
            printf("%d", n);
            ptr += 1 + to_string(old).size();
        }else{
            putchar(*ptr);
            ptr++;
        }
    }
}
bool is_ref(int x){
    if(s[x][0] != '[')return false;
    char *ptr = s[x] + 1;
    while(*ptr){
        if(*ptr == ']')break;
        ptr++;
    }
    char *ss = s[x] + 1;
    while(ss != ptr){
        if(isdigit(*ss) == false)
            return false;
        ss++;
    }
    if(ptr - ss > 3)return false;
    return true;
}
int main(){
    while(gets(s[cnt]) != NULL){
        int len = strlen(s[cnt]);
        if(len == 0)continue;
        cnt++;
    }
    //puts("in");
    for(int i=0;i<cnt;i++){
        if(is_ref(i)){
            int refn = get_ref_num(s[i] + 1);
            refer[refn] = i;
        }else{
            desc.push_back(i);
        }
    }
    int sn = 1;
    for(int x:desc){
        char *ptr = s[x];
        while(*ptr){
            if(*ptr == '['){
                int n = get_ref_num(ptr + 1);
                if(new_ref.find(n) == new_ref.end())
                    new_ref[n] = sn++;
                ptr += 1 + to_string(n).size();
            }else{
                ptr++;
            }
        }
    }
    for(int x:desc){
        output_desc(x);
        puts("\n");
    }
    map<int, int> yy;
    for(auto x:new_ref){
        yy[x.second] = refer[x.first];
    }
    for(auto it=yy.begin();it!=yy.end();++it){
        auto tmp = it;
        auto x = *it;
        output_ref(x.second);
        if(++tmp != yy.end())
            puts("");
        puts("");
    }
    return 0;
}

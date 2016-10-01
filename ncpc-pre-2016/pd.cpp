#include <bits/stdc++.h>
using namespace std;
char in[1000];

int main(){
    while(fgets(in, 1000, stdin) && !(in[0] == '0')){
        vector<int> vc;
        vc.push_back(-1);
        char *ptr = strtok(in, " ");
        while(ptr){
            int x;
            sscanf(ptr, "%d", &x);
            vc.push_back(x);
            ptr = strtok(NULL, " ");
        }
        bool tf = true;
        for(int i=1;i<(int)vc.size();i++){
            int l = i * 2;
            if(l < (int)vc.size() && vc[l] > vc[i]){
                //printf("1 %d\n", i);
                tf = false;
            }
            int r = l + 1;
            if(r < (int)vc.size() && vc[r] > vc[i]){
                //printf("2 %d\n", i);
                tf = false;
            }
            //if(r < (int)vc.size() && l < (int)vc.size() && vc[r] > vc[l]){
                //printf("%d %d\n", vc[r], vc[l]);
                //printf("3 %d\n", i);
                //tf =false;
            //}
        }
        if(tf)puts("1");
        else puts("0");
    }
}

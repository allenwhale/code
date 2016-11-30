#include <bits/stdc++.h>
using namespace std;
vector<int> get_input(){
    string buffer;
    getline(cin, buffer);
    stringstream ss(buffer);
    vector<int> vec;
    int n;
    while(ss >> n)
        vec.push_back(n);
    return vec;
}
bool get(int x, int y){
    if(y < 0){
        return ((x >> (-y - 1)) & 1) ^ 1;
    }else{
        return (x >> (y - 1)) & 1;
    }
}

void Solve(){
    auto x = get_input();
    int n = x[0], m = x[1];
    vector<int> y[128];
    for(int i = 0 ; i < m ; i++){
        y[i] = get_input();
    }
    for(int i = 0 ; i < m ; i++){
        if(y[i][0] == 0 || y[i][1] == 0 || y[i][2] == 0){
            cout << "INVALID: NULL RING" << endl;
            return;
        }
        y[i].pop_back();
    }
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < (int)y[i].size() ; j++){
            if(y[i][j] < -n || y[i][j] > n){
                cout << "INVALID: RING MISSING" << endl;
                return;
            }
        }
    }
    for(int i = 0 ; i < m ; i++){
        set<int> s;
        for(int j = 0 ; j < (int)y[i].size() ; j++){
            if(s.count(abs(y[i][j])) == 1){
                cout << "INVALID: RUNE CONTAINS A REPEATED RING" << endl;
                return;
            }
            s.insert(abs(y[i][j]));
        }
    }
    bool ans = false;
    for(int i=0;i<(1<<n)&&!ans;i++){
        bool tf = true;
        for(int j=0;j<m&&tf;j++){
            if(!(get(i, y[j][0]) || get(i, y[j][1]) || get(i, y[j][2]))){
                tf = false;
            }
        }
        if(tf){
            ans = true;
        }
    }
    if(ans) cout << "RUNES SATISFIED!" << endl;
    else cout << "RUNES UNSATISFIABLE! TRY ANOTHER GATE!" << endl;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    auto x = get_input();
    while(x[0]--)
        Solve();
    return 0;
}

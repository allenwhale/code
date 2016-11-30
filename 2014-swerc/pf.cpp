#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Rec{
    ll x1, y1, x2, y2;
    bool intersect(const Rec &n){
        if(x1 == n.x2 && (y2 - y1) + (n.y2 - n.y1) - (max(y2, n.y2) - min(y1, n.y1)) >= 0)
            return true;
        if(x2 == n.x1 && (y2 - y1) + (n.y2 - n.y1) - (max(y2, n.y2) - min(y1, n.y1)) >= 0)
            return true;
        if(y2 == n.y1 && (x2 - x1) + (n.x2 - n.x1) - (max(x2, n.x2) - min(x1, n.x1)) >= 0)
            return true;
        if(y1 == n.y2 && (x2 - x1) + (n.x2 - n.x1) - (max(x2, n.x2) - min(x1, n.x1)) >= 0)
            return true;
        return false;
    }
    ll area(){
        return (x2 - x1) * (y2 - y1);
    }
}r[50010];
int p[50010];
ll a[50010];
unordered_map<int, unordered_set<int>> mp;
int find(int x){
    return x == p[x] ? x : p[x] = find(p[x]);
}
void merge(int a, int b){
    p[find(a)] = find(b);
}
int main(){
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        int x, y, w, h;
        scanf("%d%d%d%d", &x, &y, &w, &h);
        r[i] = {(ll)x, (ll)y, (ll)x + w, (ll)y + h};
    }
    for(int i=0;i<N;i++)
        p[i] = i;
    for(int i=0;i<N;i++){
        mp[r[i].x1].insert(i);
        mp[r[i].x2].insert(i);
    }
    for(auto item : mp){
        //printf("x: %d\n", item.first);
        vector<pair<ll, int>> work;
        for(auto i : item.second){
            //printf("%d ", i);
            work.push_back({r[i].y1, i});
            work.push_back({r[i].y2, i});
        }
        //puts("");
        sort(work.begin(), work.end());
        for(auto i : item.second){
            auto it = lower_bound(work.begin(), work.end(), make_pair(r[i].y1, -1));
            auto it_end = upper_bound(work.begin(), work.end(), make_pair(r[i].y2, INT_MAX));
            while(it != it_end){
                //printf("m %d %d\n", i, it->second);
                //if(r[i].intersect(r[it->second]))
                    merge(i, it->second);
                ++it;
            }
        }
    }
    mp.clear();
    for(int i=0;i<N;i++){
        mp[r[i].y1].insert(i);
        mp[r[i].y2].insert(i);
    }
    for(auto item : mp){
        vector<pair<ll, int>> work;
        for(auto i : item.second){
            work.push_back({r[i].x1, i});
            work.push_back({r[i].x2, i});
        }
        sort(work.begin(), work.end());
        for(auto i : item.second){
            auto it = lower_bound(work.begin(), work.end(), make_pair(r[i].x1, -1));
            auto it_end = upper_bound(work.begin(), work.end(), make_pair(r[i].x2, INT_MAX));
            while(it != it_end){
                //if(r[i].intersect(r[it->second]))
                    merge(i, it->second);
                ++it;
            }
        }
    }
    memset(a, 0, sizeof(a));
    for(int i=0;i<N;i++){
        //printf("%d %d\n", i, find(i));
        a[find(i)] += r[i].area();
    }
    ll ans = 0;
    for(int i=0;i<N;i++)
        ans = max(ans, a[i]);
    cout << ans << endl;
    return 0;
}

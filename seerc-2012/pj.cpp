#include <bits/stdc++.h>
using namespace std;
char in[1000010];
typedef pair<int, int> PII;
unordered_map<string, int> mp;
int find(const char *s){
    if(mp.find(s) == mp.end()){
        int res = mp.size() + 1;
        mp[s] = res;
    }
    return mp[s];
}
unordered_map<int, int> combine;
int dis[1010];
bool inq[1010];
int main(){
    //freopen("J.IN", "r", stdin);
    while(fgets(in, 1010, stdin)){
        in[strlen(in) - 1] = 0;
        char *ptr = strtok(in, " \r\n");
        vector<int> tmp;
        while(ptr){
            tmp.push_back(find(ptr));
            ptr = strtok(NULL, " \r\n");
        }
        if(tmp.size() != 3)break;
        combine[tmp[0] * 1013 + tmp[1]] = tmp[2];
        combine[tmp[1] * 1013 + tmp[0]] = tmp[2];
    }
    while(fgets(in, 1000010, stdin)){
        memset(dis, 0x3f ,sizeof(dis));
        memset(inq, 0, sizeof(inq));
        in[strlen(in) - 1] = 0;
        char *ptr = strtok(in, " \n\r");
        unordered_set<int> exist;
        while(ptr){
            exist.insert(find(ptr));
            dis[find(ptr)] = 0;
            ptr = strtok(NULL, " \r\n");
        }
        fgets(in, 1000010, stdin);
        vector<int> want;
        in[strlen(in) - 1] = 0;
        ptr = strtok(in, " \r\n");
        while(ptr){
            want.push_back(find(ptr));
            ptr = strtok(NULL, " \r\n");
        }
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        //queue<int> q;
        for(int x : exist){
            pq.push({0, x});
            //q.push(x);
            inq[x] = true;
        }
        while(!pq.empty()){
            auto now = pq.top();
            pq.pop();
            if(now.first != dis[now.second])continue;
            //int now = q.front();
            //q.pop();
            //inq[now] = false;
            vector<int> n;
            for(int x : exist){
                if(combine.find(now.second * 1013 + x) != combine.end()){
                    int to = combine[now.second * 1013 + x];
                    if(exist.find(to) == exist.end())
                        n.push_back(to);
                    //exist.insert(combine[now * 1013 + x]);
                    if(dis[to] > dis[x] + dis[now.second] + 1){
                        dis[to] = dis[x] + dis[now.second] + 1;
                        //printf("%d %d %d %d\n", to, x, now.second, dis[to]);
                        pq.push({dis[to], to});
                        //q.push(to);
                    }
                }
            }
            for(int x : n)
                exist.insert(x);
            //if(n.size())q.push(now), inq[now] = true;
        }
        for(int i = 0 ; i < (int)want.size() ; i++){
            int x = want[i];
            if(dis[x] != 0x3f3f3f3f)
                printf("%d", dis[x]);
            else printf("-1");
            printf(" ");
        }
        printf("\n");

    }
    return 0;
}

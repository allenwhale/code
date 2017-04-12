#include <bits/stdc++.h>
using namespace std;

struct MCMF{
    struct Edge {
        int v1, v2, w, f, c;
    };
    int N;
    vector<Edge> E;
    vector<vector<int>> ed;
    vector<int> dist;
    vector<int> prev;
    vector<bool> inq;
    MCMF(int n=0): N(n), ed(N), dist(N), prev(N), inq(N) {}
    void add_edge(int a, int b, int w, int c){
        ed[a].push_back(E.size());
        E.push_back({a, b, w, c, c});
        ed[b].push_back(E.size());
        E.push_back({b, a, -w, 0, c});
    }
    bool Bfs(int s, int t){
        fill(dist.begin(), dist.end(), 0x3f3f3f3f);
        fill(prev.begin(), prev.end(), -1);
        fill(inq.begin(), inq.end(), false);
        queue<int> q;
        dist[s] = 0;
        inq[s] = true;
        q.push(s);
        while(!q.empty()){
            int now = q.front();
            q.pop();
            inq[now] = false;
            for(int i=0;i<(int)ed[now].size();i++){
                const Edge &e = E[ed[now][i]];
                if(e.f > 0 && dist[e.v2] > dist[e.v1] + e.w){
                    dist[e.v2] = dist[e.v1] + e.w;
                    prev[e.v2] = ed[now][i];
                    if(!inq[e.v2]){
                        q.push(e.v2);
                        inq[e.v2] = true;
                    }
                }
            }
        }
        return dist[t] != 0x3f3f3f3f;
    }
    pair<int, int> Solve(int s, int t){
        pair<int, int> res = {0, 0};
        while(Bfs(s, t)){
            int now = t;
            int f = INT_MAX, c = 0;
            while(now != s){
                f = min(f, E[prev[now]].f);
                c += E[prev[now]].w;
                now = E[prev[now]].v1;
            }
            now = t;
            while(now != s){
                E[prev[now]].f -= f;
                E[prev[now] ^ 1].f += f;
                now = E[prev[now]].v1;
            }
            res.first += f;
            res.second += f * c;
        }
        return res;
    }
};

struct AC{
    struct Node{
        Node *ch[26], *fail;
        vector<int> indexes;
        Node(){
            memset(ch, 0, sizeof(ch));
            fail = NULL;
        }
    };
    Node *root;
    AC(){
        root = new Node();
    }
    void Insert(const string &s, int index){
        Node *tr = root;
        for(char c : s){
            if(!tr->ch[c - 'a']){
                tr->ch[c - 'a'] = new Node();
            }
            tr = tr->ch[c - 'a'];
        }
        tr->indexes.push_back(index);
    }
    void Build(){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node *now = q.front();
            q.pop();
            for(int i=0;i<26;i++){
                if(now->ch[i]){
                    Node *ptr = now->fail;
                    while(ptr && !ptr->ch[i])
                        ptr = ptr->fail;
                    if(!ptr)now->ch[i]->fail = root;
                    else now->ch[i]->fail = ptr->ch[i];
                    q.push(now->ch[i]);
                }
            }
        }
    }
    vector<pair<int, int>> Match(const string &s){
        vector<pair<int, int>> res;
        Node *tr = root;
        for(int i=0;i<(int)s.size();i++){
            char c = s[i];
            while(tr && !tr->ch[c - 'a'])
                tr = tr->fail;
            if(tr)tr = tr->ch[c - 'a'];
            else tr = root;
            Node *ptr = tr;
            while(ptr){
                for(int index : ptr->indexes)
                    res.push_back({index, i});
                ptr = ptr->fail;
            }
        }
        return res;
    }
};

char s[510];
char p[110][510], len[110];
int w[110];

int main(){
    int N, M, X;
    scanf("%d", &N);
    scanf("%s", s);
    scanf("%d", &M);
    AC ac;
    for(int i=0;i<M;i++){
        scanf("%s%d", p[i], &w[i]);
        len[i] = strlen(p[i]);
        ac.Insert(p[i], i);
    }
    ac.Build();
    auto res = ac.Match(s);
    scanf("%d", &X);
    MCMF mcmf(N + 3);
    int source = N + 1, target = source + 1;
    for(int i=0;i<N;i++)
        mcmf.add_edge(i, i + 1, 0, X);
    mcmf.add_edge(source, 0, 0, X);
    mcmf.add_edge(N, target, 0, X);
    for(auto m : res){
        mcmf.add_edge(m.second - len[m.first] + 1, m.second + 1, -w[m.first], 1);
    }
    auto ans = mcmf.Solve(source, target);
    printf("%d\n", -ans.second);

    return 0;
}

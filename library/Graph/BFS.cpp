#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

#define rep(i, n) for (int i = 1; i < (int) (n); i++)
template<class T> void print(const T& t){ cout << t << "\n"; }

vector<int> BFS(const Graph &G, int s) {
    int n = (int)G.size();
    vector<int> dist(n, -1);
    queue<int> que;

    dist[0] = 0;
    que.push(0);

    while(!que.empty()) {
        int v = que.front();
        que.pop();
        for (auto nv : G[v]) {
            if (dist[nv] != -1) continue;
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }
    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;

    Graph G(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> dist = BFS(G, 0);
    rep(i, n) print(dist[i]);
}
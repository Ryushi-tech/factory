#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

#define rep(i, n) for (int i = 0; i < (int) (n); i++)
template<class T> void print(const T& t){ cout << t << "\n"; }

vector<int> depth;
vector<int> subtree_size;

void dfs(const Graph &G, int v, int p = -1, int d = 0) {
    depth[v] = d;
    subtree_size[v] = 1;
    for (auto nv : G[v]) {
        if (nv == p) continue;
        dfs(G, nv, v, d + 1);
        subtree_size[v] += subtree_size[nv];
    }
}

int main() {
    int n, m; cin >> n >> m;

    Graph G(n);
    rep(i, m) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int root = 0;
    depth.assign(n, 0);
    subtree_size.assign(n, 0);
    dfs(G, root);
    rep(i, n) cout << depth[i] << " " << subtree_size[i] << "\n";
}
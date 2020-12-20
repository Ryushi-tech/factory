#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define rng(x) x.begin(), x.end()
#define pq(T) priority_queue<T, vector<T>, greater<T>>
template<class T> void print(const T& t){ cout << t << "\n"; }
const ll INF = 1LL << 60;

struct range_edge_graph {
    int n;
    struct edge { int to; ll weight;};
    vector<vector<edge>> g;

    range_edge_graph(int n) : n(n) {
        g.resize(3*n);
        rep(i, n) {
            int cl = i<<1|0, cr = i<<1|1;
            add_edge(i, cl, 0);
            add_edge(i, cr, 0);
            add_edge(cl + 2*n, i + 2*n, 0);
            add_edge(cr + 2*n, i + 2*n, 0);
        }
    }

    void add_edge(int u, int v, ll w) {
        if (3*n <= u) u -= 2*n;
        g[u].push_back({v, w});
    }

    void add_edge(int l1, int r1, int l2, int r2, ll w) {
        int idx = g.size();
        for (l1 += n, r1 += n; l1 < r1; l1 >>= 1, r1 >>= 1) {
            if (l1 & 1) add_edge(l1 + 2*n, idx, 0), l1++;
            if (r1 & 1) --r1, add_edge(r1 + 2*n, idx, 0);
        }
        vector<edge> node;
        for (l2 += n, r2 += n; l2 < r2; l2 >>= 1, r2 >>= 1) {
            if (l2 & 1) node.push_back({l2++, w});
            if (r2 & 1) node.push_back({--r2, w});
        }
        g.push_back(node);
    }

    vl dijkstra(int s) {
        s += n;
        vl dist(g.size(), INF);
        dist[s] = 0;
        using P = pair<ll, ll>;
        pq(P) que;
        que.emplace(0, s);
        while (!que.empty()) {
            P p = que.top();
            que.pop();
            int v = p.second;
            if (dist[v] < p.first) continue;
            for (edge& e : g[v]) {
                if (dist[e.to] > dist[v] + e.weight) {
                    dist[e.to] = dist[v] + e.weight;
                    que.emplace(dist[e.to], e.to);
                }
            }
        }
        vl res(dist.begin() + n, dist.begin() + 2*n);
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    range_edge_graph g(n);

    rep(i, m) {
        int l, r, c;
        cin >> l >> r >> c;
        l--; r--;
        g.add_edge(l, r + 1, l, r + 1, c);
    }
    auto dist = g.dijkstra(0);
    ll ans = dist[n - 1];
    print(ans != INF ? ans : -1);
}
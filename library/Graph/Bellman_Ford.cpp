#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
typedef long long int ll;
typedef vector<ll> vl;
template<class T> void print(const T& t){ cout << t << "\n"; }

const ll INF = 1LL << 60;
struct Edge {
    int to; ll w;
    Edge(int to, ll w) : to(to), w(w) {}
};
using Graph = vector<vector<Edge>>;
template<class T> bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    else return false;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, s;
    cin >> n >> m >> s;
    Graph G(m);
    rep(i, m) {
        int a, b, w;
        cin >> a >> b >> w;
        G[a].push_back(Edge(b, w));
    }

    bool exist_negative_cycle = false;
    vl dist(n, INF);
    dist[s] = 0;
    rep(i, n) {
        bool update = false;
        rep(v, n) {
            if (dist[v] == INF) continue;
            for (auto e: G[v]) {
                if (chmin(dist[e.to], dist[v] + e.w)) { update = true; }
            }
        }
        if (!update) break;
        if (i == n - 1) exist_negative_cycle = true;
    }

    if (exist_negative_cycle) { print("Negative cycle exist!"); }
    else rep(v, n) print(dist[v] < INF ? dist[v] : -1);
}

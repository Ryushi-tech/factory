#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using pp = pair<ll, int>;
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define PQ(T) priority_queue<T,vector<T>,greater<T>>
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

    vl dist(n, INF);
    dist[s] = 0;

    PQ(pp) que;
    que.push(make_pair(dist[s], s));

    while (!que.empty()) {
        int v = que.top().second;
        ll d = que.top().first;
        que.pop();

        if (d > dist[v]) continue;
        for (auto e: G[v]) {
            if (chmin(dist[e.to], dist[v] + e.w)) {
                que.push(make_pair(dist[e.to], e.to));
            }
        }
    }

    rep(v, n) print(dist[v] < INF ? dist[v] : -1);
}

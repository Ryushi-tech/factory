#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vp = vector<pair<int, int>>;
using vvp = vector<vp>;
using vvi = vector<vi>;
#define rep(i, a, b) for (int i = a; i < (int) (b); i++)
#define rrep(i, a, b) for (int i = a; i >= (int) (b); i--)
#define fore(i_in, a) for (auto& i_in: a)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pq(T) priority_queue<T, vector<T>, greater<T>>
template<class T> void chmin(T &a, T b) { if (a > b) a = b; }
//template<class T> bool chmin(T& a, T b) {if (a > b) {a = b;return true;} else return false;}
template<class T> void chmax(T &a, T b) { if (a < b) a = b; }
//template<class T> bool chmax(T& a, T b) {if (a < b) {a = b;return true;} else return false;}
template<class T> void print(const T &t) { cout << t << "\n"; }

const ll INF = 1LL << 60;
struct Edge {
    int to; ll w;
    Edge(int to, ll w) : to(to), w(w) {}
};
using Graph = vector<vector<Edge>>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    Graph G(n+1);
    rep(i, 0, m) {
            int a, b;
            cin >> a >> b;
            G[a].push_back(Edge(b, 1));
    }

    vl dist(n+1, INF);
    int s = 1;
    dist[s] = 0;

    using pp = pair<ll, int>;
    pq(pp) que;
    que.push({dist[s], s});

    while (!que.empty()) {
        int v = que.top().second;
        ll d = que.top().first;
        que.pop();

        if (d > dist[v]) continue;
        for (auto e: G[v]) {
            if (chmin(dist[e.to], dist[v] + e.w)) {
                que.push({dist[e.to], e.to});
            }
        }
    }
    print(dist[n] <= 2 ? "POSSIBLE": "IMPOSSIBLE");
}

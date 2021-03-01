#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep1(i,n) for(int i=(n);i>0;i--)
#define fore(i_in,a) for (auto& i_in: a)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fio() cin.tie(nullptr);ios::sync_with_stdio(false);
#define DEBUG_CTN(v) cerr<<#v<<":";for(auto itr=v.begin();itr!=v.end();itr++) cerr<<" "<<*itr; cerr<<endl
template<class T> bool chmax(T &a, const T &b) {if (a<b) { a = b; return true; } return 0;}
template<class T> bool chmin(T &a, const T &b) {if (a>b) { a = b; return true; } return 0;}
template<class T> void print(const T &t) { cout << t << "\n"; }
const ll INF = 1LL << 60;

#define pq(T) priority_queue<T, vector<T>, greater<T>>
struct Edge {ll to; ll w; Edge(ll to, ll w) : to(to), w(w) {}};
using Graph = vector<vector<Edge>>;

vl dijkstra(Graph &G, int s){
    int n = G.size();
    vl dist(n, INF);
    dist[s] = 0;

    using pp = pair<ll, ll>;
    pq(pp) que;
    que.push({dist[s], s});

    while (!que.empty()) {
        ll v = que.top().second;
        ll d = que.top().first;
        que.pop();

        if (d > dist[v]) continue;
        if(!G[v].empty()) fore(e, G[v]) {
            if (chmin(dist[e.to], dist[v] + e.w)) {
                que.push({dist[e.to], e.to});
            }
        }
    }
    return dist;
}

int main() {
    fio(); ll n,m; cin>>n>>m;
    Graph G(n),H(n);
    rep(i,m) {
        ll a,b,w; cin>>a>>b>>w;
        a--;b--;
        G[a].push_back(Edge(b, w));
        H[b].push_back(Edge(a, w));
    }

    rep(s, n) {
        vl dist = dijkstra(G, s);
        ll ans = INF;
        if(!H[s].empty()) fore(e, H[s]) chmin(ans, dist[e.to] + e.w);
        print(ans != INF ? ans: -1);
    }
}

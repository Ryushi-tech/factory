#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pl = pair<ll, ll>;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep1(i,n) for(int i=(n);i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define fore(i_in,a) for (auto& i_in: a)
#define forp(x,y,a) for(auto& [x, y]: a)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pq(T) priority_queue<T, vector<T>, greater<T>>
#define fio() cin.tie(nullptr);ios::sync_with_stdio(false);
#define ofst_FLR(a, b) (a-1)/b;
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<(int)v.size();i++) cerr<<" "<<v[i]; cerr<<endl
#define UNIQUE(v) v.erase(unique(all(v)), v.end());
template<class T> bool chmax(T &a, const T &b) {if (a<b) { a = b; return true; } return 0;}
template<class T> bool chmin(T &a, const T &b) {if (a>b) { a = b; return true; } return 0;}
template<class T> void print(const T &t) { cout << t << "\n"; }

const ll INF = 1LL << 60;
struct Edge {ll to; ll w; Edge(ll to, ll w) : to(to), w(w) {}};
using Graph = vector<vector<Edge>>;

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
            ll ans = INF;
            if(!H[s].empty()) fore(e, H[s]) chmin(ans, dist[e.to] + e.w);
            print(ans != INF ? ans: -1);
    }
}

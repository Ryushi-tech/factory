#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep1(i,n) for(int i=(n);i>0;i--)
#define fore(i_in,a) for (auto& i_in: a)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fio() cin.tie(nullptr);ios::sync_with_stdio(false);
#define DEBUG_CTN(v) cerr<<#v<<":";for(auto itr=v.begin();itr!=v.end();itr++) cerr<<" "<<*itr; cerr<<endl
template<class T> bool chmax(T &a, const T &b) {if (a<b) { a = b; return true; } return false;}
template<class T> bool chmin(T &a, const T &b) {if (a>b) { a = b; return true; } return false;}
template<class T> void print(const T &t) { cout << t << "\n"; }
const ll INF = 1LL << 62;
const int iINF = 1 << 30;

#define pq(T) priority_queue<T, vector<T>, greater<T>>
struct Edge {ll to; ll w; Edge(ll to, ll w) : to(to), w(w) {}};
using Graph = vector<vector<Edge>>;

int n,m,u,v;
ll S,smax=3000;
vl A(101),B(101),C(50),D(50),ans(50,INF);
vector<vl> dist(50,vl(3010,INF));

int mask=5010;
ll encode(ll a,ll b) {return mask*a+b;}
pair<ll,ll> decode(ll c){return {c/mask,c%mask};}

void dijkstra(Graph &G){
    dist[0][S] = 0;

    using pp = pair<ll,ll>;
    pq(pp) que;
    que.push({0,S});

    while (!que.empty()) {
        ll V = que.top().second;
        ll t = que.top().first;
        auto [v,s] = decode(V);
        que.pop();

        if (t>dist[v][s]) continue;
        chmin(ans[v],t);
        fore(e, G[v]) {
            if(s<A[e.w]) continue;
            ll nt=t+B[e.w];
            ll ns=s-A[e.w];
            if (chmin(dist[e.to][ns],nt)) que.push({dist[e.to][ns], encode(e.to,ns)});
        }
        ll nt=t+D[v];
        ll ns=min(smax,s+C[v]);
        if(chmin(dist[v][ns],nt)) que.push({dist[v][ns], encode(v,ns)});
    }
}

int main() {
    fio(); cin>>n>>m>>S;
    chmin(S,smax);
    Graph G(n);
    rep(i,m) {
        cin>>u>>v>>A[i]>>B[i]; u--; v--;
        G[u].emplace_back(v,i);
        G[v].emplace_back(u,i);
    }
    rep(i,n) cin>>C[i]>>D[i];
    dijkstra(G);
    rep1(i,n-1) print(ans[i]);
}
//two currencies
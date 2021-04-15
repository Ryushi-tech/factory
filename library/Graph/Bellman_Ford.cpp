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
template<class T> bool chmax(T &a, const T &b) {if (a<b) { a = b; return true; } return 0;}
template<class T> bool chmin(T &a, const T &b) {if (a>b) { a = b; return true; } return 0;}
template<class T> void print(const T &t) { cout << t << "\n"; }
const ll INF = 1LL << 62;
const int iINF = 1 << 30;

struct Edge {ll to; ll w; Edge(ll to, ll w) : to(to), w(w) {}};
using Graph = vector<vector<Edge>>;

int n,m,p;

int main() {
    fio(); cin>>n>>m>>p;
    Graph G(n); int res=0;
    rep(i,m) {
        int a,b,w; cin>>a>>b>>w;a--;b--;
        int tmp = max(w-p,0);
        G[a].push_back(Edge(b,-tmp));
        res+=tmp;
    }
    bool exist_negative_cycle = false;
    vl dist(n,INF);
    dist[0] = 0;
    rep(i,n) {
        bool update = false;
        rep(v,n) {
            if (dist[v]==INF) continue;
            fore(e,G[v]) if (chmin(dist[e.to], dist[v] + e.w)) update = true;
        }
        if (!update) break;
        if (i==n-1) exist_negative_cycle = true;
    }

    if (exist_negative_cycle and -dist[n-1]>res) { print(-1); }
    else print(dist[n-1] < INF ? -dist[n-1] : -1);
}
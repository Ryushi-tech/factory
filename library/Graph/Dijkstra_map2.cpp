#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vi = vector<int>;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep1(i,n) for(int i=(n);i>0;i--)
#define fore(i_in,a) for (auto& i_in: a)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define cnts(x,c) count(all(x),c)
#define fio() cin.tie(nullptr);ios::sync_with_stdio(false);cout<<fixed<<setprecision(12);
#define DEBUG_CTN(v) cerr<<#v<<":";for(auto itr=v.begin();itr!=v.end();itr++) cerr<<" "<<*itr; cerr<<endl
template<class T> bool chmax(T &a, const T &b) {if (a<b) {a = b; return true;} return false;}
template<class T> bool chmin(T &a, const T &b) {if (a>b) {a = b; return true;} return false;}
template<class T> void print(const T &t) {cout<<t<<"\n";}
template<class T> void PRINT(const T &t) {rep(i,sz(t)) cout<<t[i]<<" \n"[i==sz(t)-1];}
const ll INF = 1LL << 62;
const int iINF = 1 << 30;

#define pq(T) priority_queue<T, vector<T>, greater<T>>
struct Edge {ll to; ll w; Edge(ll to, ll w) : to(to), w(w) {}};
using Graph = vector<vector<Edge>>;

vl dijkstra(Graph &G,int s,int k){
    map<ll,ll> dist;
    vl stk;
    dist[s]=0;
    stk.emplace_back(s);

    using pp=pair<ll,ll>;
    pq(pp) que;
    que.push({dist[s],s});

    while (!que.empty()) {
        ll v=que.top().second;
        ll d=que.top().first;
        que.pop();
        if (d>dist[v]) continue;
        if(!G[v].empty()) fore(e,G[v]) {
            if (!dist.count(e.to) and dist[v]<k) {
                dist[e.to]=dist[v]+e.w;
                stk.emplace_back(e.to);
                que.push({dist[e.to], e.to});
            }
            else if (dist[v]<k and chmin(dist[e.to], dist[v]+e.w)) {
                stk.emplace_back(e.to);
                que.push({dist[e.to], e.to});
            }
        }
    }
    return stk;
}

int n,m,q,x,k;

int main() {
    fio(); cin>>n>>m;
    Graph G(n);
    rep(i,m) {
        ll a,b; cin>>a>>b; a--;b--;
        G[a].emplace_back(b,1);
        G[b].emplace_back(a,1);
    }
    cin>>q;
    while(q--){
        cin>>x>>k;x--;
        auto stk=dijkstra(G,x,k);
        ll res=accumulate(all(stk),0LL)+sz(stk);
        print(res);
    }
}
//Small d and k
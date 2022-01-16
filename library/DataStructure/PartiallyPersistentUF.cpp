#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
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
#define fio() cin.tie(nullptr);ios::sync_with_stdio(false);
#define DEBUG_CTN(v) cerr<<#v<<":";for(auto itr=v.begin();itr!=v.end();itr++) cerr<<" "<<*itr; cerr<<endl
template<class T> bool chmax(T &a, const T &b) {if (a<b) {a = b; return true;} return false;}
template<class T> bool chmin(T &a, const T &b) {if (a>b) {a = b; return true;} return false;}
template<class T> void print(const T &t) {cout<<t<<"\n";}
template<class T> void PRINT(const T &t) {rep(i,sz(t)) cout<<t[i]<<" \n"[i==sz(t)-1];}
const ll INF = 1LL << 62;
const int iINF = 1 << 30;

using pll=pair<ll,ll>;
struct PartiallyPersistentUnionFind{
    vl par, last;
    vector<vector<pll>> upd;
    PartiallyPersistentUnionFind(){}
    PartiallyPersistentUnionFind(ll n): par(n,-1), last(n,INF), upd(n){
        fore(i,upd) i.emplace_back(-1,-1);
    }
    bool unite(ll x,ll y,ll t){
        x=find(x,t);
        y=find(y,t);
        if(x==y)return true;
        if(par[x]>par[y]) swap(x,y);
        par[x]+=par[y];
        upd[x].emplace_back(t,par[x]);
        par[y]=x;
        last[y]=t;
        return false;
    }
    ll find(ll x,ll t) const { // after t
        if(t<last[x]) return x;
        return find(par[x],t);
    }
    ll size(ll x,ll t) const {
        x = find(x,t);
        return -(--lower_bound(all(upd[x]), pll{t,0}))->second;
    }
    bool same(ll x, ll y,ll t) const {
        return find(x,t)==find(y,t);
    }
    ll operator()(ll x, ll t) const {
        return -(--lower_bound(all(upd[x]), pll{t,0}))->second;
    }
};

int n,m,q;
struct edge{
    int from;
    int to;
    int cost;
};

int main() {
    fio();cin>>n>>m>>q;
    PartiallyPersistentUnionFind uf(n);
    vector<edge> edges(m);
    rep(i,m){
        int a,b,c;cin>>a>>b>>c;a--;b--;
        edges[i]={a,b,c};
    }
    sort(all(edges),[](edge a,edge b){return a.cost<b.cost;});
    rep(i,m){
        auto [a,b,c]=edges[i];
        uf.unite(a,b,c);
    }
    rep(i,q){
        int u,v,w;cin>>u>>v>>w;u--;v--;
        if(!uf.same(u,v,w)) print("Yes");
        else print("No");
    }
}
//MST+1
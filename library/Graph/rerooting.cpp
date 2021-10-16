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
#define cnts(x,c) count(all(x),c)
#define fio() cin.tie(nullptr);ios::sync_with_stdio(false);
#define DEBUG_CTN(v) cerr<<#v<<":";for(auto itr=v.begin();itr!=v.end();itr++) cerr<<" "<<*itr; cerr<<endl
template<class T> bool chmax(T &a, const T &b) {if (a<b) {a = b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if (a>b) {a = b; return 1;} return 0;}
template<class T> void print(const T &t) {cout<<t<<"\n";}
template<class T> void PRINT(const T &t) {rep(i,sz(t)) cout<<t[i]<<" \n"[i==sz(t)-1];}
const ll INF = 1LL << 62;
const int iINF = 1 << 30;

//key_t:辺固有の情報　頂点固有の情報はラムダの方でキャプチャさせる
//sum_t:計算結果
template<typename key_t,typename sum_t=key_t>
struct ReRooting{
    struct Edge {
        int from,to;
        key_t cost;
        sum_t dp1,dp2;
        //dp1:部分木の内容
        //dp2:e=g[idx][i]の時、g[idx][0,i)のdp1の累積が入る
    };
    using F=function<sum_t(sum_t,sum_t)>;
    using G=function<sum_t(sum_t,Edge)>;

    vector<vector<Edge>> g;
    const F merge;
    const G score;
    const sum_t id;
    vector<sum_t> dp1,dp2;
    ReRooting(int n,const G &score,const F &merge,const sum_t &id=sum_t{})
            :g(n),merge(merge),score(score),id(id),dp1(n,id),dp2(n,id){}

    void add_edge(int u,int v,const key_t &c){
        g[u].emplace_back(Edge{u,v,c,id,id});
    }

    void dfs1(int v,int p){
        fore(e,g[v]) if(e.to!=p){
                dfs1(e.to,v);
                e.dp1=score(dp1[e.to],e);
                dp1[v]=merge(dp1[v],e.dp1);
            }
    }

    void dfs2(int v,int p,sum_t top){
        sum_t cur=id;
        rep(i,sz(g[v])){
            auto &e=g[v][i];
            e.dp2=cur;
            if(e.to==p)e.dp1=score(top,e);
            cur=merge(cur,e.dp1);
        }
        dp2[v]=cur;
        cur=id;
        rrep(i,sz(g[v])){
            auto &e=g[v][i];
            if(e.to!=p)
                dfs2(e.to,v,merge(e.dp2,cur));
            cur=merge(cur,e.dp1);
        }
    }

    vector<sum_t> build(){
        dfs1(0,-1);
        dfs2(0,-1,id);
        return dp2;
    }
};

int n,m;

int main() {
    fio(); cin>>n>>m;
    auto score=[&](ll x, auto e){
        return x+1LL;
    };
    auto merge=[](ll x, ll y){
        return x*y%m;
    };
    ReRooting<ll> g(n,score,merge,1LL);
    rep(i,n-1){
        int a,b;cin>>a>>b;a--;b--;
        g.add_edge(a,b,0);
        g.add_edge(b,a,0);
    }
    auto ans=g.build();
    fore(x,ans) print(x);
}
//EDPC V Subtree
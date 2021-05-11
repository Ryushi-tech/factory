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

int n,q,a,b,k;
using vi = vector<int>;

int main() {
    fio(); cin>>n;
    int lg=1;
    while((1<<lg)<n) lg++;

    vector<vi> G(n),anc(lg,vi(n));
    vi depth(n),id(n);

    rep(i,n-1) {
        cin>>a>>b; a--;b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    int vert_id=0;
    function<void(int,int)> dfs=[&](int v, int p){
        anc[0][v]=p;
        id[v]=vert_id++;
        fore(nv, G[v]){
            if(nv==p) continue;
            depth[nv]=depth[v]+1;
            dfs(nv,v);
        }
    };
    dfs(0,0);
    rep1(i,lg-1) rep(j,n) anc[i][j]=anc[i-1][anc[i-1][j]];

    auto lca=[&](int u,int v){
        if(depth[u]<depth[v]) swap(u,v);
        int dist=depth[u]-depth[v];
        rrep(i,lg){
            if(dist<(1<<i)) continue;
            dist-=(1<<i);
            u=anc[i][u];
        }
        if(u==v) return u;
        rrep(i,lg){
            if(anc[i][u]==anc[i][v]) continue;
            tie(u,v)=tie(anc[i][u],anc[i][v]);
        }
        return anc[0][u];
    };

    cin>>q;
    while(q--){
        cin>>k; vi sel(k);
        rep(i,k) cin>>sel[i],sel[i]--;
        sort(all(sel),[&](int u,int v){return id[u]<id[v];});
        int ans=0;
        rep(j,k) {
            ans+=depth[sel[j]];
            int lc=lca(sel[j],sel[(j+1)%k]);
            ans-=depth[lc];
        }
        print(ans);
    }
}
//typical90-35
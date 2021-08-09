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

using vi = vector<int>;

template<class T> struct RMQ {
    vector<vector<T>> jmp;
    RMQ(const vector<T>& V) : jmp(1, V) {
        for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
            jmp.emplace_back(sz(V) - pw * 2 + 1);
            rep(j,sz(jmp[k]))
            jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
        }
    }
    T query(int a, int b) {
        assert(a < b); // or return inf if a == b
        int dep = 31 - __builtin_clz(b - a);
        return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};

struct LCA {
    int T = 0;
    vi time, path, ret;
    RMQ<int> rmq;

    LCA(vector<vi>& C) : time(sz(C)), rmq((dfs(C,0,-1), ret)) {}
    void dfs(vector<vi>& C, int v, int par) {
        time[v] = T++;
        for (int y : C[v]) if (y != par) {
            path.push_back(v), ret.push_back(time[v]);
            dfs(C, y, v);
        }
    }

    int lca(int a, int b) {
        if (a == b) return a;
        tie(a, b) = minmax(time[a], time[b]);
        return path[rmq.query(a, b)];
    }
    //dist(a,b){return depth[a] + depth[b] - 2*depth[lca(a,b)];}
};

int n,q;
vector<vi> G;
vector<vi> edge[100100];
vi need[100100];
map<int,int> res_num[100100], res_sum[100100];
int dist[100100],cur_num[100100],cur_sum[100100];

void dfs2(int i, int p){
    fore(c,need[i]){
        res_num[i][c]=cur_num[c];
        res_sum[i][c]=cur_sum[c];
    }
    fore(e,edge[i]){
        int j=e[0],c=e[1],d=e[2];
        if(j==p) continue;
        dist[j]=dist[i]+d;
        cur_num[c]++;
        cur_sum[c]+=d;
        dfs2(j,i);
        cur_num[c]--;
        cur_sum[c]-=d;
    }
}

int main() {
    fio(); cin>>n>>q;
    G=vector<vi>(n);
    rep(i,n-1){
        int a,b,c,d; cin>>a>>b>>c>>d;
        a--; b--; c--;
        edge[a].push_back({b,c,d});
        edge[b].push_back({a,c,d});
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    LCA lcaG(G);

    int X[100100],Y[100100],U[100100],V[100100],L[100100];
    rep(i,q){
        cin>>X[i]>>Y[i]>>U[i]>>V[i];
        X[i]--; U[i]--; V[i]--;
        L[i]=lcaG.lca(U[i],V[i]);
        need[U[i]].emplace_back(X[i]);
        need[V[i]].emplace_back(X[i]);
        need[L[i]].emplace_back(X[i]);
    }
    dfs2(0,-1);
    rep(i,q){
        int x=X[i],y=Y[i],u=U[i],v=V[i],l=L[i];
        int du=dist[u]-res_sum[u][x]+res_num[u][x]*y;
        int dv=dist[v]-res_sum[v][x]+res_num[v][x]*y;
        int dl=dist[l]-res_sum[l][x]+res_num[l][x]*y;
        int ans=du+dv-2*dl;
        print(ans);
    }
}
//Colorful tree
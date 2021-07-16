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

using vi = vector<int>;
vector<vi> children,lis;
vi in,out,depth;
int timer;

void dfs(const int u){
    in[u]=timer++;
    lis[depth[u]].emplace_back(in[u]);
    fore(v,children[u]){
        depth[v]=depth[u]+1;
        dfs(v);
    }
    out[u]=timer++;
}

int n,q;

int main() {
    fio(); cin>>n;
    children=lis=vector<vi>(n);
    in=out=depth=vi(n);
    rep1(i,n-1){
        int p; cin>>p;
        children[p-1].emplace_back(i);
    }
    dfs(0);
    cin>>q;
    rep(i,q){
        int u,d; cin>>u>>d; u--;
        const auto &v=lis[d];
        print(lower_bound(all(v),out[u])-lower_bound(all(v),in[u]));
    }
}
//count descendants
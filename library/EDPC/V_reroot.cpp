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

#include<atcoder/all>
using namespace atcoder;
using mint = modint;
using vm = vector<mint>;

int n,mod;
using vi = vector<int>;
vector<vi> E(101010);
vm dp(101010), ans(101010);

void rec(int v,int p=-1) {
    dp[v]=1;
    fore(to,E[v]) {
        if (to==p) continue;
        rec(to,v);
        dp[v]*=dp[to]+1;
    }
}

void rerec(int v,int p=-1) {
    ans[v]=1;
    fore(to,E[v]) ans[v]*=dp[to]+1;
    int s=sz(E[v]);
    vm left(s),right(s);
    rep(i,s) {
        left[i]=dp[E[v][i]]+1;
        right[i]=dp[E[v][i]]+1;
    }
    rep1(i,s-1) left[i]*=left[i-1];
    rrep(i,s-1) right[i]*=right[i+1];
    rep(i,s) {
        if (E[v][i]==p) continue;
        dp[v]=1;
        if (i) dp[v]*=left[i-1];
        if (i+1<s) dp[v]*=right[i+1];
        rerec(E[v][i],v);
    }
}

int main() {
    cin>>n>>mod;
    mint::set_mod(mod);
    rep(i,n-1) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    rec(0);
    rerec(0);
    rep(i,n) print(ans[i].val());
}

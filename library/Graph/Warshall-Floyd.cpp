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

int n,m,q,u,v;
ll l,c;

int main() {
    fio(); cin>>n>>m>>l;
    vector<vl> dp(n,vl(n,1e10)), cost(n,vl(n,1e10));
    rep(i,m) {
        cin>>u>>v>>c; u--; v--;
        if(c>l) continue;
        dp[u][v]=dp[v][u]=c;
    }
    rep(i,n) rep(x,n) rep(y,n) dp[x][y] = min(dp[x][y], dp[x][i]+dp[i][y]);
    rep(x,n) rep(y,n) if(dp[x][y] <= l) cost[x][y] = 1;
    rep(i,n) rep(x,n) rep(y,n) cost[x][y] = min(cost[x][y], cost[x][i]+cost[i][y]);

    cin>>q;
    rep(i,q){
        cin>>u>>v; u--; v--;
        ll res = cost[u][v];
        print(res > 300 ? -1 : res-1);
    }
}
//Travel by car
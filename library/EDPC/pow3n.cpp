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

int n,k;
ll x,y;

int main() {
    fio(); cin>>n>>k;
    vl X(n),Y(n);
    rep(i,n) {cin>>X[i]>>Y[i];}
    vector<vl> d(n,vl(n));
    rep(i,n) rep(j,n){
            d[i][j]=(X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]);
        }
    vl cost(1<<n);
    rep(mask,(1<<n)) rep(i,n) rep(j,n){
                if((mask>>i)&1 and (mask>>j)&1){
                    chmax(cost[mask],d[i][j]);
                }
            }
    vector<vl> dp(1<<n,vl(k+1,INF));
    dp[0][0]=0;
    for(int mask=1;mask<(1<<n);mask+=2){
        for(int sub=mask;sub>0;sub=(sub-1)&mask){
            rep(j,k) dp[mask][j+1]=min(dp[mask][j+1],max(dp[mask^sub][j],cost[sub]));
        }
    }
    print(dp[(1<<n)-1][k]);
}
//typical90-45
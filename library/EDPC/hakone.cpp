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
using mint = modint1000000007;

int n,k;
mint dp[55][55][2525];

int main() {
    fio(); cin>>n>>k;
    dp[0][0][0]=1;
    rep(i,n) rep(a,n+1) rep(j,k+1){
        if(dp[i][a][j]==0) continue;
        int j2=j+2*a;
        dp[i+1][a][j2]+=dp[i][a][j];
        dp[i+1][a][j2]+=dp[i][a][j]*a;
        if(a) dp[i+1][a-1][j2]+=dp[i][a][j]*a*a;
        dp[i+1][a][j2]+=dp[i][a][j]*a;
        dp[i+1][a+1][j2]+=dp[i][a][j];
    }
    print(dp[n][0][k].val());
}
//permutation oddness
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

int n;

int main() {
    fio(); cin>>n;
    int N = 2*n;
    vl a(N); rep(i,N) cin>>a[i];
    vector<vl> dp(N,vl(N,iINF>>1));
    rep(i,N-1) dp[i][i+1] = abs(a[i]-a[i+1]);

    for(int d=3;d<N;d+=2) rep(l,N-d) {
        int cl=l, cr=l+d;
        for(int k=cl;k<cr;k++) chmin(dp[cl][cr],dp[cl][k]+dp[k+1][cr]);
        chmin(dp[cl][cr],dp[cl+1][cr-1]+abs(a[cl]-a[cr]));
    }
    print(dp[0][N-1]);
}
//Typical90-19
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx512f")
#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
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
#define fio() cin.tie(nullptr);ios::sync_with_stdio(false);cout<<fixed<<setprecision(12);
#define DEBUG_CTN(v) cerr<<#v<<":";for(auto itr=v.begin();itr!=v.end();itr++) cerr<<" "<<*itr; cerr<<endl
template<class T> bool chmax(T &a, const T &b) {if (a<b) {a = b; return true;} return false;}
template<class T> bool chmin(T &a, const T &b) {if (a>b) {a = b; return true;} return false;}
template<class T> void print(const T &t) {cout<<t<<"\n";}
template<class T> void PRINT(const T &t) {rep(i,sz(t)) cout<<t[i]<<" \n"[i==sz(t)-1];}
const ll INF = 0x3f3f3f3f3f3f3f3fll;
const int iINF = 1 << 30;

ll h, w;
ll r[2005],c[2005];
char a[2005][2005];
ll dp[2005][2005][2][2];
ll di[2]={1,0},dj[2]={0,1};

ll solve(){
    rep1(i,h) rep1(j,w) rep(d,2) rep(f,2) dp[i][j][d][f]=INF;
    rep(r1,2){
        int c1=a[1][1]^r1;
        dp[1][1][0][c1]=r1*r[1]+c1*c[1];
        dp[1][1][1][r1]=r1*r[1]+c1*c[1];
    }
    rep1(i,h) rep1(j,w) rep(d,2) rep(l,2){
        int ni=i+di[d],nj=j+dj[d];
        if(ni>h or nj>w) continue;
        int flip=a[ni][nj]^l,cost=0;
        if(d==0) cost=r[ni]*flip;
        else cost=c[nj]*flip;
        rep(nd,2){
            int nl=l;
            if(d!=nd) nl=flip;
            chmin(dp[ni][nj][nd][nl],dp[i][j][d][l]+cost);
        }
    }
    ll ret=INF;
    rep(d,2) rep(f,2) chmin(ret,dp[h][w][d][f]);
    return ret;
}

int main() {
    fio();cin>>h>>w;
    rep1(i,h) cin>>r[i];
    rep1(i,w) cin>>c[i];
    rep1(i,h) rep1(j,w) cin>>a[i][j],a[i][j]-='0';
    ll ans=solve();
    rep1(i,h) rep1(j,w) a[i][j]^=1;
    chmin(ans,solve());
    print(ans);
}
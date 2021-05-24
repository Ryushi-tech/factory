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

int h,w;

int main() {
    fio(); cin>>h>>w;
    vector<string> s(h);
    rep(i,h) cin>>s[i];
    vector<vl> dp(h,vl(w,iINF));

    function<ll(int,int)> dfs=[&](int x,int y)->ll{
        if(dp[x][y]!=iINF) return dp[x][y];
        if(x==h-1 and y==w-1) return dp[x][y]=0;
        if((x+y)%2==0){
            dp[x][y]=-INF;
            if(x<h-1) chmax(dp[x][y],dfs(x+1,y)+(s[x+1][y]=='+'? 1:-1));
            if(y<w-1) chmax(dp[x][y],dfs(x,y+1)+(s[x][y+1]=='+'? 1:-1));
            return dp[x][y];
        }else{
            dp[x][y]=INF;
            if(x<h-1) chmin(dp[x][y],dfs(x+1,y)-(s[x+1][y]=='+'? 1:-1));
            if(y<w-1) chmin(dp[x][y],dfs(x,y+1)-(s[x][y+1]=='+'? 1:-1));
            return dp[x][y];
        }
    };

    dfs(0,0);
    ll ans=dp[0][0];
    if(ans>0) print("Takahashi");
    else if(ans==0) print("Draw");
    else print("Aoki");
}
//Game in momotetsu world
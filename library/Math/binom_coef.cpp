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

int n,a,x,key,val;
vector<vl> dp(51,vl(2560,-1));

vector<vl> comb(int n) {
    vector<vl> v(n+1,vl(n+1));
    rep(i,sz(v)) {
        v[i][0]=1; v[i][i]=1;
    }
    rep1(j,sz(v)-1) rep1(k,j-1) {
            v[j][k]=(v[j-1][k-1]+v[j-1][k]);
    }
    return v;
}

int main() {
    fio(); cin>>n>>a;
    auto res=comb(51);
    dp[0][0]=1;
    map<int,int> d;
    rep(i,n) cin>>x,d[x]++;
    vl v;
    fore(y,d) v.emplace_back(y.first);
    sort(rall(v));
    fore(y,v) {
        key=y; val=d[y];
        rrep(i,n) rrep(j,2501) if(dp[i][j]>-1) rrep1(k,val) {
            if(dp[i+k][j+k*key]==-1) dp[i+k][j+k*key]=dp[i][j]*res[val][k];
            else dp[i+k][j+k*key]+=dp[i][j]*res[val][k];
        }
    }
    ll ans=0;
    rep1(j,n) if(dp[j][j*a]>-1) ans+=dp[j][j*a];
    print(ans);
}
//高橋くんとカード
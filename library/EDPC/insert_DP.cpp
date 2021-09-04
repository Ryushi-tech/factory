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
template<class T> void PRINT(const T &t) {rep(i,sz(t)) cout<<t[i]<<" \n"[i==sz(t)-1];}
const ll INF = 1LL << 62;
const int iINF = 1 << 30;

#include<atcoder/all>
using namespace atcoder;
using mint = modint1000000007;
using vm = vector<mint>;

int n;
using vi = vector<int>;

int main() {
    fio(); cin>>n;
    vi h(n);
    fore(x,h) cin>>x;
    vector dp(n,vm(n));
    vm su(n+1,1);
    su[0]=0; dp[0][0]=1;
    rep(i,n) {
        if(i==0) continue;
        rep(j,i+1){
            if(h[i-1]<=h[i]) dp[i][j]+=su[i]-su[j];
            if(h[i-1]>=h[i]) dp[i][j]+=su[j];
        }
        rep(j,i+1) su[j+1]=su[j]+dp[i][j];
    }
    print(su[n].val());
}
//Deforestation
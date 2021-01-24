#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pl = pair<ll, ll>;
using ml = map<ll, ll>;
using vl = vector<ll>;
using vp = vector<pl>;
using vvl = vector<vl>;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(n);i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define fore(i_in,a) for (auto& i_in: a)
#define forp(x,y,a) for(auto& [x, y]: a)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pq(T) priority_queue<T, vector<T>, greater<T>>
#define fio() cin.tie(nullptr);ios::sync_with_stdio(false);
#define CEIL(a, b) (a+b-1)/b;
#define offset_FLOOR(a, b) (a-1)/b;
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<(int)v.size();i++) cerr<<" "<<v[i]; cerr<<endl
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
template<class T> bool chmax(T &a, const T &b) {if (a<b) { a = b; return true; } return 0;}
template<class T> bool chmin(T &a, const T &b) {if (a>b) { a = b; return true; } return 0;}
template<class T> void print(const T &t) { cout << t << "\n"; }

int n; ll k;
vvl dp(41, vl(2, -1));

int main() {
    fio(); cin>>n>>k;
    vl A(n); rep(i,n) cin>>A[i];
    dp[40][0] = 0;
    rrep(d, 40){
        ll msk = 1LL << d;
        int ones = 0;
        rep(i,n) if(A[i] & msk) ones++;
        int zeros = n - ones;
        if (k & msk) {
            chmax(dp[d][0], dp[d+1][0] + zeros * msk);
            chmax(dp[d][1], dp[d+1][0] + ones * msk);
        }
        else {
            chmax(dp[d][0], dp[d+1][0] + ones * msk);
        }
        if (dp[d+1][1] > -1) chmax(dp[d][1], dp[d+1][1] + max(zeros, ones) * msk);
    }
    ll ans = max(dp[0][0], dp[0][1]);
    print(ans);
}
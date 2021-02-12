#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pl = pair<ll, ll>;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep1(i,n) for(int i=(n);i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define fore(i_in,a) for (auto& i_in: a)
#define forp(x,y,a) for(auto& [x, y]: a)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pq(T) priority_queue<T, vector<T>, greater<T>>
#define fio() cin.tie(nullptr);ios::sync_with_stdio(false);
#define ofst_FLR(a, b) (a-1)/b;
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<(int)v.size();i++) cerr<<" "<<v[i]; cerr<<endl
#define UNIQUE(v) v.erase(unique(all(v)), v.end());
template<class T> bool chmax(T &a, const T &b) {if (a<b) { a = b; return true; } return 0;}
template<class T> bool chmin(T &a, const T &b) {if (a>b) { a = b; return true; } return 0;}
template<class T> void print(const T &t) { cout << t << "\n"; }

int A[80][80], B[80][80];
bitset<30303> dp[80][80];

int main() {
    fio(); int h, w; cin>>h>>w;

    rep(i,h) rep(j,w) cin>>A[i][j];
    rep(i,h) rep(j,w) cin>>B[i][j];

    int base = 15000;
    dp[0][0].set(base + A[0][0] - B[0][0]);
    dp[0][0].set(base - A[0][0] + B[0][0]);

    rep(i,h) rep(j,w) {
        int d = abs(A[i][j]-B[i][j]);
        if(i) {
            dp[i][j] |= dp[i-1][j] >> d;
            dp[i][j] |= dp[i-1][j] << d;
        }
        if(j) {
            dp[i][j] |= dp[i][j-1] >> d;
            dp[i][j] |= dp[i][j-1] << d;
        }
    }

    int ans = 10000;
    rep(d,30303) if(dp[h-1][w-1][d]) chmin(ans, abs(d - base));
    print(ans);
}

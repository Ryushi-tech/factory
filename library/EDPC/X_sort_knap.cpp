#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vp = vector<pair<int, int>>;
using vvp = vector<vp>;
using vvi = vector<vi>;
#define rep(i, a, b) for (int i = a; i < (int) (b); i++)
#define rrep(i, a, b) for (int i = a; i >= (int) (b); i--)
#define fore(i_in, a) for (auto& i_in: a)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pq(T) priority_queue<T, vector<T>, greater<T>>
template<class T> void chmin(T &a, const T &b) { if (a > b) a = b; }
template<class T> void chmax(T &a, const T &b) { if (a < b) a = b; }
template<class T> void print(const T &t) { cout << t << "\n"; }

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vi W(1010), S(1010), V(1010);
    vl dp(20020);
    vp order(1010);
    rep(i,0,n) {cin >> W[i] >> S[i] >> V[i]; order[i]={W[i]+S[i], i};}
    sort(order.begin(), order.begin()+n);
    ll res=0;
    rep(i, 0, n) {
        int j = order[i].second;
        rrep(x, S[j], 0) {
            ll v = dp[x] + V[j]; chmax(res, v);
            if (x+W[j]<=10000) chmax(dp[x+W[j]], v);
        }
    }
    print(res);
}
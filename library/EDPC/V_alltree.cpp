#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
using mint = modint;
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

int n, mod;
vvi E;
vl dp(101010), ans(101010);

void rec(int v, int p = -1) {
    dp[v] = 1;
    fore(to, E[v]) {
        if (to == p) continue;
        rec(to, v);
        dp[v] *= dp[to] + 1; dp[v] %= mod;
    }
}

void rerec(int v, int p = -1) {
    ans[v] = 1;
    fore(to, E[v]) { ans[v] *= dp[to] + 1; ans[v] %= mod; }
    int s = E[v].size();
    vl left(s), right(s);
    rep(i, 0, s) { left[i] = dp[E[v][i]] + 1; right[i] = dp[E[v][i]] + 1; }
    rep(i, 1, s) { left[i] *= left[i-1]; left[i] %= mod; }
    rrep(i, s-2, 0) { right[i] *= right[i+1]; right[i] %= mod; }
    rep(i,0,s) {
        if (E[v][i] == p) continue;
        dp[v] = 1;
        if (i) dp[v] *= left[i-1]; dp[v] %= mod;
        if (i + 1 < s) dp[v] *= right[i+1]; dp[v] %= mod;
        rerec(E[v][i], v);
    }
}

int main() {
    cin >> n >> mod;
    E.assign(n, vi());
    rep(i, 0, n-1) {
        int u, v; cin >> u >> v; u--, v--;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    rec(0);
    rerec(0);
    rep(i,0,n) print(ans[i]);
}

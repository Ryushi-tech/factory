#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using mint = modint1000000007;
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vm = vector<mint>;
using vvm = vector<vm>;
#define rep(i, a, b) for (int i = a; i < (int) (b); i++)
#define rrep(i, a, b) for (int i = a; i >= (int) (b); i--)
#define fore(i_in, a) for (auto& i_in: a)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<class T> void print(const T &t) { cout << t << "\n"; }

int n; vvi E;
vm dp(201010, 1), ans(201010, 1), fact(201010, 1), inv(201010);

void pre() {
    rep(i, 1, 201010) fact[i] = i * fact[i-1];
    mint fi = fact[201009].inv();
    inv.assign(201010, fi);
    rrep(i, 201009, 1) inv[i-1] = i * inv[i];
}

vi sz(201010);

void rec(int v, int p = -1) {
    dp[v] = 1;
    sz[v]++;
    fore(to, E[v]) {
        if (to == p) continue;
        rec(to, v);
        sz[v] += sz[to];
        dp[v] *= dp[to] * inv[sz[to]];
    }
    dp[v] *= fact[sz[v] - 1];
}

void rerec(int v, mint d, int p = -1) {
    mint sum = 1;
    fore(to, E[v]) {
        if (to == p) sum *= d * fact[n - sz[v] - 1] * inv[n - sz[v]];
        else sum *= dp[to] * inv[sz[to]];
    }
    ans[v] = sum * fact[n - 1];
    fore(to, E[v]) {
        if (to == p) continue;
        rerec(to, sum * dp[to].inv() * fact[sz[to]], v);
    }
}

int main() {
    pre();
    cin >> n;
    E.assign(n, vi());
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    rec(0);
    rerec(0,1);
    rep(i, 0, n) print(ans[i].val());
}

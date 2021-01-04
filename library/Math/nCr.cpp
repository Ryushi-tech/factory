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
const ll INF = 1LL << 60;

#include<atcoder/all>
using namespace atcoder;
using mint = modint1000000007;
using vm = vector<mint>;
using vvm = vector<vm>;

vm dp(201010), fact(201010, 1), inv(201010);

void init() {
    rep(i, 1, 201010) fact[i] = i * fact[i-1];
    inv[201009] = fact[201009].inv();
    rrep(i, 201009, 1) inv[i-1] = i * inv[i];
}

mint nCr(int a, int b){
    if (a < b || a < 0 || b < 0) return 0;
    return fact[a] * inv[b] * inv[a - b];
}

mint nPr(int a, int b){
    if (a < b || a < 0 || b < 0) return 0;
    return fact[a] * inv[a - b];
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    init(); dp[0] = 1;
    int h, w, n; cin >> h >> w >> n;
    vp obst(n+2); obst[n] = {1, 1}; obst[n+1] = {h, w};
    rep(i, 0, n) {
        int a, b; cin >> a >> b;
        obst[i] = {a, b};
    }
    sort(all(obst));
    int N = n + 2;
    rep(i,1,N) {
        mint res = 0;
        rep(j, 0, i) {
            if (obst[i].second < obst[j].second) continue;
            int dy = obst[i].first - obst[j].first, dx = obst[i].second - obst[j].second;
            res -= dp[j] * nCr(dx + dy, dx);
        }
        dp[i] = res;
    }
    print((-1*dp[N-1]).val());
}

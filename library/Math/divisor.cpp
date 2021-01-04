#include<bits/stdc++.h>
using namespace std;
using ll = ll;
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

vl enum_divisors(ll N) {
    vl res;
    for (ll i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            if (N/i != i) res.push_back(N/i);
        }
    }
    sort(all(res));
    return res;
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
    print((-1*dp[N-1]).val());
}

#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
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

ll op(ll a, ll b) {return max(a, b);}
ll eid() {return 0;}
ll gh(ll f, ll x) {return f + x;}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q; cin >> n >> q;
    vl dp(n+2);
    lazy_segtree<ll, op, eid, ll, gh, gh, eid> seg(dp);
    vvp R(202020);

    rep(i, 0, q) {
        int l, r, a; cin >> l >> r >> a;
        l--; r--;
        R[r].push_back({l,a});
    }

    rep(r, 0, n) {
        ll opt = seg.prod(0, r);
        seg.apply(r, r+1, opt);
        fore(p, R[r]) {
            seg.apply(p.first, r+1, p.second);
        }
    }

    ll ans = seg.prod(0, n);
    print(ans);
}

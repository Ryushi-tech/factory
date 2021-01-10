#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vp = vector<pii>;
using vvi = vector<vi>;
#define rep(i, a, b) for (int i = a; i < (int) (b); i++)
#define rrep(i, a, b) for (int i = a; i >= (int) (b); i--)
#define fore(i_in, a) for (auto& i_in: a)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pq(T) priority_queue<T, vector<T>, greater<T>>
template<class T> void chmin(T &a, T b) { if (a > b) a = b; }
//template<class T> bool chmin(T& a, T b) {if (a > b) {a = b;return true;} else return false;}
template<class T> void chmax(T &a, T b) { if (a < b) a = b; }
//template<class T> bool chmax(T& a, T b) {if (a < b) {a = b;return true;} else return false;}
template<class T> void print(const T &t) { cout << t << "\n"; }

class Dsu {
public:
    Dsu() {}
    explicit Dsu(int n) : dat(n, -1), num_components_(n) {}

    int sz() const { return dat.size(); }
    int find(int v) {
        assert(0 <= v), assert(v < sz());
        return dat[v] < 0 ? v : dat[v] = find(dat[v]);
    }
    pii unite(int u, int v) {
        assert(0 <= u), assert(u < sz());
        assert(0 <= v), assert(v < sz());
        u = find(u), v = find(v);
        if (u == v) return {u, -1};
        --num_components_;
        if (-dat[u] < -dat[v]) swap(u, v);
        dat[u] += dat[v];
        dat[v] = u;
        return {u, v};
    }
    bool same(int u, int v) {
        assert(0 <= u), assert(u < sz());
        assert(0 <= v), assert(v < sz());
        return find(u) == find(v);
    }
    int size(int v) {
        assert(0 <= v), assert(v < sz());
        return -dat[find(v)];
    }
    int num_components() const { return num_components_; }

private:
    vi dat;
    int num_components_;
};

int main() {
    int lim = 400040;
    int n; cin >> n;
    Dsu d(lim); vi v(lim);
    rep(i,0,n) {
        int a, b; cin >> a >> b;
        a--; b--;
        tie(a, b) = d.unite(a, b);
        v[a]++;
        if (b != -1) v[a] += v[b];
    }
    int ans = 0;
    rep(i,0,lim) {
        if (d.find(i) == i) ans += min(d.size(i), v[i]);
    }
    print(ans);
}

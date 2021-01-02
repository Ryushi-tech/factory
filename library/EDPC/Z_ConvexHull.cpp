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


template<typename T> struct ConvexHullTrick {
    using ptt = pair<T,T>;
    vector<ptt> deq;          // first * x + second
    T s,t;
    ConvexHullTrick(int n) {  // n: query
        deq.resize(n);
        s=0, t=0;
    }
    void add(T a, T b) {      // a: monotony decreasing
        const ptt p(a,b);
        while(s+1<t && check(deq[t-2],deq[t-1],p)) t--;
        deq[t++] = p;
    }
    T query(T x) {            // x: monotony increasing
        while(s+1<t && f(deq[s], x) >= f(deq[s+1], x)) s++;
        return f(deq[s], x);
    }
    T bin_query(T x) {        // x: general order
        T low = s-1, high = t-1;
        while(low + 1 < high) {
            T mid = low + high >> 1;
            if (isright(deq[mid], deq[mid+1], x)) low = mid;
            else high = mid;
        }
        return f(deq[high], x);
    }
private:
    bool isright(const ptt &p1, const ptt &p2, T x) {
        return (p1.second-p2.second) >= x * (p2.first-p1.first);
    }
    bool check(const ptt &p1, const ptt &p2, const ptt &p3) {
        return (p2.first-p1.first)*(p3.second-p2.second) >=
               (p2.second-p1.second)*(p3.first-p2.first);
    }
    T f(const ptt &p, T x) {
        return p.first * x + p.second;
    }
};

int n; ll c;
vl h(202020), dp(202020);

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> c;
    ConvexHullTrick<ll> cht(n);
    rep(i, 0, n) {
        cin >> h[i];
        if(i) { dp[i] = cht.query(h[i]) + h[i] * h[i]; }
        cht.add(-2 * h[i], h[i] * h[i] + dp[i] + c);
    }
    print(dp[n-1]);
}

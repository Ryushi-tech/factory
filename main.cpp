#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
#define rep(i, a, b) for (int i = a; i < (int) (b); i++)
template<class T> void print(const T &t) { cout << t << "\n"; }

template<typename T> struct ConvexHullTrick {
    using ptt = pair<T,T>;
    vector<ptt> deq;          // first * x + second
    T s,t;
    explicit ConvexHullTrick(int n) {  // n: query
        deq.resize(n);
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
private:
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

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
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
template<class T> void chmin(T &a, const T &b) { if (a > b) a = b; }
template<class T> void chmax(T &a, const T &b) { if (a < b) a = b; }
template<class T> void print(const T &t) { cout << t << "\n"; }
const ll INF = 1LL << 60;

template <class Z> map<Z,int> factorize(Z n){
    map<Z,int> res;
    for(Z i=2;i*i<=n;++i) while(n%i==0) ++res[i],n/=i;
    if(n!=1) ++res[n];
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

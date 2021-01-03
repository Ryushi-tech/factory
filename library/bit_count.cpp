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
template<class T> void chmin(T &a, T b) { if (a > b) a = b; }
//template<class T> bool chmin(T& a, T b) {if (a > b) {a = b;return true;} else return false;}
template<class T> void chmax(T &a, T b) { if (a < b) a = b; }
//template<class T> bool chmax(T& a, T b) {if (a < b) {a = b;return true;} else return false;}
template<class T> void print(const T &t) { cout << t << "\n"; }

int n; vi A(20);
vvi X(20,vi(20)), Y(20,vi(20));

int bit_count(int x) {
    if (x == 0) return 0;
    return bit_count(x >> 1) + (x & 1);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    rep(i,0,n) {
        cin >> A[i];
        rep(j,0,A[i]) {
            cin >> X[i][j] >> Y[i][j]; X[i][j]--;
        }
    }
    int ans = 0;
    rep(bits, 0, 1 << n) {
        bool ok = true;
        rep(i,0,n) {
            if (bits >> i & 1) rep(j,0,A[i]) {
                if((bits >> X[i][j] & 1) != Y[i][j]) ok = false;
            }
        }
        if (ok) chmax(ans, bit_count(bits));
    }
    print(ans);
}

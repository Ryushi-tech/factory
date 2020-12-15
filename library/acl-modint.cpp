#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
using vm = vector<mint>;
using vvm = vector<vm>;
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
template<class T> void print(const T& t){ cout << t << "\n"; }

vvm dp(2000, vm(2000)), X(2000, vm(2000)), Y(2000, vm(2000)), Z(2000, vm(2000));

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int H, W; cin >> H >> W;
    vector<string> s(H);
    rep(h, H) cin >> s[h];
    dp[0][0] = 1;

    rep(h, H) {
        rep(w, W) {
            if (h == 0 && w == 0) continue;
            if (s[h][w] == '#') continue;
            if (w > 0         ) X[h][w] = X[h][w - 1] + dp[h][w - 1];
            if (         h > 0) Y[h][w] = Y[h - 1][w] + dp[h - 1][w];
            if (w > 0 && h > 0) Z[h][w] = Z[h - 1][w - 1] + dp[h - 1][w - 1];
            dp[h][w] = (X[h][w] + Y[h][w] + Z[h][w]);
        }
    }
    print(dp[H - 1][W - 1].val());
}

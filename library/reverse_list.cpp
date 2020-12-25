#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define repi(i, n) for (int i = 1; i <= (int) (n); i++)
template<class T> void print(const T &t) { cout << t << "\n"; }
const ll INF = 1LL << 60;

int n;
vi P, R;

bool solve(int s, vi &res) {
    if (res.size() == n - 1) {
        rep(i, n) if (P[i] != i) return false;
        return true;
    }
    if (R[s] <= s) return false;
    for (int k = R[s]; k > s; k--) {
        res.push_back(k);
        swap(P[k], P[k - 1]);
    }
    return solve(R[s], res);
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    P.resize(n), R.resize(n);
    rep(i, n) {
        cin >> P[i];
        P[i]--;
        R[P[i]] = i;
    }
    vi ans;
    if (!solve(0, ans)) print(-1);
    else for (auto &x: ans) print(x);
}
//Exoswap
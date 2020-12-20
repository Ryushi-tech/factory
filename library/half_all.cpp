#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define rng(x) x.begin(), x.end()
template<class T> void print(const T& t){ cout << t << "\n"; }

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, t;
    cin >> n >> t;
    vl s(n);
    for (ll &x: s) cin >> x;

    vl A{0}, B{0};
    for (ll x : s) {
        for (int i = A.size(); i--;) {
            ll sum = x + A[i];
            A.push_back(sum);
        }
        swap(A, B);
    }

    sort(rng(B));
    ll ans = 0;
    for (ll a: A)
        if (t >= a) {
            a += *(upper_bound(rng(B), t - a) - 1);
            ans = max(a, ans);
        }
    print(ans);
}
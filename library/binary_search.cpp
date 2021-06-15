#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
template<class T> void print(const T& t){ cout << t << "\n"; }

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n; cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    int low = 0, high = 1 << 30;
    const int geta = n + 1;

    while(high - low > 1) {
        int mid = (low + high) / 2;
        ll num = 0;
        fenwick_tree<ll> fw(2 * n + 10);
        int sum = 0;
        fw.add(sum + geta, 1);
        rep(i, n) {
            int val;
            if (a[i] <= mid) val = 1; else val = -1;
            sum += val;
            num += fw.sum(1, sum + geta);
            fw.add(sum + geta, 1);
        }
        if (num > n * (n + 1) / 2 / 2) high = mid;
        else low = mid;
    }
    print(high);
}
//Median of medians

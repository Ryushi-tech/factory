#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
#define rep(i, n) for (int i = 1; i <= (int) (n); i++)
#define rng(x) x.begin(), x.end()
#define pq(T) priority_queue<T, vector<T>, greater<T>>
template<class T> void print(const T& t){ cout << t << "\n"; }
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    int ans = 0;
    rep(i, n) {
        bool flg = true;
        for (int base:{8, 10}) {
            int x = i;
            while(x) {
                if (x % base == 7) flg = false;
                x /= base;
            }
        }
        ans += flg;
    }
    print(ans);
}
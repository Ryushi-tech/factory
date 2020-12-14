#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
template<class T> void print(const T& t){ cout << t << "\n"; }

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    vector<int> A(m);
    rep(i, m) cin >> A[i];
    sort(all(A));
    A.push_back(n + 1);
    vector<int> s;
    int prev = 0;
    for (int a : A) {
        int x = a - prev - 1;
        if (x > 0) s.push_back(x);
        prev = a;
    }
    if (s.empty()) {
        print(0);
        return 0;
    }
    else {
        sort(all(s));
        int x = s.front();
        int ans = 0;
        for (int ss : s) ans += (ss + x - 1) / x;
        print(ans);
        return 0;
    }
}

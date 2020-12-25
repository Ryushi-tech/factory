#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
template<class T> void print(const T& t){ cout << t << "\n"; }

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    map<ll, int> dict;
    rep(i,n) {ll d; cin >> d; dict[d]++;}
    int ans = 0;
    for(auto &x : dict) if (x.second & 1) ans++;
    print(ans);
}

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pl = pair<ll, ll>;
using ml = map<ll, ll>;
using vl = vector<ll>;
using vp = vector<pl>;
using vvl = vector<vl>;
#define rep(i, a, b) for (int i = a; i < (int) (b); i++)
#define rrep(i, a, b) for (int i = a; i >= (int) (b); i--)
#define fore(i_in, a) for (auto& i_in: a)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pq(T) priority_queue<T, vector<T>, greater<T>>
template<class T> bool chmin(T& a, T b) {if (a > b) {a = b;return true;} else return false;}
template<class T> bool chmax(T& a, T b) {if (a < b) {a = b;return true;} else return false;}
template<class T> void print(const T &t) { cout << t << "\n"; }

ll n, ans;
vl cards(100100);

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin>>n;
    rep(i,0,n) cin >> cards[i];
    rep(i,0,n) {
        if (cards[i] >= cards[i+1]) {
            ans += cards[i]/2;
            cards[i] %= 2;
            if (cards[i] > 0 and cards[i+1] > 0) {ans+=cards[i]; cards[i+1]-=cards[i];}
        }
        else {
            ans += cards[i];
            cards[i+1]-=cards[i];
        }
    }
    print(ans);
}

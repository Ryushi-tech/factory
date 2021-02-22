#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep1(i,n) for(int i=(n);i>0;i--)
#define fore(i_in,a) for (auto& i_in: a)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pq(T) priority_queue<T, vector<T>, greater<T>>
#define fio() cin.tie(nullptr);ios::sync_with_stdio(false);
#define DEBUG_CTN(v) cerr<<#v<<":";for(auto itr=v.begin();itr!=v.end();itr++) cerr<<" "<<*itr; cerr<<endl
#define UNIQUE(v) v.erase(unique(all(v)), v.end());
template<class T> bool chmax(T &a, const T &b) {if (a<b) { a = b; return true; } return 0;}
template<class T> bool chmin(T &a, const T &b) {if (a>b) { a = b; return true; } return 0;}
template<class T> void print(const T &t) { cout << t << "\n"; }
const ll INF = 1LL << 60;

int main() {
    fio(); ll k; cin>>k;
    ll cnt=0;
    for(ll a=1; a<=k; a++) {
        for (ll b = 1; b <= k; b++) {
            if (a * b > k) break;
            else for (ll c = 1; c <= k; c++) {
                    if (a * b * c > k) break;
                    else cnt++;
                }
            }
        }
    print(cnt);
}

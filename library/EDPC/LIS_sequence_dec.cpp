#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep1(i,n) for(int i=(n);i>0;i--)
#define fore(i_in,a) for (auto& i_in: a)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fio() cin.tie(nullptr);ios::sync_with_stdio(false);
#define DEBUG_CTN(v) cerr<<#v<<":";for(auto itr=v.begin();itr!=v.end();itr++) cerr<<" "<<*itr; cerr<<endl
template<class T> bool chmax(T &a, const T &b) {if (a<b) { a = b; return true; } return 0;}
template<class T> bool chmin(T &a, const T &b) {if (a>b) { a = b; return true; } return 0;}
template<class T> void print(const T &t) { cout << t << "\n"; }
const ll INF = 1LL << 62;
const int iINF = 1 << 30;

int n;
using vi = vector<int>;

template<class T> int LIS(vector<T> a,  bool is_strong = true) {
    const T lINF = iINF; int N = sz(a); vector<T> dp(N, lINF);
    rep(i,N) {
        if (is_strong) *lower_bound(all(dp), a[i]) = a[i];
        else *upper_bound(all(dp), a[i]) = a[i];
    }
    return lower_bound(all(dp), lINF) - dp.begin();
}

int main() {
    fio(); cin>>n;
    vi a(n); fore(x,a) cin>>x;
    reverse(all(a));
    print(LIS(a,false));
}

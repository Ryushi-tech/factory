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

#include<atcoder/all>
using namespace atcoder;

int n,q;
ll s,t,x,d;

using S = int;
using F = int;

S op(S l, S r) { return min(l,r); }
S e() { return iINF; }

S mapping(F l, S r) { return min(l,r); }
F composition(F l, F r) { return min(l,r); }
F id() { return iINF; }

int main() {
    fio(); cin>>n>>q;
    vl s(n),t(n),x(n),d(q);
    rep(i,n) cin>>s[i]>>t[i]>>x[i];
    rep(i,q) cin>>d[i];
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(q);
    rep(i,n){
        ll cl = s[i]-x[i];
        ll cr = t[i]-x[i];
        auto l = lower_bound(all(d), cl) - d.begin();
        auto r = lower_bound(all(d), cr) - d.begin();
        seg.apply(l,r,x[i]);
    }
    rep(i,q) {int ans = seg.get(i); print(ans != iINF ? ans : -1);}
}

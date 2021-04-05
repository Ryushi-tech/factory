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

int k,m;
using mat = vector<vl>;

mat mat_mul(mat &a, mat &b) {
    mat res(sz(a), vector<ll>(sz(b[0])));
//    rep(i,sz(a)) rep(j,sz(b[0])) rep(l,sz(b)) res[i][j] ^= a[i][l] & b[l][j];
    rep(i,sz(a)) rep(j,sz(b[0])) rep(l,sz(b)) res[i][j] += a[i][l] * b[l][j];
    return res;
}

mat mat_pow(mat a, ll n) {
    mat res(sz(a), vl(sz(a)));
    rep(i,sz(a)) res[i][i] = (1LL<<32)-1;
    while(n>0) {
        if(n&1) res = mat_mul(a, res);
        a = mat_mul(a, a);
        n >>= 1;
    }
    return res;
}

int main() {
    fio(); cin>>k>>m;
    vl a(k), c(k);
    rep(i,k) cin>>a[i];
    rep(i,k) cin>>c[i];

    if(m-1<k) {print(a[m-1]); return 0;}

    reverse(all(a));
    mat A(k,vl(1));
    rep(i,k) A[i][0] = a[i];

    mat g(k,vl(k));
    rep(i,k) g[0][i] = c[i];
    rep(i,k-1) g[i+1][i] = (1LL<<32)-1;

    auto G = mat_pow(g,m-k);
    auto res = mat_mul(G,A);
    print(res[0][0]);
}
//漸化式
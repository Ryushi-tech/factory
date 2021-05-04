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
template<class T> bool chmax(T &a, const T &b) {if (a<b) { a = b; return true; } return false;}
template<class T> bool chmin(T &a, const T &b) {if (a>b) { a = b; return true; } return false;}
template<class T> void print(const T &t) { cout << t << "\n"; }
const ll INF = 1LL << 62;
const int iINF = 1 << 30;

#include<atcoder/all>
using namespace atcoder;
using mint = modint1000000007;
using vm = vector<mint>;
using vi = vector<int>;

int n,m,x,y;
ll k,a;
using mat = vector<vm>;

mat mat_mul(mat &a, mat &b) {
    mat res(sz(a), vm(sz(b[0])));
    rep(i,sz(a)) rep(j,sz(b[0])) rep(l,sz(b)) {
        res[i][j] += a[i][l] * b[l][j];
    }
    return res;
}

mat mat_pow(mat a, ll n) {
    mat res(sz(a), vm(sz(a)));
    rep(i,sz(a)) res[i][i] = 1;
    while(n>0) {
        if(n&1) res = mat_mul(a, res);
        a = mat_mul(a, a);
        n >>= 1;
    }
    return res;
}

int main() {
    fio(); cin>>n>>m>>k;

    mat A(n,vm(1));
    rep(i,n) cin>>a,A[i][0]=a;

    mat g(n,vm(n));
    mint base=2, inv2=base.inv();
    mint mm=m, invm=mm.inv();
    mint c=inv2*invm;
    vi cnt(n);
    rep(i,m) {
        cin>>x>>y; x--;y--; cnt[x]++; cnt[y]++;
        g[x][x]+=c; g[x][y]+=c; g[y][y]+=c; g[y][x]+=c;
    }
    rep(i,n) g[i][i]+=(m-cnt[i])*invm;

    auto G = mat_pow(g,k);
    auto res = mat_mul(G,A);
    rep(i,n) cout<<res[i][0].val()<<"\n";
}
//Graph smoothing
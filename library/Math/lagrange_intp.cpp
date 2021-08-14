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
#define cnts(x,c) count(all(x),c)
#define fio() cin.tie(nullptr);ios::sync_with_stdio(false);
#define DEBUG_CTN(v) cerr<<#v<<":";for(auto itr=v.begin();itr!=v.end();itr++) cerr<<" "<<*itr; cerr<<endl
template<class T> bool chmax(T &a, const T &b) {if (a<b) {a = b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if (a>b) {a = b; return 1;} return 0;}
template<class T> void print(const T &t) {cout<<t<<"\n";}
template<class T> void PRINT(const T &t) {rep(i,sz(t)) cout<<t[i]<<" \n"[i==sz(t)-1];}
const ll INF = 1LL << 62;
const int iINF = 1 << 30;

#include<atcoder/all>
using namespace atcoder;
using mint=modint1000000007;
using vm=vector<mint>;

int max_n=3e6+300;
vm fact(max_n+1,1),inv(max_n+1,1);

void init() {
    rep1(i,max_n) fact[i]=i*fact[i-1];
    inv[max_n]=fact[max_n].inv();
    rrep1(i,max_n) inv[i-1]=i*inv[i];
}

mint lagrange_interpolation(vm y, mint val) {
    if(fact[2]==1) init();
    int N=sz(y)-1;
    vm R(N+1,1);
    rrep1(i,N) R[i-1]=R[i]*(val-i);
    mint res=0,L=1;
    rep(i,N+1) {
        res+=y[i]*L*R[i]*inv[i]*inv[N-i]*mint((N-i)&1 ? -1:1);
        L*=val-i;
    }
    return res;
}

ll n,t;

int main() {
    fio(); cin>>n;
    vm a(n+1);
    rep(i,n+1) {int z; cin>>z; a[i]=z;}
    cin>>t;
    vm x(n+1); rep(i,n+1) x[i]=i;
    auto ans=lagrange_interpolation(a,t);
    print(ans.val());
}
//見たことのない多項式
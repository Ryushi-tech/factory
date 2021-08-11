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

mint lagrange_interpolation(vm x, vm y, mint T) {
    const ll n=sz(x)-1;
    mint ret=0;
    rep(i,n+1) {
        mint t=1;
        rep(j,n+1) {
            if(i==j) continue;
            t*=(T-x[j])*(x[i]-x[j]).inv();
        }
        ret+=t*y[i];
    }
    return ret;
}

mint lagrange_interpolate_arithmetic(mint a, mint d,vm y, mint T) {
    const ll n=sz(y)-1;
    mint ret=0,ft=1;
    rep(i,n+1) ft*=T-(a+d*i);
    mint f=1;
    rep1(i,n) f*=-1*i*d;
    ret+=y[0]*f.inv()*ft*(T-a).inv();
    rep(i,n){
        f*=d*(i+1)*(d*(i-n)).inv();
        ret+=y[i+1]*f.inv()*ft*(T-a-d*(i+1)).inv();
    }
    return ret;
}

ll n,t;

int main() {
    fio(); cin>>n;
    vm a(n+1);
    rep(i,n+1) {int z; cin>>z; a[i]=z;}
    cin>>t;
    vm x(n+1); rep(i,n+1) x[i]=i;
//    auto ans=lagrange_interpolation(x,a,t);
    auto ans=lagrange_interpolate_arithmetic(0,1,a,t);
    print(ans.val());
}
//見たことのない多項式
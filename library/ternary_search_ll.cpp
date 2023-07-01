#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx512f")
#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vi = vector<int>;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep1(i,n) for(int i=(n);i>0;i--)
#define fore(i_in,a) for (auto& i_in: a)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define cnts(x,c) count(all(x),c)
#define fio() cin.tie(nullptr);ios::sync_with_stdio(false);cout<<fixed<<setprecision(12);
#define DEBUG_CTN(v) cerr<<#v<<":";for(auto itr=v.begin();itr!=v.end();itr++) cerr<<" "<<*itr; cerr<<endl
template<class T> bool chmax(T &a, const T &b) {if (a<b) {a = b; return true;} return false;}
template<class T> bool chmin(T &a, const T &b) {if (a>b) {a = b; return true;} return false;}
template<class T> void print(const T &t) {cout<<t<<"\n";}
template<class T> void PRINT(const T &t) {rep(i,sz(t)) cout<<t[i]<<" \n"[i==sz(t)-1];}
const ll INF = 0x3f3f3f3f3f3f3f3fll;
const int iINF = 1 << 30;

ll a,b;

double check(ll x){
    double res=(double)b*x+(double)a/sqrt(1+x);
    return res;
}

int main() {
    fio(); cin>>a>>b;
    ll l=0,r=1e18;
    while(l+2<r){
        ll c1=l+(r-l)/3;
        ll c2=r-(r-l)/3;
        if(check(c1)<check(c2)) r=c2;
        else l=c1;
    }
    double ans=a;
    for(ll x=l;x<=r;x++) chmin(ans,check(x));
    cout << fixed << setprecision(6) << ans << "\n";
}
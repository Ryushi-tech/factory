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
template<class T> void PMINT(const T &t) {rep(i,sz(t)) cout<<t[i].val()<<" \n"[i==sz(t)-1];}
const ll INF = 1LL << 62;
const int iINF = 1 << 30;

#include<atcoder/all>
using namespace atcoder;
using mint=modint;
using vm=vector<mint>;


vm lagrange_interpolation(vm x,vm y){
    int n=sz(x)-1;
    rep(i,n+1){
        mint t=1;
        rep(j,n+1)if(i!=j)t*=x[i]-x[j];
        y[i]*=t.inv();
    }
    ll cur=0,nxt=1;
    vector dp(2,vm(n+2));
    dp[0][0]=-x[0];dp[0][1]=1;
    rep1(i,n){
        rep(j,n+2){
            dp[nxt][j]=-dp[cur][j]*x[i];
            if(j)dp[nxt][j]+=dp[cur][j-1];
        }
        swap(nxt,cur);
    }
    vm res(n+1);
    rep(i,n+1){
        if(y[i]==0)continue;
        if(x[i]==0)rep(j,n+1)res[j]+=dp[cur][j+1]*y[i];
        else{
            mint dx=x[i].inv(),tmp=0;
            rep(j,n+1){
                res[j]-=(dp[cur][j]-tmp)*dx*y[i];
                tmp=-(dp[cur][j]-tmp)*dx;
            }
        }
    }
    return res;
}

vm interpolate_kth(vm x, vm y, int n) {
    vm res(n), temp(n);
    rep(k,n-1) for(int i=k+1;i<n;i++)
        y[i] = (y[i]-y[k]) * (x[i]-x[k]).inv();
    mint last = 0; temp[0] = 1;
    rep(k,n) rep(i,n) {
        res[i] += y[k] * temp[i];
        swap(last, temp[i]);
        temp[i] -= last * x[k];
    }
    return res;
}

int p;

int main() {
    fio(); cin>>p;
    mint::set_mod(p);
    vm x(p),y(p);
    rep(i,p) {int z; cin>>z; y[i]=z;}
    rep(i,p) x[i]=i;
    vm res=lagrange_interpolation(x,y);
    PMINT(res);
}
//polynomial construction
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
using mint = modint998244353;

int n;

int main() {
    fio();cin>>n;

//    compress
    vector<int> a(n); set<int> s;
    rep(i,n) cin>>a[i],s.insert(a[i]);
    map<int,int> p;
    int idx=0;
    fore(x,s) p[x]=idx,idx++;
//

    int m=sz(s);
    fenwick_tree<mint> bit(m+1);
    vector<mint> two(n+1,1);
    rep(i,n) two[i+1]=two[i]*2;
    mint ans=0;
    rep(i,n){
        ans+=two[i]*bit.sum(0,p[a[i]]+1);
        bit.add(p[a[i]],two[i+1].inv());
    }
    print(ans.val());
}
//LEQ
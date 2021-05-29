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

int n,m,c,l,r;

int main() {
    fio(); cin>>n>>m;
    vector<pair<int,pair<int,int>>> clr(m);
    rep(i,m) cin>>c>>l>>r,clr[i]={c,{l-1,r}};
    sort(all(clr));
    dsu d(n+1);
    ll ans=0;
    int cnt=0;
    fore(x,clr){
        c=x.first,l=x.second.first,r=x.second.second;
        if(!d.same(l,r)) d.merge(l,r),ans+=c,cnt++;
    }
    print(cnt==n?ans:-1LL);
}
//typical90-49
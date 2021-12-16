#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
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
#define fio() cin.tie(nullptr);ios::sync_with_stdio(false);
#define DEBUG_CTN(v) cerr<<#v<<":";for(auto itr=v.begin();itr!=v.end();itr++) cerr<<" "<<*itr; cerr<<endl
template<class T> bool chmax(T &a, const T &b) {if (a<b) {a = b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if (a>b) {a = b; return 1;} return 0;}
template<class T> void print(const T &t) {cout<<t<<"\n";}
template<class T> void PRINT(const T &t) {rep(i,sz(t)) cout<<t[i]<<" \n"[i==sz(t)-1];}
const ll INF = 1LL << 62;
const int iINF = 1 << 30;

int n;

void compress(vi &v){
    vi x=v;
    sort(all(x));
    x.erase(unique(all(x)),x.end());
    fore(y,v) y=lower_bound(all(x),y)-x.begin();
}

int main() {
    fio(); cin>>n;
    vi a(n),b(n);
    fore(x,a) cin>>x;
    fore(x,b) cin>>x;
    compress(a); compress(b);
    vector<pair<int,int>> ab(n);
    rep(i,n) ab[i]={a[i],b[i]};
    sort(all(ab));
    fenwick_tree<int> bi(n);
    ll ans=0;
    rep(i,n){
        auto le=i;
        while(i+1<n and ab[i].first==ab[i+1].first) i++;
        for(int j=le;j<=i;j++) bi.add(ab[j].second,1);
        for(int j=le;j<=i;j++) ans+=bi.sum(ab[j].second,n);
    }
    print(ans);
}
//jealous two
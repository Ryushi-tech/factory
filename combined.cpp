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

int q;
ll n,a,b,c,d;

ll dfs(ll n, ll tmp){
    while(n%2==0) {tmp+=a; n/=2;}
    while(n%3==0) {tmp+=b; n/=3;}
    while(n%5==0) {tmp+=c; n/=5;}
    if(n==1) return tmp;
    ll res1 = dfs(n+1,tmp+d);
    ll res2 = dfs(n-1,tmp+d);
    return min(res1, res2);
}

int main() {
    fio(); cin>>q;
    while(q--){
        cin>>n>>a>>b>>c>>d;
        ll ans = dfs(n,d);
        print(ans);
    }
}

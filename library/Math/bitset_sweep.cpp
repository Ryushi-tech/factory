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

int n,m,t,a,s;

int main() {
    fio(); cin>>n>>m;
    vector<bitset<300>> sw(n+1);
    rep(i,n){
        cin>>t;
        rep(j,t){
            cin>>a; a--; sw[i].set(a);
        }
    }
    rep(i,m){
        cin>>s; sw[n].set(i,s);
    }
    int idx0=0;
    rep(i,m){
        int idx=-1;
        for(int j=idx0;j<n;j++){
            if(sw[j][i]){
                idx=j;
                break;
            }
        }
        if(idx==-1) continue;
        swap(sw[idx0],sw[idx]);
        for(int j=idx0+1;j<=n;j++) if(sw[j][i]) sw[j]^=sw[idx0];
        idx0++;
    }
    if(sw[n].any()){
        print(0);
    } else {
        int ans=1;
        rep(i,n) if(sw[i].none()) ans=ans*2%998244353;
        print(ans);
    }
}
//typical90-57
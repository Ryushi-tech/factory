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
#define fio() cin.tie(nullptr);ios::sync_with_stdio(false);cout<<fixed<<setprecision(12);
#define DEBUG_CTN(v) cerr<<#v<<":";for(auto itr=v.begin();itr!=v.end();itr++) cerr<<" "<<*itr; cerr<<endl
template<class T> bool chmax(T &a, const T &b) {if (a<b) {a = b; return true;} return false;}
template<class T> bool chmin(T &a, const T &b) {if (a>b) {a = b; return true;} return false;}
template<class T> void print(const T &t) {cout<<t<<"\n";}
template<class T> void PRINT(const T &t) {rep(i,sz(t)) cout<<t[i]<<" \n"[i==sz(t)-1];}
const ll INF = 1LL << 62;
const int iINF = 1 << 30;

template <typename C>
int mex(C const & xs){
    int y=0;
    for(int x:xs) { // xs must be sorted (duplication is permitted)
        if(y<x) break;
        if(y==x) ++y;
    }
    return y;
}

int grundy(int x,int y){
    static map<pair<int,int>,int> memo;
    if(x>y) swap(x,y);
    pair<int,int> key={x,y};
    if(!memo.count(key)) {
        set<int> g;
        for(int i=2;i<=x;i+=2) g.insert(grundy(x-i,y+i/2));
        for(int i=2;i<=y;i+=2) g.insert(grundy(x+i/2,y-i));
        memo[key] = mex(g);
    }
    return memo[key];
}

int main() {
    rep(z,100) rep(x,z+1){
            int y=z-x;
            if(y>=x) if(grundy(x,y)==0) printf("%d %d\n",x,y);
    }
}

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

template <class T> map<T, int> factorize(T n) {
    map<T, int> res;
    for (T i = 2; i * i <= n; ++i) while (n % i == 0) ++res[i], n /= i;
    if (n != 1) ++res[n];
    return res;
}

int n;

int main() {
    fio(); cin>>n;
    map<int,vector<pair<int,bool>>> memo;
    int cnt=0;
    rep(i,n) rep(j,2){
        int x; cin>>x;
        fore(p, factorize(x)){
            memo[p.first].emplace_back(i,(bool)j);
            cnt++;
        }
    }
    two_sat ts(cnt*2);
    int pos=0;
    fore(x,memo){
        auto [p,v]=x;
        rep(i,sz(v)){
            ts.add_clause(v[i].first,!v[i].second,cnt+pos,true);
            if(i){
                ts.add_clause(cnt+pos-1,false,cnt+pos,true);
                ts.add_clause(v[i].first,!v[i].second,cnt+pos-1,false);
            }
            pos++;
        }
    }
    print(ts.satisfiable()?"Yes":"No");
}
//Coprime solitaire
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

int n,m,d,x;
int db[33][100100];

int main() {
    fio(); cin>>n>>m>>d;
    vector<vector<pair<int,int>>> bridges(n);
    rep(i,m){
        cin>>x;x--;
        bridges[x].emplace_back(i,x+1);
        bridges[x+1].emplace_back(i,x);
    }
    rep(i,n) sort(all(bridges[i]));
    rep(i,n){
        int pos=i,cur=0;
        while(lower_bound(all(bridges[pos]),make_pair(cur,-1))!=bridges[pos].end()){
            auto itr=lower_bound(all(bridges[pos]),make_pair(cur,-1));
            pos=itr->second;
            cur=itr->first;cur++;
        }
        db[0][i]=pos;
    }
    rep(k,30) rep(i,n) db[k+1][i]=db[k][db[k][i]];
    rep(i,n){
        int pos=i;
        rep(k,30) if((1<<k)&d) pos=db[k][pos];
        print(pos+1);
    }
}
//阿弥陀
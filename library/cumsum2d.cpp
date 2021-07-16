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
template<class T> void PRINT(const T &t) {rep(i,sz(t)) cout<<t[i]<<" \n"[i==sz(t)-1];}
const ll INF = 1LL << 62;
const int iINF = 1 << 30;

template<class T> struct CumulativeSum2D{
    vector<vector<T>> data;
    CumulativeSum2D(int H,int W): data(H+1,vector<T>(W+1,0)){}
    void add(int y,int x,ll value){
        ++x; ++y;
        if(y>=sz(data) || x>=sz(data[0])) return;
        data[y][x]+=value;
    }
    void build(){
        int h=sz(data)-1, w=sz(data[0])-1;
        rep(i,h) rep(j,w) data[i+1][j+1]+=data[i][j+1]+data[i+1][j]-data[i][j];
    }
    ll query(int sy,int sx,int gy,int gx){
        return data[gy+1][gx+1]-data[sy][gx+1]-data[gy+1][sx]+data[sy][sx];
    }
};

int n,k,C[808][808];

bool check(int x){
    CumulativeSum2D<int> acu(n,n);
    rep(i,n) rep(j,n){
            if(C[i][j]<x) acu.add(i,j,-1);
            else acu.add(i,j,1);
        }
    acu.build();
    bool flg=true;
    rep(i,n-k+1) rep(j,n-k+1){
            ll res=acu.query(i,j,i+k-1,j+k-1);
            flg&=res>0LL;
        }
    return flg;
}

int main() {
    fio(); cin>>n>>k;
    rep(i,n) rep(j,n) {
            cin>>C[i][j];
        }
    int ok=0,ng=1000000001;
    while(ng-ok>1){
        int mid=(ok+ng)/2;
        if(check(mid)) ok=mid;
        else ng=mid;
    }
    print(ok);
}
//pond
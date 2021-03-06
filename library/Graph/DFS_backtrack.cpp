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

int h,w;
char C[20][20];
bool seen[20][20];
vector<int> dx={-1,1,0,0};
vector<int> dy={0,0,1,-1};

int dfs(int sx,int sy,int px,int py){
    if(sx==px and sy==py and seen[px][py]) return 0;
    seen[px][py]=true;
    int ret=-10000;
    rep(i,4){
        int nx=px+dx[i],ny=py+dy[i];
        if(nx<0 or ny<0 or nx>=h or ny>=w or C[nx][ny]=='#') continue;
        if((sx!=nx or sy!=ny) and seen[nx][ny]) continue;
        chmax(ret,dfs(sx,sy,nx,ny)+1);
    }
    seen[px][py]=false;
    return ret;
}

int main() {
    fio(); cin>>h>>w;
    rep(i,h) rep(j,w) cin>>C[i][j];
    int ans=-1;
    rep(i,h) rep(j,w) chmax(ans,dfs(i,j,i,j));
    if(ans<3) ans=-1;
    print(ans);
}
//typical90-72
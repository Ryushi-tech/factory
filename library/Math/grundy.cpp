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

int n;
using vi = vector<int>;

int main() {
    fio(); cin>>n;
    vi a(100100), b(100100);
    vector<vi> grundy(55,vi(1555,0));
    rep(i,n) cin>>a[i];
    rep(i,n) cin>>b[i];
    rep(i,51) rep(j,1501){
            vi mex(1555);
            if (i>0) mex[grundy[i-1][j+i]]=1;
            if (j>1) rep1(k,j/2) mex[grundy[i][j-k]]=1;
            rep(k,1555) if(mex[k]==0) {grundy[i][j]=k; break;}
    }
    int res=0;
    rep(i,n) {
        res^=grundy[a[i]][b[i]];
    }
    print(res!=0?"First":"Second");
}
//typical90-31
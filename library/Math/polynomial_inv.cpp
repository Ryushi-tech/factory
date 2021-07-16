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
using mint = modint998244353;
using vm = vector<mint>;

vm pol_inv(vm C, int L){
//    c[0]=1
    int n=sz(C);
    vm A={1,0};
    int level=0;
    while((1<<level)<L){
        int CS=min(2<<level,n);
        vm P=convolution(A,vm(C.begin(),C.begin()+CS));
        vm Q(2<<level);
        Q[0]=1;
        for(int j=(1<<level);j<(2<<level);j++){
            Q[j]=-P[j];
        }
        A= convolution(A,Q);
        A.resize(4<<level);
        level++;
    }
    A.resize(L);
    return A;
}

int n,k;

int main() {
    fio(); cin>>n>>k;
    vector<vm> dp(k+1);
    dp[k]={1,1,1};
    rrep(i,k){
        int lim=(i==0?n:min(k/i,n));
        vm C(sz(dp[i+1]));
        C[0]=1;
        rep1(j,sz(dp[i+1])-1){
            C[j]=-dp[i+1][j];
        }
        vm G=pol_inv(C,lim+2);
        dp[i]=G;
    }
    print(dp[0][n+1].val());
}
//typical90-90
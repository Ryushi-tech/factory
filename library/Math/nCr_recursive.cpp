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

ll A,B,K;
vector<vl> memo(61,vl(61,-1));
ll nCr(ll a, ll b){
    if(b==0 or a==b) return 1;
    if(0<=memo[a][b]) return memo[a][b];
    return memo[a][b]= nCr(a-1,b-1)+ nCr(a-1,b);
}

int main() {
    fio(); cin>>A>>B>>K; K--;
    ll n=A+B; string ans="";
    rep(i,n){
        if(A>0){
            if(K<nCr(A+B-1,B)){
                ans+="a"; A--;
            } else {
                ans+="b";
                K-=nCr(A+B-1,B);
                B--;
            }
        }
        else {
            ans+="b";B--;
        }
    }
    print(ans);
}
//aab aba baa
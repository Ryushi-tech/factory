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
string s,t;
using vi = vector<int>;
int mod=699999953;

int main() {
    fio(); cin>>n>>s>>t;
    vi seq1(n),seq3(n);
    rep(i,n) {
        seq1[i]=(s[i]=='R'?0:(s[i]=='G'?1:2));
        seq3[i]=(t[i]=='R'?0:(t[i]=='G'?1:2));
    }
    int ans=0;
    rep(i,3){
        vi seq2(n);
        rep(j,n) seq2[j]=(i-seq3[j]+3)%3;
        int pow3=1,hash1=0,hash2=0;
        rep(j,n) {
            hash1=(hash1*3+seq1[j])%mod;
            hash2=(hash2+pow3*seq2[n-j-1])%mod;
            if(hash1==hash2)ans++;
            pow3=pow3*3%mod;
        }
        pow3=1,hash1=0,hash2=0;
        rep(j,n-1) {
            hash1=(hash1+pow3*seq1[n-j-1])%mod;
            hash2=(hash2*3+seq2[j])%mod;
            if(hash1==hash2)ans++;
            pow3=pow3*3%mod;
        }
    }
    print(ans);
}
//typical90-47
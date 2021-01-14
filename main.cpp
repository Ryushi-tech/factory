#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pl = pair<ll, ll>;
using ml = map<ll, ll>;
using vl = vector<ll>;
using vp = vector<pl>;
using vvl = vector<vl>;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(n);i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define fore(i_in, a) for (auto& i_in: a)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pq(T) priority_queue<T, vector<T>, greater<T>>
#define fio() cin.tie(nullptr);ios::sync_with_stdio(false);
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
template<class T> bool chmax(T &a, const T &b) {if (a<b) { a = b; return 1; } return 0;}
template<class T> bool chmin(T &a, const T &b) {if (a>b) { a = b; return 1; } return 0;}
template<class T> void print(const T &t) { cout << t << "\n"; }

#include<atcoder/all>
using namespace atcoder;
using mint = modint1000000007;

ll n, k;
ml dic;

int main() {
    fio(); cin>>n;
    rep(i,n) {cin>>k; dic[k]++;}
    for (int i = 1 - (n&1); i < n; i+=2) {
        if (i == 0 and dic[i] != 1) {
            print(0); return 0;
        }
        else if (i != 0 and dic[i] != 2) {
            print(0); return 0;
        }
    }
    mint base = 2;
    mint ans = base.pow(n/2);
    print(ans.val());
}

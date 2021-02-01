#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pl = pair<ll, ll>;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep1(i,n) for(int i=(n);i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define fore(i_in,a) for (auto& i_in: a)
#define forp(x,y,a) for(auto& [x, y]: a)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pq(T) priority_queue<T, vector<T>, greater<T>>
#define fio() cin.tie(nullptr);ios::sync_with_stdio(false);
#define ofst_FLR(a, b) (a-1)/b;
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<(int)v.size();i++) cerr<<" "<<v[i]; cerr<<endl
#define UNIQUE(v) v.erase(unique(all(v)), v.end());
template<class T> bool chmax(T &a, const T &b) {if (a<b) { a = b; return true; } return 0;}
template<class T> bool chmin(T &a, const T &b) {if (a>b) { a = b; return true; } return 0;}
template<class T> void print(const T &t) { cout << t << "\n"; }

int main(){
    random_device seed_gen;
    mt19937_64 rnd(seed_gen());

    uniform_int_distribution<int> dist_N(4, 10), dist_A(1, 20);
    int n = dist_N(rnd);
    vector<int> A(n);
    rep(i,n) A[i] = dist_A(rnd);

    cout << n << endl;
    rep(i,n) cout << A[i] << " \n"[i==n-1];
    return 0;
}
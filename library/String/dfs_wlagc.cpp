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
#define fore(i_in,a) for (auto& i_in: a)
#define forp(x,y,a) for(auto& [x, y]: a)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pq(T) priority_queue<T, vector<T>, greater<T>>
#define fio() cin.tie(nullptr);ios::sync_with_stdio(false);
#define CEIL(a, b) (a+b-1)/b;
#define offset_FLOOR(a, b) (a-1)/b;
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<(int)v.size();i++) cerr<<" "<<v[i]; cerr<<endl
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
template<class T> bool chmax(T &a, const T &b) {if (a<b) { a = b; return true; } return 0;}
template<class T> bool chmin(T &a, const T &b) {if (a>b) { a = b; return true; } return 0;}
template<class T> void print(const T &t) { cout << t << "\n"; }

#include<atcoder/all>
using namespace atcoder;
using mint = modint1000000007;
using msm = map<string, mint>;

int n;
vector<msm> dp(101);
string C = "AGCT";

bool ok(string l4) {
    rep(i,4) {
        string tmp = l4;
        if (i!=3) swap(tmp[i], tmp[i+1]);
        if (int(tmp.find("AGC")) != -1) return false;
    }
    return true;
};

mint dfs(int cur, string l3) {
    if (dp[cur][l3]!=0) return dp[cur][l3];
    if (cur == n) return 1;
    mint res = 0;
    fore(c, C) {
        if (ok(l3 + c)) res += dfs(cur + 1, l3.substr(1,2) + c);
    }
    dp[cur][l3] = res;
    return res;
};

int main() {
    fio(); cin>>n;
    mint ans = dfs(0, "THX");
    print(ans.val());
}
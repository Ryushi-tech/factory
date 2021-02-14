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
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_ANY(v) cerr<<#v<<":";for(auto itr=v.begin();itr!=v.end();itr++) cerr<<" "<<*itr; cerr<<endl
#define UNIQUE(v) v.erase(unique(all(v)), v.end());
template<class T> bool chmax(T &a, const T &b) {if (a<b) { a = b; return true; } return 0;}
template<class T> bool chmin(T &a, const T &b) {if (a>b) { a = b; return true; } return 0;}
template<class T> void print(const T &t) { cout << t << "\n"; }

#include<atcoder/all>
using namespace atcoder;

int h, w;

int main() {
    fio(); cin>>h>>w;
    vector<string> s(h);
    rep(i,h) cin>>s[i];

    s[0][0] = '#';
    s[0][w-1] = '#';
    s[h-1][0] = '#';
    s[h-1][w-1] = '#';

    dsu d(2020);
    int thr = 1010;
    rep(i,h) rep(j,w) if(s[i][j]=='#') d.merge(i, thr + j);

    set<int> col, row;
    rep(i,h) row.insert(d.leader(i));
    rep(j,w) col.insert(d.leader(thr + j));
    int ans = min(col.size(), row.size()) - 1;
    print(ans);
}

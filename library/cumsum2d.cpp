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


template<class T> struct CumulativeSum2D{
    vector<vector<T>> data;
    CumulativeSum2D(int H, int W): data(H+1, vector<T>(W+1, 0)){}
    void add(int y, int x, ll value){
        ++x; ++y;
        if(y >= (int) data.size() || x >= (int) data[0].size()) return;
        data[y][x] += value;
    }
    void build(){
        int h = (int) data.size() - 1, w = (int) data[0].size() - 1;
        rep(i,h) rep(j,w) data[i+1][j+1] += data[i][j+1] + data[i+1][j] - data[i][j];
    }
    ll query(int sy, int sx, int gy, int gx){
        return data[gy][gx] - data[sy][gx] - data[gy][sx] + data[sy][sx];
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h,w,k; cin >> h >> w >> k;
    vector<string> s(h); rep(i,h) cin >> s[i];

    CumulativeSum2D<ll> acu(h,w);
    rep(i,h) rep(j,w) if(s[i][j] == '1') acu.add(i, j, 1);
    acu.build();
    rep(i,h) rep(j,w) cout << acu.query(1,2,i+1,j+1) << " \n"[j==w-1];
}

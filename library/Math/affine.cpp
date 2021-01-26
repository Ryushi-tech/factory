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

int n,m,q,a,b;
vector<vector<ll>> VX, VY;

int main() {
    fio(); cin>>n;
    vector<int> X(n), Y(n); rep(i,n) cin>>X[i]>>Y[i];
    VX.push_back({1,0,0}); VY.push_back({0,1,0});
    cin>>m; rep(i,m) {
        int x; cin>>x;
        vector<ll> vx = VX.back();
        vector<ll> vy = VY.back();
        if (x==1) {
            swap(vx,vy);
            rep(j,3) vy[j] *= -1;
        }
        else if (x==2) {
            swap(vx,vy);
            rep(j,3) vx[j] *= -1;
        }
        else if (x==3) {
            ll p; cin>>p;
            rep(j,3) vx[j] *= -1;
            vx[2] += 2 * p;
        }
        else {
            ll p; cin>>p;
            rep(j,3) vy[j] *= -1;
            vy[2] += 2 * p;
        }
        VX.push_back(vx); VY.push_back(vy);
    }
    cin>>q; rep(i,q) {
        cin>>a>>b; b--;
        ll ansx = VX[a][0]*X[b] + VX[a][1]*Y[b] + VX[a][2];
        ll ansy = VY[a][0]*X[b] + VY[a][1]*Y[b] + VY[a][2];
        cout << ansx << " " << ansy << "\n";
    }
}
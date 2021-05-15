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

#include<atcoder/all>
using namespace atcoder;

int n,w,a,k,c;

int main() {
    fio(); cin>>n>>w;
    mf_graph<int> graph(n+2);
    int s=n,t=n+1,su=0;
    rep(i,n) {
        cin>>a; su+=a;
        graph.add_edge(s,i,a);
        graph.add_edge(i,t,w);
    }
    rep(i,n) {
        cin>>k;
        rep(j,k) {
            cin>>c; c--;
            graph.add_edge(c,i,iINF);
        }
    }
    cout<<su-graph.flow(s,t)<<endl;
}
//typical90-40
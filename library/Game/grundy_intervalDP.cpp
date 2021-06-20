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
template<class T> void print(const T &t) {cout << t << "\n";}
const ll INF = 1LL << 62;
const int iINF = 1 << 30;

int q,n;
using vi = vector<int>;
vi L(101),R(101);

int calc(int al, int ar, vector<vi>& grundy){
    if(grundy[al][ar]>=0) return grundy[al][ar];
    grundy[al][ar]=0;
    set<int> s;
    rep(i,n) if(al<=L[i] and R[i]<=ar) {
        int x=calc(al,L[i],grundy);
        int y=calc(R[i],ar,grundy);
        s.insert(x^y);
    }
    while(s.count(grundy[al][ar])) grundy[al][ar]++;
    return grundy[al][ar];
}

int main() {
    fio(); cin>>q;
    while(q--){
        cin>>n; rep(i,n) cin>>L[i]>>R[i],L[i]--,R[i]--;
        vector<vi> gr(101,vi(101,-1));
        if(calc(0,100,gr)==0) print("Bob");
        else print("Alice");
    }
}
//interval game2
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
template<class T> void print(const T &t) {cout<<t<<"\n";}
template<class T> void PRINT(const T &t) {rep(i,sz(t)) cout<<t[i]<<" \n"[i==sz(t)-1];}
const ll INF = 1LL << 62;
const int iINF = 1 << 30;

#define pq(T) priority_queue<T, vector<T>, greater<T>>
int q,c;
ll a,b;

int main() {
    fio(); cin>>q;
    pq(ll) L,R;
    L.push(INF); R.push(INF);
    ll min_f=0;
    while(q--){
        cin>>c;
        if(c==1){
            cin>>a>>b;
            ll l0=-L.top(), r0=R.top();
            min_f+=max(l0-a,0LL)+max(a-r0,0LL)+b;
            L.push(-a);
            ll tmp=L.top(); L.pop();
            R.push(-tmp);
            R.push(a);
            tmp=R.top(); R.pop();
            L.push(-tmp);
        }
        else{
            ll l0=-L.top();
            cout<<l0<<" "<<min_f<<endl;
        }
    }
}

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep1(i,n) for(int i=(n);i>0;i--)
#define fore(i_in,a) for (auto& i_in: a)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pq(T) priority_queue<T, vector<T>, greater<T>>
#define fio() cin.tie(nullptr);ios::sync_with_stdio(false);
#define DEBUG_CTN(v) cerr<<#v<<":";for(auto itr=v.begin();itr!=v.end();itr++) cerr<<" "<<*itr; cerr<<endl
#define UNIQUE(v) v.erase(unique(all(v)), v.end());
template<class T> bool chmax(T &a, const T &b) {if (a<b) { a = b; return true; } return 0;}
template<class T> bool chmin(T &a, const T &b) {if (a>b) { a = b; return true; } return 0;}
template<class T> void print(const T &t) { cout << t << "\n"; }
const ll INF = 1LL << 60;

string s;
ll m;
int d;

bool check(ll n) {
    vector<ll> Y;
    ll mm = m;
    while (0 < mm) {
        Y.push_back(mm % n);
        mm /= n;
    }
    reverse(all(Y));

    if (s.size() < Y.size()) return true;
    else if (s.size() > Y.size()) return false;

    int len = s.size();
    rep(i, len) {
            ll x = s[i] - '0';
            ll y = Y[i];

            if (x == y) continue;
            else if (x < y) return true;
            else return false;
    }
    return true;
}

int main() {
    fio(); cin>>s>>m;

    if(s.size()==1) {
        ll x = stol(s);
        print(x <= m ? 1: 0);
        return 0;
    }

    rep(i,s.size()) chmax(d,stoi(s.substr(i,1)));
    ll ok = d, ng = INF;
    while(ng - ok > 1){
        ll mid = (ok + ng) /2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    print(ok - d);
}

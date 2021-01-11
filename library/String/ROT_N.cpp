#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pl = pair<ll, ll>;
using ml = map<ll, ll>;
using vl = vector<ll>;
using vp = vector<pl>;
using vvl = vector<vl>;
#define rep(i, a, b) for (int i = a; i < (int) (b); i++)
#define rrep(i, a, b) for (int i = a; i >= (int) (b); i--)
#define fore(i_in, a) for (auto& i_in: a)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pq(T) priority_queue<T, vector<T>, greater<T>>
template<class T> void chmin(T &a, T b) { if (a > b) a = b; }
//template<class T> bool chmin(T& a, T b) {if (a > b) {a = b;return true;} else return false;}
template<class T> void chmax(T &a, T b) { if (a < b) a = b; }
//template<class T> bool chmax(T& a, T b) {if (a < b) {a = b;return true;} else return false;}
template<class T> void print(const T &t) { cout << t << "\n"; }

int main(){
    int n; cin >> n;
    string s; cin >> s;
    for(auto c : s){
        int idx = c - 'A' + n;
        idx %= 26;
        char res = 'A' + idx;
        cout << res;
    }
}
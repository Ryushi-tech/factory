#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep1(i,n) for(int i=(n);i>0;i--)
#define fore(i_in,a) for (auto& i_in: a)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fio() cin.tie(nullptr);ios::sync_with_stdio(false);
#define DEBUG_CTN(v) cerr<<#v<<":";for(auto itr=v.begin();itr!=v.end();itr++) cerr<<" "<<*itr; cerr<<endl
template<class T> bool chmax(T &a, const T &b) {if (a<b) { a = b; return true; } return 0;}
template<class T> bool chmin(T &a, const T &b) {if (a>b) { a = b; return true; } return 0;}
template<class T> void print(const T &t) { cout << t << "\n"; }
const ll INF = 1LL << 62;
const int iINF = 1 << 30;

int n;
string s;

int main() {
    fio(); cin>>n;
    cout<<0<<endl;
    cin>>s;
    if(s=="Vacant") return 0;

    int l=0, r=n;
    string tmp;
    int q=20;
    while(q--) {
        int mid=(l+r)/2;
        cout<<mid<<endl;
        cin>>tmp;
        if(tmp=="Vacant") return 0;
        if ((mid&1 and s!=tmp) or (mid%2==0 and s==tmp)) l=mid;
        else r=mid;
    }
}
//Vacant seat
/** 
How often have I said to you that when you have eliminated the impossible, whatever remains, however improbable, must be the truth?        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl
#define kakimasu(x) cout << x << '\n'
#define sseuda(x) cout << x

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<long long> vll;
typedef vector<vector<int> > vvi;
typedef vector<vll> vvll;
typedef vector<pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const int INF = 1 << 30;
/**
Start coding from here
*/

int toInt(char ch) {
	string s = "0123456789ABCDEFGHI";
	return s.find(ch);
}
string to_base(unsigned int n, unsigned int base) {
    static const char alphabet[] = "0123456789ABCDEFGHI";
    string result;
    while(n) { result += alphabet[n % base]; n /= base; }
    return string(result.rbegin(), result.rend());
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tc;
	cin>>tc;
	while(tc--) {
		int k, b, n;
		cin>>k>>b>>n;
		string res=to_base(n, b);
		int ans=0;
		for(auto& ch:res)ans+=toInt(ch)*toInt(ch);
		cout<<k<<' '<<ans<<'\n';
	}
	return 0;
}

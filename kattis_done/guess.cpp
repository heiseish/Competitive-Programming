/** 
Wherever someone is still thinking of you, that place is your home.
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) (v.begin(),v.end())
#define pb push_back
#define nd second
#define st first

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

const int inf = 1 << 30;
/**
Start coding from here
*/
string ask(int m) {
	string temp;
	cout << m << "\n" << flush;
	cin >> temp;
	return temp;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int l = 0, r = 1001;
	forn(i, 0, 9) {
		int m = ( l + r) >> 1;
		string res = ask(m);
		if (res == "lower") r = m;
		else if (res == "higher")  l = m;
		else exit(0);
	}
	return 0;
}

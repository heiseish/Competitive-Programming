/** 
A detective who uses his deductive powers to corner a suspect, and then does nothing to stop them from committing suicide, is no better than the murderer himself.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl
#define rsa(x, y) memset(x, y, sizeof x);

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

bool isVowel(char ch) {
	return ch == 'a' || ch == 'e' || ch == 'o'
		|| ch == 'u' || ch == 'i';
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string n;
	getline(cin, n);
	int ct = 0;
	for (auto &ch : n) {
		if (ct) ct--;
		else {
			if (isVowel(ch)) ct = 2;
			cout << ch;
		}
		
	}
	cout << '\n';
	return 0;
}

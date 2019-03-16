/** 
Sometimes you must hurt in order to know,fall in order to grow,lose in order to gain because life’s greatest lessons are learned through pain.
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
bool eval(string n, bool p, bool q, bool r, bool s, bool t) {
	stack<bool> v;
	int cur = n.length() - 1;
	while (cur >= 0) {
		char to = n[cur--];
		if (to == 'p') v.push(p);
		else if (to == 'q') v.push(q);
		else if (to == 'r') v.push(r);
		else if (to == 's') v.push(s);
		else if (to == 't') v.push(t);
		else if (to == 'K') {
			bool a = v.top();v.pop();
			bool b = v.top();v.pop();
			v.push(a && b);
		} else if (to == 'A') {
			bool a = v.top();v.pop();
			bool b = v.top();v.pop();
			v.push(a || b);
		} else if (to == 'N') {
			bool a = v.top();v.pop();
			v.push(!a);
		} else if (to == 'C') {
			bool a = v.top();v.pop();
			bool b = v.top();v.pop();
			v.push(!a || b);
		} else if (to == 'E') {
			bool a = v.top();v.pop();
			bool b = v.top();v.pop();
			v.push(!(a ^ b));
		}
	}
	// cout << v.top() << endl;
	return v.top();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string n;
	while(cin >> n && n != "0") {
		bool can = true;
		forn(p, 0, 1) {
			if (!can) break;
			forn(q, 0, 1) {
				if (!can) break;
				forn(r, 0, 1) {
					if (!can) break;
					forn(s, 0, 1) {
						if (!can) break;
						forn(t, 0, 1) {
							can &= eval(n, p, q, r, s, t);
							if (!can) break;
						}
					}
				}
			}
		}
		if (!can) printf("not\n");
		else printf("tautology\n");

	}
	return 0;
}

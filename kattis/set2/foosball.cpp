/** 
it is foolish to fear what we have to see and know”        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl
#define kakimasu(x) cout << x << '\n'
#define sz(x) (int)x.size()
#define UNIQUE(v) (v).resize(unique(all(v)) - (v).begin())
//need to sort first b4 using unique

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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	vector<string> names(n);
	forn(i, 0, n-1) cin >> names[i];
	string e;
	cin>>e;
	queue<int> q;
	forn(i, 4, n - 1) q.push(i);
	vpi ans;
	int best = 0;
	int curww = 0, curbw = 0;
	int wo = 0, wd = 2, bo = 1, bd = 3;
	bool wof = true, bof = true;
	for (auto &v : e) {
		if (v == 'W') {
			swap(wo, wd);
			wof = !wof;

			swap(bo, bd);
			int next = q.front();
			q.pop();
			q.push(bo);
			bo = next;
			bof = false;

			curww++;
			curbw=0;
			if (curww > best) {
				ans.clear();
				best = curww;
			}
			if (curww == best) {
				if (wof) ans.pb({wo, wd});
				else ans.pb({ wd, wo });
			}
		} else {
			swap(bo, bd);
			bof = !bof;

			swap(wo, wd);
			int next = q.front();
			q.pop();
			q.push(wo);
			wo = next;
			wof = false;

			curbw++;
			curww=0;
			if (curbw > best) {
				ans.clear();
				best = curbw;
			}
			if (curbw == best) {
				if (bof) ans.pb({bo, bd});
				else ans.pb({ bd, bo });
			}
		}
	}
	for (auto &p : ans) {
		cout << names[p.st] << ' ' << names[p.nd] <<'\n';
	}
	return 0;
}

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
int n;
unordered_map<string, vector<string> > g;
unordered_map<string, bool> e;
vector<string> res, fin;
void dfs(string st, string en) {
	e[st] = true;
	res.pb(st);
	if (st == en) {
		fin = res;
		return;
	}
	for (auto i : g[st]) {
		if (!e[i]) dfs(i, en);
	}
	res.pop_back();
}
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	// fflush(stdin);
	cin.ignore();
	forn(i, 1, n) {
		string input;
		getline(cin, input);
		stringstream ss(input);
		string cur, next;
		ss >> cur;
		e[cur] = false;
		while(ss >> next) {
			g[cur].pb(next);
			g[next].pb(cur);
			e[next] = false;
		}
	}
	string start, end;
	cin >> start >> end;
	dfs(start, end);
	if (fin.empty()) printf("no route found\n");
	else {
		forn(i, 0, (int) fin.size() - 1) 
			if (i != fin.size() - 1)
				printf("%s ", fin[i].c_str());
			else
				printf("%s\n", fin[i].c_str());
	}
	return 0;
}

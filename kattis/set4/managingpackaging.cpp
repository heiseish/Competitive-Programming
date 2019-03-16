/** 
Three times now… We’ve fought world wars for our own nations, our own villages. We’ve hurt one another. We’ve hated one another. That hatred bred a lust for power, and that lust for power created ME. I was a Jinchuuriki, the embodiment of hatred and power. And I hated this world, and all the people in it… I wanted to destroy it with my own hands. The exact same thing Akatsuki is trying to do today. But one man, one ninja from Konoha stopped me. I was his enemy, yet he wept for me! I hurt him, yet he called me his friend! He saved me! My enemy, my fellow Jinchuuriki… He suffered the same pain as me, yet bore no ill will! There are no enemies here because we’ve all suffered at Akatsuki’s hand! SO THERE IS NO SAND, NO STONE, NO LEAF, NO MIST, NO CLOUD! THERE ARE ONLY SHINOBI! And if you still hold a grudge against the Sand, then when this war is over, come and take my head instead! Our enemies are after the friend who saved my life! If they take him, if we hand him over, our world is finished! I want to protect him, and I want to protect our world! But I’m too young to protect it all on my own! All of you lend me your aid!        
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
	while(cin >> n && n) {
		int ct = 0;
		unordered_map<int, vi> g;
		vi a(n, 0);
		unordered_map<string, int> sti;
		unordered_map<int, string> its;
		cin.ignore();
		forn(i, 1, n) {
			string s;
			getline(cin, s);
			string d;
			stringstream ss(s);
			ss >> d;
			int idx;
			if (!sti.count(d)) {
				sti[d] = ct;
				its[ct] = d;
				idx = ct++;
			} else idx = sti[d];
			while(ss >> d) {
				int dep;
				if (!sti.count(d)) {
					sti[d] = ct;
					its[ct] = d;
					dep = ct++;
				} else dep = sti[d];
				g[dep].pb(idx);
				a[idx]++;
			}
		}
		priority_queue<string, vector<string>, greater<string> > q;
		forn(i, 0, n-1) {
			if (!a[i]) q.push(its[i]);
		}
		vector<string> ans;
		vi vis(n, 0);
		while(!q.empty()) {
			string t = q.top();
			vis[sti[t]]++;
			q.pop();
			ans.pb(t);
			for (auto &s : g[sti[t]]) {
				if (vis[s]) continue;
				a[s]--;
				if (a[s] == 0) q.push(its[s]);
			}
		}
		if (sz(ans) != n) cout << "cannot be ordered\n";
		else {
			for (auto s : ans) cout << s << '\n';	
			cout << '\n';
		}
	}
	return 0;
}

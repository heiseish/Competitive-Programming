/** 
Regardless of our limitations, we can always be of some use. Our power may seem insignificant… but it may just prove to be useful in the grand scheme of things. Stay focused. Never avert your eyes, because if an opening arises, even our insignificant power may be enough to determine the fate of the world.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define sz(x) (int)x.size()
#define UNIQUE(v) (v).resize(unique(all(v)) - (v).begin())
#define mp make_pair
#define debug(x) cout<<#x<<" --> "<<x<<endl;

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const int INF = 1 << 30;
/**
Start coding from here
*/
double dist(pair<double, double>& f, pair<double, double>& s) {
	return sqrt(pow(f.st - s.st, 2) + pow(f.nd - s.nd, 2));
}

double g[105][105];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	unordered_map<string, int> sti;
	vector<string> its(n+1);
	string s;
	double x, y;
	vector<pair<double, double> > d(n+1);
	forn(i,1,n) {
		cin>>s>>x>>y;
		sti[s]=i;
		its[i] = s;
		d[i]={x, y};
	}
	forn(i,1,n) forn(j,1,n) g[i][j] = dist(d[i], d[j]);
	int home = sti["home"];
	int work = sti["work"];
	cin.ignore();
	string t;
	while(getline(cin, t)) {
		stringstream ss(t);
		vi p;
		string l;
		while(ss >> l) p.pb(sti[l]);
		sort(all(p));
		int ans[13];
		double best = 1.0 * INF;
		do {
			double cur=0.0; 
			int last = -1;
			forn(i,0,sz(p)-1) {
				if (last == -1) cur+=g[work][p[i]];
				else cur+=g[last][p[i]];
				last = p[i];
			}
			cur += g[last][home];
			if (cur < best) {
				best = cur;
				forn(i,0,sz(p)-1) ans[i] = p[i];
			}
		} while(next_permutation(all(p)));
		forn(i,0,sz(p)-1)cout << its[ans[i]] <<' ';
		cout << '\n';
	}
	return 0;
}

/** 
People become stronger because they have things they cannot forget. That’s what you call growth.        
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
	unordered_map<string, double> zz;
	zz["UTC"]=0;
	zz["GMT"]=0;
	zz["BST"]=1;
	zz["IST"]=1;
	zz["WET"]=0;
	zz["WEST"]=1;
	zz["CET"]=1;
	zz["CEST"]=2;
	zz["EET"]=2;
	zz["EEST"]=3;
	zz["MSK"]=3;
	zz["MSD"]=4;
	zz["AST"]=-4;
	zz["ADT"]=-3;
	zz["NST"]=-3.5;
	zz["NDT"]=-2.5;
	zz["EST"]=-5;
	zz["EDT"]=-4;
	zz["CST"]=-6;
	zz["CDT"]=-5;
	zz["MST"]=-7;
	zz["MDT"]=-6;
	zz["PST"]=-8;
	zz["PDT"]=-7;
	zz["HST"]=-10;
	zz["AKST"]=-9;
	zz["AKDT"]=-8;
	zz["AEST"]=10;
	zz["AEDT"]=11;
	zz["ACST"]=9.5;
	zz["ACDT"]=10.5;
	zz["AWST"]=8;
	for (auto &v : zz) v.nd*=60;
	int tc;
	cin>>tc;
	while(tc--) {
		int rl;
		string t;
		cin>>t;
		if (t == "noon") rl=12*60;
		else if (t=="midnight") rl=0;
		else {
			int hour=stoi(t.substr(0, t.find(":")));
			int min=stoi(t.substr(t.find(":") + 1));
			rl = hour * 60 + min;
			string m;
			cin>>m;
			if (m=="p.m." && hour<12) rl+=12*60;
			if (m=="a.m." && hour==12) rl = min;
		}
		string f, s;
		cin>>f>>s;
		int diff = zz[s]-zz[f];
		// debug(rl);
		rl+=diff;
		// debug(rl);
		if (rl < 0) rl += 60 * 24;
		else if (rl >=60 * 24) rl-=60 * 24;

		if (rl==0) cout << "midnight\n";
		else if (rl == 60*12) cout << "noon\n";
		else {
			bool aftn=rl>60*12;
			if (aftn) rl-=60*12;
			int hour=(int) floor(rl/60);
			int min=rl%60;
			if (hour==0) hour=12;
			cout << hour << ":" << setfill('0') << setw(2) << min;
			if (aftn) cout << " p.m.\n";
			else cout << " a.m.\n";
		}
	}
	return 0;
}

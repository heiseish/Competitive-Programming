/** 
How often have I said to you that when you have eliminated the impossible, whatever remains, however improbable, must be the truth?        
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
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	vi oR, xoR, anD;
	char ch;
	int t;
	forn(i,0,n-1) {
		cin>>ch>>t;
		if(ch=='|')  oR.pb(t);
		else if(ch=='&') anD.pb(t);
		else xoR.pb(t);
	}
	int can = 0;
	int orans = (oR.empty() ? -1 : oR.front());
	for(auto & v : oR) orans |= v;
	if(orans!=-1) can++;
	int andans = (anD.empty() ? -1 : anD.front());
	for(auto & v : anD) andans &= v;
	if(andans!=-1) can++;
	int xorans = (xoR.empty() ? -1 : xoR.front());
	forn(i,1,sz(xoR)-1) xorans ^= xoR[i];
	if(xorans!=-1) can++;
	cout<<can<<'\n';
	if(andans!=-1) cout<<"& " << andans<<'\n';
	if(orans!=-1) cout<<"| " << orans<<'\n';
	if(xorans!=-1) cout<<"^ " << xorans<<'\n';
	return 0;
}

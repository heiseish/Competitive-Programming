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
#define sseuda(x) cout << x
#define sz(x) (int)x.size()

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

struct Per {
	ll u,r,t;
};
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	vpi ti(10);
	forn(i,0,9) cin>>ti[i].st>>ti[i].nd;
	vector<Per> p(10);
	forn(i,0,9) cin>>p[i].u>>p[i].r>>p[i].t;
	ll cur=0L;
	forn(i,0,2) {
		forn(n,0,9) {
			Per& now=p[n];
			ll temp=now.t;
			ll cycle;
			if (temp>cur) cycle=0;
			else cycle=(ll) floor(1.0* abs(cur-temp)/ (now.u+now.r));
			temp+=cycle*(now.u+now.r);
			// while(temp+now.u+now.r<=cur) temp+=now.u+now.r;
			ll offset=cur-temp;
			if(offset<0) {
				cur+=ti[n].st;
				now.t=max(temp, cur);
				cur+=ti[n].nd;
			} else if (offset==0) {
				cur+=now.u;
				ll n1=cur;
				cur+=ti[n].st;
				now.t=max(n1+now.r, cur);
				cur+=ti[n].nd;
			} else {
				ll start=max(temp+now.u, cur);
				cur=start+ti[n].st;
				now.t=max(cur, temp+now.u+now.r);
				cur+=ti[n].nd;
			}
		}
	}
	cout<<cur-ti[9].nd<<'\n';
	return 0;
}

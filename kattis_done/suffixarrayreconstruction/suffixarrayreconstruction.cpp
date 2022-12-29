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
	int tc;
	cin >> tc;
	while(tc--) {
		int l, s;
		cin >> l >> s;
		vector<char> words(l, '*');
		bool can = true;
		forn(i, 0, s - 1) {
			int idx;
			string suf;
			cin >> idx >> suf;
			int start = idx - 1;
			int cur = 0;
			while(suf[cur] != '*' && cur < suf.length()) {
				if (words[start] == '*') words[start] = suf[cur];
				else if (words[start] != suf[cur]) can = false;
				start++;
				cur++;
			}
			if (cur < suf.length()) {
				int last = l - 1;
				int lastcur = suf.length() - 1;
				while(suf[lastcur] != '*') {
					if (words[last] == '*') words[last] = suf[lastcur];
					else if (words[last] != suf[lastcur]) can = false;
					last--;
					lastcur--;
				}
			}
		}
		for (auto &v : words) if (v == '*') can = false;
		if (!can) cout << "IMPOSSIBLE";
		else for (auto &v : words) cout << v;
		cout << '\n';
	}
	return 0;
}

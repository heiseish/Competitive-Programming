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
const int maxn =5;
char key[maxn][maxn];
void pprint(string s, unordered_map<char, pi>& h) {
	if (s == "XX") cout<<"YY";
	else if (h[s[0]].st != h[s[1]].st && h[s[0]].nd != h[s[1]].nd) {
		cout << key[h[s[0]].st][h[s[1]].nd] << key[h[s[1]].st][h[s[0]].nd];
	} else if (h[s[0]].st == h[s[1]].st) {
		cout << key[h[s[0]].st][(h[s[0]].nd + 1)%5] << key[h[s[1]].st][(h[s[1]].nd + 1)%5];
	} else if (h[s[0]].nd == h[s[1]].nd) {
		cout << key[(h[s[0]].st + 1)%5][h[s[0]].nd] << key[(h[s[1]].st + 1)%5][h[s[1]].nd];
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n;
	string k;
	while(cin>>n, n) {
		cin.ignore();
		getline(cin, k);
		int l = sz(k);
		int curidx = 0;
		int alpha=0;
		unordered_map<char, int> g;
		forn(i, 0, 4) forn(j,0,4) {
			if (curidx<l) {
				char next = toupper(k[curidx]);
				if (next=='J') next = 'I';
				while(curidx < l && (g[next] || k[curidx]==' ')) {
					curidx++;
					if (curidx<l) {
						next = toupper(k[curidx]);
						if (next=='J') next = 'I';
					}
				}
				if (curidx<l) {
					g[next]++;
					key[i][j]=next;
					curidx++;
					continue;
				}
			} 
			while(g['A'+alpha] || alpha==9) alpha++; 
			key[i][j]='A'+alpha++;
			g[key[i][j]]++;
		}
		//keep track of row and col idx for fast searching
		unordered_map<char, pi> h;
		forn(i, 0, 4) {
			forn(j,0,4) {
				// cout<<key[i][j]<<' ';
				h[key[i][j]] = {i, j};
			}
			// cout<<'\n';
		}

		while(n--){
			string t;
			getline(cin, t);
			string pp="";
			for (auto &ch : t) {
				if (ch==' ') continue;
				char next = toupper(ch);
				if (next=='J') next='I';
				if (pp =="") pp+=next;
				else {
					if (next==pp[0]) {
						pprint(pp + 'X', h);
						pp=next;
					} else {
						pprint(pp + next, h);
						pp="";
					}
				}
			}
			if (sz(pp) >0) pprint(pp + 'X', h);
			cout<<'\n';
		}
		cout<<'\n';
	}
	return 0;
}

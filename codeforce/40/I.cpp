/** 
The truth. It is a beautiful and terrible thing, and should therefore be treated with caution.        
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

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}
const int maxn = 125007;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	string s, t;
	cin>>s>>t;
	int ls=sz(s), lt=sz(t);
	vector<vi> in(6), to(6);
	forn(i, 1, ls) {
		if (i <= lt) in[t[i-1] - 'a'].pb(i);
		to[s[i-1]-'a'].pb(i);
	}
	vi cc(ls + 1, 0);
	
	forn(i, 0, 5) {
		vi a(ls + 1, 0), b(ls + 1, 0);
		for(auto &v : in[i]) {
			a[v] = 1;
		}

		for(auto &v : to[i]) {
			b[ls + 1 - v] = 1;
		}
		vi c = multiply(a, b);

		
		for(int k=min(ls+1, sz(c)-1); k >= 2;k--) {
			cc[ls+1-k] += c[k];
		}
	}
	vi numlet(ls-lt+1, 0);
	unordered_map<char, int> track, trackt;
	forn(i, 0, lt-1) {
		track[s[i]]++;
		trackt[t[i]]++;
	}
	int numlett = sz(trackt);
	numlet[0]=sz(track);
	forn(i, lt, ls-1) {
		track[s[i - lt]]--;
		track[s[i]]++;
		int ini=0;
		for(auto &v : track) 
			if (v.nd!=0) ini++;
		numlet[i-lt+1]=ini;
	}
	forn(i, 0, ls-lt) {
		debug(i);
		debug(max(numlet[i], numlett));
		debug(cc[i]);
		cout <<  max(numlet[i], numlett) -cc[i] <<'\n';
	}
	return 0;
}

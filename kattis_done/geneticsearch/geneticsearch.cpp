/** 
If it’s an important memory, then you shouldn't forget it. Since those who aren't with us only live on in our memories.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl
#define rsa(x, y) memset(x, y, sizeof x);

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
const int MAX_N = 110;

char T[MAX_N], P[MAX_N]; // T = text, P = pattern
int b[MAX_N], n, m; // b = back table, n = length of T, m = length of P


void kmpPreprocess() { // call this before calling kmpSearch()
  int i = 0, j = -1; b[0] = -1; // starting values
  while (i < m) { // pre-process the pattern string P
    while (j >= 0 && P[i] != P[j]) j = b[j]; // if different, reset j using b
    i++; j++; // if same, advance both pointers
    b[i] = j; // observe i = 8, 9, 10, 11, 12 with j = 0, 1, 2, 3, 4
} }           // in the example of P = "SEVENTY SEVEN" above

int kmpSearch() { // this is similar as kmpPreprocess(), but on string T
  int i = 0, j = 0, ans = 0; // starting values
  while (i < n) { // search through string T
    while (j >= 0 && T[i] != P[j]) j = b[j]; // if different, reset j using b
    i++; j++; // if same, advance both pointers
    if (j == m) { // a match found when j == m
      ans++;
      j = b[j]; // prepare j for the next possible match
} } 
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string S, L;
	vector<char> syms{'A', 'C', 'G', 'T'};
	while(true) {
		cin >> S;
		if (S == "0") break;
		cin >> L;
		n = L.length();

		m = S.length();
		strcpy(P, S.c_str());
		strcpy(T, L.c_str());
		kmpPreprocess();
		int ans1 = kmpSearch();
		

		unordered_map<string, int> t1, t2;
		forn(i, 0, S.length() - 1) {
			auto temp = S;
			temp.erase(temp.begin() + i);
			t1[temp]++;
		}

		int ans2 = 0;
		m--;
		for (auto &subs : t1) {
			strcpy(P, subs.st.c_str());
			strcpy(T, L.c_str());
			kmpPreprocess();
			ans2 += kmpSearch();
		}

		m+=2;
		int ans3 = 0;
		forn(i, 0, S.length() - 1) {
			for (auto &ch : syms) {
				auto temp = S;
				temp.insert(temp.begin() + i, ch);
				t2[temp]++;
			}
		}
		for (auto &ch : syms) {
			auto temp = S;
			t2[temp + ch]++;
		}
		for (auto &subs : t2) {
			strcpy(P, subs.st.c_str());
			strcpy(T, L.c_str());
			kmpPreprocess();
			ans3 += kmpSearch();
		}
		cout << ans1 << ' ' << ans2 << ' ' << ans3 << '\n';
	}
	return 0;
}

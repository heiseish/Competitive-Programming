/** 
Wherever someone is still thinking of you, that place is your home.        
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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	// freopen("input.txt", "r", stdin);
	unordered_map<int, string> commands;
	unordered_map<int, int> next;
	unordered_map<char, int> variables;
	forn(i, 0, 26) {
		char nt = 'A' + i;
		variables[nt] = 0;
	}
	vi labels;
	string input;
	while(getline(cin,input)) {
		stringstream ss(input);
		int label;
		ss>>label;
		labels.pb(label);
		commands[label] = input.substr(input.find(" ")+1);
		if (cin.eof()) break;
		
	}
	sort(all(labels));
	forn(i, 0, sz(labels)-2) next[labels[i]] = labels[i+1];
	int cur = labels[0];

	while(true) {
		string here = commands[cur];
		stringstream ss(here);
		string cmd;
		ss>>cmd;
		if (cmd == "LET") {
			char varName;
			ss>>varName>>cmd;
			vector<string> wtf;
			while(ss>>cmd) wtf.pb(cmd);
			if (sz(wtf)==1) {
				if (isdigit(wtf[0].back())) variables[varName] = stoi(wtf[0]);
				else variables[varName] = variables[wtf[0][0]];
			} else {
				int X, Y;
				string op = wtf[1];
				string x=wtf[0], y = wtf[2];
				if (isdigit(x.back())) X=stoi(x);
				else X = variables[x[0]];

				if (isdigit(y.back())) Y=stoi(y);
				else Y = variables[y[0]];

				if(op=="+") {
					variables[varName] = X + Y;
				} else if (op=="-")
					variables[varName] = X - Y;
				else if (op=="/")
					variables[varName] = X / Y;
				else 
					variables[varName] = X * Y;
			}
			
		} else if (cmd == "PRINT" || cmd == "PRINTLN") {
			string topr;
			if (cmd == "PRINT") topr = here.substr(here.find("PRINT ") + 6);
			else topr = here.substr(here.find("PRINTLN ") + 8);

			if (sz(topr) == 1) {
				cout << variables[topr.back()];
			} else {
				cout << topr.substr(1, sz(topr)-2);
			}
			if (cmd=="PRINTLN") cout <<"\n";
		} else if (cmd == "IF") {
			string x, y;
			int X, Y;
			string op;
			ss>>x>>op>>y;
			if (isdigit(x.back())) X = stoi(x);
			else X = variables[x.back()];

			if (isdigit(y.back())) Y = stoi(y);
			else Y = variables[y.back()];

			bool ans;
			if (op=="=") ans=X==Y;
			else if(op==">") ans=X>Y;
			else if(op=="<") ans=X<Y;
			else if(op=="<>") ans=X!=Y;
			else if (op=="<=") ans=X<=Y;
			else if (op==">=") ans=X>=Y;
			string trash;
			ss>>trash;
			ss>>trash;
			int nxt;
			ss>>nxt;
			if (ans) {
				cur = nxt;
				continue;
			} 
		}
		if (!next[cur]) break;
		else cur = next[cur];
	}
	return 0;
}

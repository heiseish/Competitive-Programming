#include <bits/stdc++.h>
using namespace std;
#define forn(i,a,b) for(int i = a; i < b;i++)
typedef pair<int, int> ii;
vector<string> m;
int n;
int main() {
	int  k;
	cin >> n >> k;


	vector<vector<int> > dp(n, vector<int>(n, 0));
	for (int i = 0; i < n;i++) {
		string t;
		cin >> t;
		m.push_back(t);
	}
	int curmax = -1, curdpMax = -1;;
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n;j++) {
			int curdp = m[i][j]== 'a' ? 0 : 1; 
			if (i == 0 && j == 0) dp[i][j] = curdp;
			else if ( i > 0 && j == 0) dp[i][j] = dp[i-1][j] + curdp;
			else if ( i == 0 && j > 0) dp[i][j] = dp[i][j-1] + curdp;
			else dp[i][j] = min({ dp[i-1][j], dp[i][j-1] }) + curdp;
			if (i + j >= curmax && dp[i][j] <= k) {
				curmax = i + j;
				curdpMax = dp[i][j];
			}
		}
	}
	string res = string(curmax + 1, 'a');
	vector<ii> isp;
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n;j++) {
			if (i + j  == curmax && dp[i][j] == curdpMax) isp.push_back({i , j});
		}
	}
	dp.clear();
	if (curmax == -1) {
		isp.push_back({0 , 0});
		res = m[0][0];
	}
	while(isp[0].first + isp[0].second != 2 * n - 2) {
		char curbest = 'z';
		set<ii> re;
		for (auto t : isp) {
			int first = t.first;
			int second = t.second;
			if (first < n - 1) {
				if (m[first + 1][second] == curbest && re.find({first + 1, second}) == re.end()) re.insert({first + 1, second});
				else if (m[first+1][second] < curbest) {
					re.clear();
					curbest = m[first+1][second];
					re.insert({first+1, second});
				}
			}
			if (second < n - 1) {
				if (m[first][second + 1] == curbest && re.find({first, second + 1}) == re.end()) re.insert({first, second + 1});
				else if (m[first][second + 1] < curbest) {
					re.clear();
					curbest = m[first][second + 1];
					re.insert({first, second+1});
				}
			}
		}
		res += curbest;
		// for (auto i : result) cout << i.first << " " << i.second << endl;
		// cout << endl;
		isp.clear();
		for (auto i : re) isp.push_back(i);
	}
	
	
	cout << res << endl;
	return 0;
}
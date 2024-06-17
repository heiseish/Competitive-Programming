#include <bits/stdc++.h>
using namespace std;
vector<vector<bool> > vi;
int n, m;
int r, c;
vector<string> ma;
struct Node {
	int x, y, rx, ry;
};

int main() {
	
	scanf("%d %d", &n, &m);
	
	scanf("%d %d", &r, &c);
	r--;
	c--;
	int x, y;
	scanf("%d %d", &x, &y);
	
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		ma.push_back(temp);
		vector<bool> tarr(m, false);
		vi.push_back(tarr);
	}
	
	int ans = 0;
	deque<Node> q;
	q.push_back({ r, c, x, y});
	while(!q.empty()) {
		Node np = q.front();
		q.pop_front();
		if (ma[np.x][np.y] == '*' || vi[np.x][np.y]) continue;
		vi[np.x][np.y] = true;
		ans++;
		if (np.x > 0) q.push_front({np.x - 1, np.y, np.rx, np.ry});
		if (np.x < n - 1)  q.push_front({np.x + 1, np.y, np.rx, np.ry});
		if (np.y > 0 && np.rx)  q.push_back({np.x, np.y - 1, np.rx - 1, np.ry});
		if (np.y < m - 1 && np.ry)  q.push_back({np.x, np.y + 1, np.rx, np.ry - 1});
		
	}
	cout << ans << endl;
	return 0;
}
/** 
Regardless of our limitations, we can always be of some use. Our power may seem insignificant… but it may just prove to be useful in the grand scheme of things. Stay focused. Never avert your eyes, because if an opening arises, even our insignificant power may be enough to determine the fate of the world.
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) (v.begin(),v.end())
#define pb push_back
#define nd second
#define st first

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

const int inf = 1 << 30;
/**
Start coding from here
*/

struct Node {
	int value;
	Node* left;
	Node* right;
};

Node* insert(Node* cur, int a) {
	if (!cur) cur = new Node({ a, nullptr, nullptr});
	else if (cur->value <= a) {
		Node* res = insert(cur->right, a);
		cur->right = res;
	}
	else {
		Node* res = insert(cur->left, a);
		cur->left = res;
	}
	return cur;
}

bool compareTree(Node* lhs, Node* rhs) {
	if (lhs == nullptr && rhs == nullptr) return true;
	if (lhs == nullptr && rhs != nullptr) return false;
	if (lhs != nullptr && rhs == nullptr) return false;
	return compareTree(lhs->left, rhs->left) && compareTree(lhs->right, rhs->right);
}

int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k;
	scanf("%d %d", &n, &k);
	vector<Node* > g(n);
	forn(i, 0, n - 1) {
		forn(j, 0, k - 1) {
			int temp;
			scanf("%d", &temp);
			g[i] = insert(g[i], temp);
		}
	}
	vector<bool> grouped(n, false);
	int ct = n;
	forn(i, 0, n - 1) {
		if (grouped[i]) continue;
		for(int j = i + 1; j <= n - 1; j++) {
			if (grouped[j]) continue;
			if (compareTree(g[i], g[j])) {
				grouped[i] = true;
				grouped[j] = true;
				ct--;
			}
		}
	}
	printf("%d\n", ct);
	return 0;
}

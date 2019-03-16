/** 
A detective who uses his deductive powers to corner a suspect, and then does nothing to stop them from committing suicide, is no better than the murderer himself.        
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
	int p;
	int n1,n5,n10,n25;
	cin>>p;
	cin>>n1>>n5>>n10>>n25;
	int a[4];
	int initial = p;
	int cantake25 = min(p /25, n25);
	a[3] = cantake25;
	n25 -= cantake25;
	p-=cantake25;

	int cantake10 = min(p /10, n10);
	a[2] = cantake10;
	n10 -= cantake10;
	p-=cantake10;
	
	int cantake5 = min(p /5, n5);
	a[1] = cantake5;
	n5 -= cantake5;
	p-=cantake5;


	int cantake1 = min(p, n1);
	a[0] = cantake1;
	n1 -= cantake1;
	p-=cantake1;

	if (p > 0) {
		cout << "Impossible\n";
		return 0;
	}

	while(a[3] > 0 && n5 >= 3 && n10 >= 1) {
		a[3]--;
		n5-=3;
		n10--;
	}

	while(a[3] > 0 && n5 >= 1 && n10 >= 2) {
		a[3]--;
		n5--;
		n10-=2;
	}

	while(a[2] > 0 && n5 >= 2) {
		a[2]--;
	}
	return 0;
}

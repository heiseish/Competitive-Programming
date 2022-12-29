/** 
Words are like swords. If you use them the wrong way, they can turn into ugly weapons.        
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
const int maxn = 103;
vector<string> m(101);
int w, h;
int dir[8]{ 1, 0, 0, 1, -1, 0, 0, -1};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    #ifdef LOCAL_PROJECT
        freopen("input.txt","r",stdin);
    #endif
    int tc;
    cin>>tc;
    while(tc--) {
        cin>>h>>w;
        forn(i,0,h-1) cin>>m[i];

		vector<vi> o(h, vi(w, INF));
		vector<vi> f(h, vi(w, INF));
		vector<vi> s(h, vi(w, INF));

        deque<pair<pi, int> > qo, qf, qs;
        forn(i,0,h-1) {
            if (m[i][0] == '#') qo.pb({{i, 0}, 1});
            if (m[i][w-1] == '#') qo.pb({{i, w-1}, 1});
            if (m[i][w-1] == '.' || m[i][w-1] == '$') qo.push_front({{i, w-1}, 0});
            if (m[i][0] == '.' || m[i][0] == '$') qo.push_front({{i, 0}, 0});
        }
        forn(i,0,w-1) {
            if (m[0][i] == '#') qo.pb({{0, i}, 1});
            if (m[h-1][i] == '#') qo.pb({{h-1, i}, 1});
            if (m[h-1][i] == '.' || m[h-1][i] == '$') qo.push_front({{h-1, i}, 0});
            if (m[0][i] == '.' || m[0][i] == '$') qo.push_front({{0, i}, 0});
        }

		while(!qo.empty()) {
			pair<pi, int> fr = qo.front(); qo.pop_front();
			auto x = fr.st.st, y = fr.st.nd;
			if (o[x][y] != INF) continue;
			o[x][y] = fr.nd;
			forn(i,0,3) {
				int newx = x + dir[i * 2];
				int newy = y + dir[i * 2 + 1];
				if (newx < 0 || newx >= h || newy < 0 || newy >= w || o[newx][newy] != INF) continue;
				if (m[newx][newy] == '#') qo.pb({{newx, newy}, fr.nd + 1});
				if (m[newx][newy] == '.' || m[newx][newy] == '$') qo.push_front({{newx, newy}, fr.nd});
			}
		}

        int ct=1;

        forn(i,0,h-1) forn(j,0,w-1) {
            if (m[i][j] == '$' && ct==1) {
                qf.pb({{i, j}, 0});
                ct++;
            } else if (m[i][j] == '$' && ct==2) {
                 qs.pb({{i, j}, 0});
            }
        }

		while(!qf.empty()) {
			pair<pi, int> fr = qf.front(); qf.pop_front();
			auto x = fr.st.st, y = fr.st.nd;
			if (f[x][y] != INF) continue;
			f[x][y] = fr.nd;
			forn(i,0,3) {
				int newx = x + dir[i * 2];
				int newy = y + dir[i * 2 + 1];
				if (newx < 0 || newx >= h || newy < 0 || newy >= w || f[newx][newy] != INF) continue;
				if (m[newx][newy] == '#') qf.pb({{newx, newy}, fr.nd + 1});
				if (m[newx][newy] == '.' || m[newx][newy] == '$') qf.push_front({{newx, newy}, fr.nd});
			}
		}

		while(!qs.empty()) {
			pair<pi, int> fr = qs.front(); qs.pop_front();
			auto x = fr.st.st, y = fr.st.nd;
			if (s[x][y] != INF) continue;
			s[x][y] = fr.nd;
			forn(i,0,3) {
				int newx = x + dir[i * 2];
				int newy = y + dir[i * 2 + 1];
				if (newx < 0 || newx >= h || newy < 0 || newy >= w || s[newx][newy] != INF) continue;
				if (m[newx][newy] == '#') qs.pb({{newx, newy}, fr.nd + 1});
				if (m[newx][newy] == '.' || m[newx][newy] == '$') qs.push_front({{newx, newy}, fr.nd});
			}
		}


        int ans=INF;
        forn(i,0,h-1) forn(j,0,w-1) {
            if(o[i][j] == INF || f[i][j] == INF || s[i][j] == INF) continue;
            if (m[i][j] == '#') ans=min(ans, o[i][j] + f[i][j] + s[i][j] - 2);
            else ans=min(ans, o[i][j] + f[i][j] + s[i][j]);
        }
        cout << ans <<'\n';

    }
    return 0;
}
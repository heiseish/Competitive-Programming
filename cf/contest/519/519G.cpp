#include <bits/stdc++.h>

using namespace std;

const int BIG = 1e9 + 239;
const int M = 2 * 1e5 + 239;
const int L = 19;
const int A = 30;
const int T = (1 << 19);
const int two = 2;

int flm[two][M];

inline void z_function(string &s, int c)
{
	int n = s.length();
	flm[c][0] = 0;
	int l = 0;
	int r = 0;
	for (int i = 1; i < n; i++)
	{
		flm[c][i] = min(flm[c][i - l], r - i);
		if (flm[c][i] < 0) flm[c][i] = 0;
		while (i + flm[c][i] < n && s[flm[c][i]] == s[i + flm[c][i]]) flm[c][i]++;
		if (i + flm[c][i] > r)
		{
			l = i;
			r = i + flm[c][i];
		}
	}        
}

int a[M], lcp[M], pos[M];

inline void suffix_array(string s)
{
	s += (char)(31);
	int n = s.length();
	vector<pair<char, int> > v;
	for (int i = 0; i < n; i++)
		v.push_back(make_pair(s[i], i));
	sort(v.begin(), v.end());
	vector<pair<int, int> > num;
	int last = 0;
	for (int i = 0; i < n - 1; i++)
	{
		num.push_back(make_pair(last, v[i].second));
		if (v[i].first != v[i + 1].first) last++;
	}
	num.push_back(make_pair(last, v.back().second));
	vector<int> u(n);
	for (int i = 0; i < n; i++) u[num[i].second] = num[i].first;
	int d = 1;
	vector<pair<pair<int, int>, int> > t;
	vector<vector<pair<int, int> > > h;
	while (d < n)
	{
		t.clear();
		h.clear();
		h.resize(n);
		for (int i = 0; i < n; i++)
		{
			int l = num[i].second - d;
			if (l < 0) l += n;
			h[u[l]].push_back(make_pair(num[i].first, l));
		}
		for (int i = 0; i < n; i++)
			for (pair<int, int> r : h[i])
				t.push_back(make_pair(make_pair(i, r.first), r.second));
		last = 0;
		num.clear();
		for (int i = 0; i < n - 1; i++)
		{
			num.push_back(make_pair(last, t[i].second));
			if (t[i].first != t[i + 1].first) last++;
		}
		num.push_back(make_pair(last, t.back().second));
		for (int i = 0; i < n; i++) u[num[i].second] = num[i].first;
		d <<= 1;
	}                           
	for (int i = 1; i < n; i++) a[i - 1] = num[i].second;
}

string s;                 

inline void kasai()
{
	int n = s.size();
	suffix_array(s); 
	for (int i = 0; i < n; i++)
		pos[a[i]] = i;
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (pos[i] == n - 1) continue;
		while (s[i + k] == s[a[pos[i] + 1] + k] && a[pos[i] + 1] + k < n && i + k < n) k++;
		lcp[pos[i]] = k;
		k = max(0, k - 1);
	}
}

int n, lw[M], rw[M]; 
string prr, rvl;                     
vector<int> open_l[M], close_l[M];   
vector<int> open_r[M], close_r[M];
multiset<int> nw;

inline void func(int l, int r)
{
	if (r - l == 1) return;
	int mid = (l + r) >> 1;
	func(l, mid);
	func(mid, r);
	rvl = "";
	for (int i = mid - 1; i >= l; i--) rvl += s[i];
	z_function(rvl, 0);
	prr = "";
	for (int i = mid; i < r; i++) prr += s[i];
	prr += '#';
	for (int i = l; i < mid; i++) prr += s[i];
	z_function(prr, 1);	
	for (int c = l; c < mid; c++)
	{
		int k1 = 0;
		if (c > l) k1 = flm[0][mid - c];
		int k2 = flm[1][r - mid + 1 + c - l];
		int len = mid - c;
		int lg = max(len - k2, 0);
		int rg = min(len - 1, k1);
		if (rg >= lg)
		{
			open_l[c - rg].push_back((2 * len));
			close_l[c - lg].push_back((2 * len));
			open_r[c - rg + 2 * len - 1].push_back((2 * len));
			close_r[c - lg + 2 * len - 1].push_back((2 * len));
		}	
	}
	rvl = "";
	for (int i = mid; i < r; i++) rvl += s[i];
	z_function(rvl, 0);
	prr = "";
	for (int i = mid - 1; i >= l; i--) prr += s[i];
	prr += '#';
	for (int i = r - 1; i >= mid; i--) prr += s[i];
	z_function(prr, 1); 
	for (int c = mid; c < r; c++)
	{
		int k1 = 0;
		if (c != r - 1) k1 = flm[0][c + 1 - mid];
		int k2 = flm[1][r - c + mid - l];
		int len = c - mid + 1;
		int lg = max(len - k2, 0);
		int rg = min(len - 1, k1);
		if (rg >= lg)
		{                                            
			open_l[c + lg - 2 * len + 1].push_back((2 * len));
			close_l[c + rg - 2 * len + 1].push_back((2 * len));
			open_r[c + lg].push_back((2 * len));
			close_r[c + rg].push_back((2 * len));
		}	
	}
	for (int i = l; i < r; i++)
	{
		for (int len : open_l[i]) nw.insert(len);
		if (!nw.empty()) lw[i] = min(lw[i], *nw.begin());
		for (int len : close_l[i]) nw.erase(nw.lower_bound(len));
		open_l[i].clear();
		close_l[i].clear();
	}          
	for (int i = l; i < r; i++)
	{
		for (int len : open_r[i]) nw.insert(len);
		if (!nw.empty()) rw[i] = min(rw[i], *nw.begin());
		for (int len : close_r[i]) nw.erase(nw.lower_bound(len));
		open_r[i].clear();
		close_r[i].clear();
	}
}

int mn[L][M], st2[M], lc[L][M], kol[A][M];

inline int getmin(int l, int r)
{
	int u = st2[r - l + 1];
	return min(mn[u][l], mn[u][r - (1 << u) + 1]);
}

inline int gett(int l, int r)
{
	if (l == r) return (n - l);
	l = pos[l];
	r = pos[r];
	if (l > r) swap(l, r);
	r--;
	int u = st2[r - l + 1];
	return min(lc[u][l], lc[u][r - (1 << u) + 1]);
}

int q, la[M], ra[M], has[M], mnp[M];

inline void init()
{
	for (int i = 0; i < n; i++) mn[0][i] = lw[i];
	for (int i = 0; i < n - 1; i++) lc[0][i] = lcp[i];
	for (int i = 1; i < L; i++)
		for (int j = 0; j < n; j++)
		{
			int r = (j + (1 << (i - 1)));
			if (r >= n)
			{
				mn[i][j] = mn[i - 1][j];
				continue;
			}
			mn[i][j] = min(mn[i - 1][j], mn[i - 1][r]);
		}
	for (int i = 1; i < L; i++)
		for (int j = 0; j < n - 1; j++)
		{
			int r = (j + (1 << (i - 1)));
			if (r >= n - 1)
			{
				lc[i][j] = lc[i - 1][j];
				continue;
			}                                          
			lc[i][j] = min(lc[i - 1][j], lc[i - 1][r]);
		}	
	st2[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		st2[i] = st2[i - 1];
		if ((1 << (st2[i] + 1)) <= i) st2[i]++;
	}	
}

int in[L][M], gl[T];

inline void build(int i, int l, int r)
{
	if (i == 0) gl[i] = 0;
	else gl[i] = gl[(i - 1) / 2] + 1;
	if (r - l == 1)
	{
		in[gl[i]][l] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(2 * i + 1, l, mid);
	build(2 * i + 2, mid, r);
	merge(in[gl[i] + 1] + l, in[gl[i] + 1] + mid, in[gl[i] + 1] + mid, in[gl[i] + 1] + r, in[gl[i]] + l);
}

inline bool is_on(int i, int l, int r, int ql, int qr, int xl, int xr)
{
	if (r <= ql || qr <= l) return false;
	if (ql <= l && r <= qr)
	{
		int it = upper_bound(in[gl[i]] + l, in[gl[i]] + r, xl) - in[gl[i]] - l;
		if (it == r - l) return false;
		return (in[gl[i]][it + l] <= xr);	
	}
	int mid = (l + r) >> 1;
	if (is_on(2 * i + 1, l, mid, ql, qr, xl, xr)) return true;
	return is_on(2 * i + 2, mid, r, ql, qr, xl, xr);
}

inline bool check_all(int l, int r)
{
	int len = (r - l + 1);
	int pl = pos[l];
	int lf = pl;
	int rf = n;
	while (rf - lf > 1)
	{
		int h = (lf + rf) / 2;
		if (gett(a[h], l) >= len) lf = h;
		else rf = h;
	}
	int rg = lf + 1;
	lf = -1;
	rf = pl;
	while (rf - lf > 1)
	{
		int h = (lf + rf) / 2;
		if (gett(a[h], l) >= len) rf = h;
		else lf = h;
	}
	int lg = rf;
	return is_on(0, 0, n, lg, rg, l, r);
}

int par[M];
set<int> cmp[M];
set<pair<int, int> > sc[M];
vector<int> ok[M];
vector<pair<int, int> > mg[M];

inline void border_check()
{
	for (int i = 0; i < q; i++) has[i] = false;
	for (int i = 0; i < q; i++) ok[ra[i] - la[i]].push_back(i);
	for (int i = 0; i < n - 1; i++) mg[lcp[i]].push_back(make_pair(a[i], a[i + 1]));
	for (int i = 0; i < n; i++)
	{
		par[i] = i;
		cmp[i].insert(i);
	}
	for (int c = n; c >= 1; c--)
	{
		for (int i : ok[c - 1])
			sc[par[la[i]]].insert(make_pair(ra[i], i));   
		for (pair<int, int> t : mg[c])
		{
			int l = par[t.first];
			int r = par[t.second];
			if (cmp[l].size() > cmp[r].size()) swap(l, r);
			for (int x : cmp[l])
				while (true)
				{
					auto it = sc[r].lower_bound(make_pair(x, 0));
					if (it == sc[r].end() || it->first > x + c - 1) break;
					has[it->second] = true;
					sc[r].erase(it);
				}
			for (pair<int, int> u : sc[l])
			{
				int id = u.second;
				auto uk = cmp[r].lower_bound(ra[id] - c + 1);
				if (uk != cmp[r].end() && (*uk) <= ra[id]) 
					has[id] = true;
				else 
				    sc[r].insert(u);
			}
			for (int x : cmp[l])
			{
				par[x] = r;
				cmp[r].insert(x);
			}
		}		
	}	
    for (int i = 0; i < q; i++)
	    if (!has[i] && check_all(la[i], ra[i]))
		{
			has[i] = true;
			continue;
		}
}

inline bool checkno(int l, int r)
{
	if (r - l + 1 > 26) return false;
	vector<int> kol(26, 0);
	for (int x = l; x <= r; x++)
	{
		if (kol[s[x] - 'a'] > 0) return false;
		kol[s[x] - 'a']++;
	}	
	return true;
}

inline bool try_kol(int l, int r, int p)
{
	int len = (r - l + 1) / p;
	return (gett(l, l + len) >= (r - l + 1 - len));
}

inline bool ison(int l, int r, char x)
{
	return (kol[x - 'a'][r + 1] > kol[x - 'a'][l]);	
}

inline int query(int l, int r, int id)
{         
	if (checkno(l, r)) return -1;
	int len = (r - l + 1);
	while (len > 1)
	{
		int p = mnp[len];
		if (try_kol(l, r, p)) return 1;
		while ((len % p) == 0) len /= p;
	}
	if (lw[l] <= r) return 2;
	if (rw[r] >= l) return 2;
	if (has[id]) return 2;
	if (ison(l + 1, r, s[l])) return 3;
	if (ison(l, r - 1, s[r])) return 3;
	if (getmin(l, r) <= r) return 3;	
	return 4;
}

int main()
{
	cin.sync_with_stdio(0); 
	cin >> n >> s;
	memset(mnp, -1, sizeof(mnp));
	for (int i = 2; i <= n; i++)
		if (mnp[i] == -1)
			for (int j = i; j <= n; j += i)
				if (mnp[j] == -1)
					mnp[j] = i;
	memset(kol[0], 0, sizeof(kol[0]));
	for (int i = 0; i < n; i++)
	{
		for (int x = 0; x < 26; x++) kol[x][i + 1] = kol[x][i];
		kol[s[i] - 'a'][i + 1]++;
	}
	for (int i = 0; i < n; i++)
	{
		lw[i] = n + 1;
		rw[i] = n + 1;
	}
	func(0, n);  
	for (int i = 0; i < n; i++)
	{
		if (lw[i] == n + 1) lw[i] = n;
		else lw[i] += (i - 1);  
		if (rw[i] == n + 1) rw[i] = -1;
		else rw[i] = (i - rw[i] + 1);
	}
	kasai();                                                                        
	init();  
	build(0, 0, n);                                                                       
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> la[i] >> ra[i];
		la[i]--, ra[i]--;                       
	}
	border_check();
	for (int i = 0; i < q; i++) cout << query(la[i], ra[i], i) << "\n";
	return 0;
}
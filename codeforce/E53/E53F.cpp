#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

const int N = 200000;
int n;
vector<int> g[N];
int par[N];
int cnt[N];
bool lit[N];
int dist[N];
vector<pair<int, int>> box[N];

int ansl;
int ansu;
int ansv;

void dfs(int u, int p) {
  par[u] = p;
  for (int v : g[u]) if (v != p) {
    cnt[u]++;
    dfs(v, u);
  }
}

void dfs2(int u, int p) {
  for (int v : g[u]) if (v != p && !lit[v]) {
    dist[v] = dist[u] + 1;
    dfs2(v, u);
  }
}

void dfs3(int u, int p, int d) {
  if (d == 0) {
    int l = box[u][0].first + box[u][1].first;
    if (ansl < l) {
      ansl = l;
      ansu = box[u][0].second;
      ansv = box[u][1].second;
    }
    return;
  }
  for (int v : g[u]) if (v != p && !lit[v]) {
    dfs3(v, u, d - 1);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int r = 0;
  for (int i = 0; i < n; i++) {
    if (g[i].size() >= 3) {
      r = i;
    }
  }
  dfs(r, -1);
  for (int i = 0; i < n; i++) {
    if (cnt[i] == 0) {
      lit[i] = true;
      int k = par[i];
      int len = 1;
      while (cnt[k] == 1) {
        len++;
        lit[k] = true;
        k = par[k];
      }
      box[k].emplace_back(len, i);
    }
  }
  for (int i = 0; i < n; i++) {
    sort(box[i].rbegin(), box[i].rend());
  }
  dfs2(r, -1);
  int u = max_element(dist, dist + n) - dist;
  dist[u] = 0;
  dfs2(u, -1);
  vector<int> du(dist, dist + n);
  int v = max_element(dist, dist + n) - dist;
  dist[v] = 0;
  dfs2(v, -1);
  vector<int> dv(dist, dist + n);

  int D = dv[u];

  int cu, cv;
  for (int i = 0; i < n; i++) {
    if (du[i] == D / 2 && dv[i] == (D + 1) / 2) {
      cu = i;
    }
   if (du[i] == (D + 1) / 2 && dv[i] == D / 2) {
      cv = i;
    }
  }
  if (u == v) {
    cerr << "A" << endl;
    printf("%d %d\n", box[u][0].second + 1, box[u][1].second + 1);
    printf("%d %d\n", box[u][2].second + 1, box[u][3].second + 1);
  } else if (cu == cv) {
    cerr << "B" << endl;
    vector<tuple<int, int, int>> a;
    for (int v : g[cu]) if (!lit[v]) {
      ansl = 0;
      dfs3(v, cu, D / 2 - 1);
      if (ansl > 0) {
        a.emplace_back(ansl, ansu, ansv);
      }
    }
    sort(a.rbegin(), a.rend());
    printf("%d %d\n", get<1>(a[0]) + 1, get<1>(a[1]) + 1);
    printf("%d %d\n", get<2>(a[0]) + 1, get<2>(a[1]) + 1);
  } else {
    cerr << "C" << endl;
    vector<tuple<int, int, int>> a;
    {
      ansl = 0;
      dfs3(cu, cv, (D - 1) / 2);
      a.emplace_back(ansl, ansu, ansv);
    }
    {
      ansl = 0;
      dfs3(cv, cu, (D - 1) / 2);
      a.emplace_back(ansl, ansu, ansv);
    }
    sort(a.rbegin(), a.rend());
    printf("%d %d\n", get<1>(a[0]) + 1, get<1>(a[1]) + 1);
    printf("%d %d\n", get<2>(a[0]) + 1, get<2>(a[1]) + 1);
  }
}
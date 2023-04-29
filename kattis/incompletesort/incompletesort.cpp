/**
If comrades that you trust gather around you, hope can take physical form and
become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;
/**
(▀̿Ĺ̯▀̿ ̿) (ง ͠° ͟ل͜ ͡°)ง
*/
const int N = 1e5 + 7;
int a[N];
int idx[N];

auto main() -> int {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (auto i = 1; i <= n; ++i) {
    cin >> a[i];
    idx[a[i]] = i;
  }
  cout << 3 << '\n';

  unordered_set<int> cur;
  auto temp = n;
  for (auto i = 1; i <= n / 4; ++i)
    cur.insert(i);
  for (auto i = 1; i <= n / 4; ++i) {
    auto j = idx[i];
    if (cur.find(j) != cur.end()) {
      while (cur.find(temp) != cur.end())
        temp--;
      cur.insert(temp);
    } else {
      cur.insert(j);
    }
  }
  vector<int> pos, val;
  pos.reserve(n / 2);
  val.reserve(n / 2);
  for (auto &v : cur) {
    cout << v << ' ';
    pos.push_back(v);
    val.push_back(a[v]);
  }
  sort(pos.begin(), pos.end());
  sort(val.begin(), val.end());

  for (auto j = 0; j < n / 2; ++j) {
    a[pos[j]] = val[j];
    idx[val[j]] = pos[j];
    // cout << "assigning " << val[j] << " to " << pos[j] << endl;
  }

  cout << '\n';
  cur.clear();

  temp = n;
  for (auto i = n / 4 + 1; i <= n / 2; ++i)
    cur.insert(i);
  for (auto i = n / 4 + 1; i <= n / 2; ++i) {
    auto j = idx[i];
    if ((cur.find(j) != cur.end())) {
      while (cur.find(temp) != cur.end())
        temp--;
      cur.insert(temp);
    } else {
      cur.insert(j);
    }
  }
  for (auto &v : cur)
    cout << v << ' ';
  cout << '\n';

  for (auto i = n / 2 + 1; i <= n; ++i)
    cout << i << ' ';
  cout << '\n';

  return 0;
}

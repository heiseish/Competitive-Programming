/**
If comrades that you trust gather around you, hope can take physical form and
become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;
/**
(▀̿Ĺ̯▀̿ ̿) (ง ͠° ͟ل͜ ͡°)ง
*/
auto main() -> int {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int32_t c, e, m;
  cin >> c >> e >> m;
  if (c != 4) {
    cout << "impossible\n";
    return 0;
  }
  if (m == 0) {
    if (e % 2 != 0) {
      cout << "impossible\n";
    } else {
      cout << "2 " << e / 2 + 2 << '\n';
    }
    return 0;
  }
  for (int i = 1; i <= (int)ceil(sqrt(m)); ++i) {
    if (m % i == 0) {
      int other = m / i;
      if (2 * (other + i) == e) {
        cout << i + 2 << ' ' << other + 2 << '\n';
        return 0;
      }
    }
  }
  cout << "impossible\n";
  return 0;
}

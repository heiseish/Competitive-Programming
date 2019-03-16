#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

const int mod = 998244353;

struct mint {
  int n;
  mint(int n_ = 0) : n(n_) {}
};

mint operator+(mint a, mint b) { return (a.n += b.n) >= mod ? a.n - mod : a.n; }
mint operator-(mint a, mint b) { return (a.n -= b.n) < 0 ? a.n + mod : a.n; }
mint operator*(mint a, mint b) { return 1LL * a.n * b.n % mod; }
mint &operator+=(mint &a, mint b) { return a = a + b; }
mint &operator-=(mint &a, mint b) { return a = a - b; }
mint &operator*=(mint &a, mint b) { return a = a * b; }
ostream &operator<<(ostream &o, mint a) { return o << a.n; }

mint dp[20][2][2][2][1 << 10];
mint dp2[20][2][2][2][1 << 10];

int popcnt(int n) {
  int res = 0;
  while (n > 0) {
    res++;
    n &= n - 1;
  }
  return res;
}

int main() {
  string L, R;
  int K;
  cin >> L >> R >> K;
  while (L.size() < R.size()) L = '0' + L;
  while (L.size() > R.size()) R = '0' + R;
  int n = L.size();
  dp[0][0][0][0][0] = 1;
  dp2[0][0][0][0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        for (int l = 0; l < 2; l++) {
          for (int m = 0; m < 1 << 10; m++) {
            int x = j ? 0 : L[i] - '0';
            int y = k ? 9 : R[i] - '0';
            for (int d = x; d <= y; d++) {
              int mm = l == 0 && d == 0 ? 0 : (m | 1 << d);
              dp[i + 1][j || d > x][k || d < y][l || d != 0][mm] += dp[i][j][k][l][m];
              dp2[i + 1][j || d > x][k || d < y][l || d != 0][mm] += dp2[i][j][k][l][m] * 10 + dp[i][j][k][l][m] * d;
            }
          }
        }
      }
    }
  }
  mint ans;
  for (int j = 0; j < 2; j++) {
    for (int k = 0; k < 2; k++) {
      for (int m = 0; m < 1 << 10; m++) {
        if (popcnt(m) <= K) {
          ans += dp2[n][j][k][1][m];
        }
      }
    }
  }
  cout << ans << endl;
}
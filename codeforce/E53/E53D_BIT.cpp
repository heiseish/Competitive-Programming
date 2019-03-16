#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct BIT {
  vector<long long> dat;

  BIT(int n) : dat(n + 1) {}

  void update(int k, long long v) {
    for (int i = k + 1; i < dat.size(); i += i & -i) {
      dat[i] += v;
    }
  }
  
  long long query(int k) {
    long long ans = 0;
    for (int i = k; i > 0; i -= i & -i) {
      ans += dat[i];
    }
    return ans;
  }

  long long query(int l, int r) {
    return query(r) - query(l);
  }
};

int main() {
  int n;
  long long T;
  cin >> n >> T;
  BIT bit0(n * 2);
  BIT bit1(n * 2);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    bit0.update(i, 1);
    bit0.update(i + n, 1);
    bit1.update(i, a[i]);
    bit1.update(i + n, a[i]);
  }
  int k = 0;
  long long ans = 0;
  int left = n;
  while (left > 0) {
    long long s = bit1.query(k, k + n);
    if (s > T) {
      int l = k;
      int r = k + n;
      while (r - l > 1) {
        int m = (l + r) / 2;
        if (bit1.query(k, m) <= T) {
          l = m;
        } else {
          r = m;
        }
      }
      ans += bit0.query(k, l);
      T -= bit1.query(k, l);
      k = l % n;
      bit0.update(k, -1);
      bit0.update(k + n, -1);
      bit1.update(k, -a[k]);
      bit1.update(k + n, -a[k]);
      left--;
    } else {
      ans += (T / s) * bit0.query(k, k + n);
      T %= s;
    }
  }
  cout << ans << endl;
}
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 131072;
int N;
long long a[MAXN];
long long k[MAXN];
long long v1[MAXN];
set<int> v1_nonzero;

long long segsum[2*MAXN]; // v[a]
long long segnsum[2*MAXN]; // a*v[a];
long long getv(long long* seg, int a, int b) {
  a += MAXN; b += MAXN;
  long long ans = 0;
  while(a<=b) {
    if(a%2 == 1) ans += seg[a++];
    if(b%2 == 0) ans += seg[b--];
    a /= 2; b /= 2;
  }
  return ans;
}
void setv(long long* seg, int a, long long v) {
  a += MAXN;
  seg[a] += v;
  while((a=a/2))
    seg[a] = seg[a*2]+seg[a*2+1];
}
long long SUM(int l, int r) {
  long long ar = getv(segsum, 0, r-1);
  long long al = getv(segsum, 0, l-1);
  return r*ar-getv(segnsum, l, r-1)-(l-1)*al;
}
void SET(int a, long long v) {
  setv(segsum, a, v);
  setv(segnsum, a, a*v);
}
void ADD(int id, long long x) {
  // no x = 0;
  if(x == 0) return;
  // v1[id-1] inc, v1[id] dec
  v1[id-1] += x; v1_nonzero.insert(id-1); SET(id-1, x);
  v1[id] -= x; SET(id, -x);
  if(v1[id] > 0)
    return;
  if(v1[id] == 0) {
    v1_nonzero.erase(id); return;
  }
  long long remain = -v1[id];
  SET(id, -v1[id]); v1[id] = 0;
  v1_nonzero.erase(id);
  auto it = v1_nonzero.lower_bound(id);
  while(remain > 0 && it != v1_nonzero.end()) {
    long long v = min(remain, v1[*it]);
    remain -= v; v1[*it] -= v; SET(*it, -v);
    if(v1[*it] == 0)
      v1_nonzero.erase(it++);
  }
  return;
}
int main() {
  scanf("%d", &N);
  for(int i=1; i<=N; ++i)
    scanf("%lld", a+i);
  for(int i=1; i<=N-1; ++i)
    scanf("%lld", k+i);
  for(int i=0; i<=N-1; ++i)
  {
    v1[i] = a[i+1]-a[i]-k[i];
    SET(i, a[i+1]-a[i]);
    if(v1[i] != 0)
      v1_nonzero.insert(i);
  }
  int Q; scanf("%d", &Q);
  while(Q--) {
    char c; int a, b; scanf(" %c%d%d", &c, &a, &b);
    if(c == 's')
      printf("%lld\n", SUM(a, b));
    else
      ADD(a, b);
  }
}
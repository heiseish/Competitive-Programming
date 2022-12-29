#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
    ll x;
    cin >> x;
    ll count=0;
    ll cur = 1L;
    for (ll k=2;k * cur <=x;k++) {
        if (x%k ==0) {
            cur *= k;
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl
#define rsa(x, y) memset(x, y, sizeof x);

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<long long> vll;
typedef vector<vector<int> > vvi;
typedef vector<vll> vvll;
typedef vector<pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const int INF = 1 << 30;
/**
Start coding from here
*/
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N;
    cin >> N;
    vector<string> t(2 * N - 2);
    vector<string> lgst;
    forn(i, 0, 2 * N - 3) { 
        cin >> t[i];
        if (t[i].length() == N - 1) lgst.pb(t[i]);
    }
    bool firstone = true;
    forn(i, 1, N - 2) {
        if (lgst[0][i] != lgst[1][i-1]) {
            firstone = false;
            break;
        }
    }
    string maxpre = firstone ? lgst[0] : lgst[1];
    string maxsuf = firstone? lgst[1] : lgst[0];
    char P[207];
    int it = 0;
    int ctp = 0, cts = 0;
    unordered_map<string, int> track;
    bool can = true;
    for (auto &v : t) {
        bool pre = true;
        forn(i, 0, v.length() - 1) {
            if (v[i] != maxpre[i]) {
                pre = false;
                break;
            }
        }
        bool suf = true;
        forn(i, 0, v.length() - 1) {
            if (v[v.length() - 1 - i] != maxsuf[maxsuf.length() - 1- i]) {
                suf = false;
                break;
            }
        }
        if (pre && !suf) {
            P[it++]='P';
            ctp++;
            track[v]++;
        } else if (!pre && suf)  {
            P[it++] ='S';
            cts++;
        } else if (!pre && !suf)
            can = false;
        else P[it++] = '*';
    }
    if (!can) {
        swap(maxpre, maxsuf);
        it = 0;
        ctp = 0, cts = 0;
        track.clear();
        bool can = true;
        for (auto &v : t) {
            bool pre = true;
            forn(i, 0, v.length() - 1) {
                if (v[i] != maxpre[i]) {
                    pre = false;
                    break;
                }
            }
            bool suf = true;
            forn(i, 0, v.length() - 1) {
                if (v[v.length() - 1 - i] != maxsuf[maxsuf.length() - 1- i]) {
                    suf = false;
                    break;
                }
            }
            if (pre && !suf) {
                P[it++]='P';
                ctp++;
                track[v]++;
            } else if (!pre && suf)  {
                P[it++] ='S';
                cts++;
            } else if (!pre && !suf)
                can = false;
            else P[it++] = '*';
        }
    }
    forn(i, 0, 2 * N - 3) {
        if (P[i] != '*') cout << P[i];
        else if (ctp < N - 1 && !track[t[i]]) {
            cout << 'P';
            ctp++;
            track[t[i]]++;
        } else cout << 'S';
    }
    cout << '\n';

    return 0;
}
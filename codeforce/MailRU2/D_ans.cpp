#include <bits/stdc++.h>
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

const int MAXN = 6228;

string s[MAXN];
string t[MAXN];
int l[MAXN];
int r[MAXN];

void nein() {
    cout << "NO\n";
    exit(0);
}

int z[MAXN];

int check(const string& text, const string& pat) {
    string s = text + '#' + pat + '*';
    z[0] = 0;
    int l = 0, r = 0;
    for (int i = 1; i < s.length(); ++i) {
        int k = 0;
        if (r > i) {
            k = min(r - i, z[i - l]);
        }

        while (s[k] == s[i + k]) {
            ++k;
        }

        if (k >= text.length()) {
            return i - text.length() - 1;
        }

        if (i + k > r) {
            l = i;
            r = i + k;
        }

        z[i] = k;
    }

    return -1;
}

int main() {
#ifdef BZ
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);
    int n;
    cin >> n;

    string cs;
    string ct;

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> t[i];
        int l = -1, r = -1;

        for (int j = 0; j < s[i].length(); ++j) {
            if (s[i][j] != t[i][j]) {
                r = j;
                if (l == -1) {
                    l = j;
                }
            }
        }

        if (l != -1) {
            ++r;
            string ns = s[i].substr(l, r - l);
            string nt = t[i].substr(l, r - l);
            if (!cs.empty() && (cs != ns || ct != nt)) {
                nein();
            }

            cs = ns;
            ct = nt;
        }

        ::l[i] = l;
        ::r[i] = r;
    }

    for (int j = 1;;++j) {
        bool bad = false;
        char cl = '-';

        for (int i = 0; i < n; ++i) {
            if (l[i] == -1) {
                continue;
            }

            if (l[i] == 0) {
                bad = true;
                continue;
            }

            char ch = s[i][l[i] - 1];
            if (cl != '-' && cl != ch) {
                bad = true;
            }

            cl = ch;
        }

        if (!bad) {
            for (int i = 0; i < n; ++i) {
                if (l[i] != -1) {
                    --l[i];
                }
            }

            cs = cl + cs;
            ct = cl + ct;
        } else {
            break;
        }
    }

    for (int j = 0;;++j) {
        bool bad = false;
        char cl = '-';

        for (int i = 0; i < n; ++i) {
            if (r[i] == -1) {
                continue;
            }

            if (r[i] + j == s[i].length()) {
                bad = true;
                continue;
            }

            char ch = s[i][r[i] + j];
            if (cl != '-' && cl != ch) {
                bad = true;
            }

            cl = ch;
        }

        if (!bad) {
            cs += cl;
            ct += cl;
        } else {
            break;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (check(cs, s[i]) != l[i]) {
            nein();
        }
    }

    cout << "YES\n" << cs << "\n" << ct << "\n";
}
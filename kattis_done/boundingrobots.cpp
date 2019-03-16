#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int main() {
	int w,l;
	while(scanf("%d %d",&w, &l), w || l) {
		int n;cin >> n;
		ii rb{0, 0}, re{0,0};
		while(n--) {
			char d;
			int dis;
			cin >> d >> dis;
			switch(d) {
				case 'u':
				rb.second += dis;
				if (re.second + dis < l - 1) re.second += dis;
				else re.second = l-1;
				break;

				case 'l':
				rb.first -= dis;
				if (re.first - dis > 0) re.first -= dis;
				else re.first = 0;
				break;

				case 'd':
				rb.second -= dis;
				if (re.second - dis > 0) re.second -= dis;
				else re.second = 0;
				break;

				case 'r':
				rb.first += dis;
				if (re.first + dis < w - 1) re.first += dis;
				else re.first = w-1;
				break;

			}
		}
		cout << "Robot thinks " << rb.first << " " << rb.second << endl;
		cout << "Actually at " << re.first << " " << re.second << endl << endl;
	}
	return 0;
}
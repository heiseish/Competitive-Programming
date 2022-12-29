#include <bits/stdc++.h>
using namespace std;
typedef unordered_map<string, int> um;
int main() {
	int w, n, cloud = 0;
	while ( cin >> w >> n, w || n) {
		cloud++;
		um dict;
		vector<string> words;
		int curM = 0;
		while(n--) {
			string temp;
			int f;
			cin >> temp >> f;
			words.push_back(temp);
			dict[temp] = f;
			if (f > curM) curM = f;
		}
		int curWid = w;
		int curH = 0, maxH = 0;
		for (auto i : words) {
			int fs = 8 + ceil((40.0 * (dict[i] - 4)) / (curM - 4));
			int ww = ceil(9.0 / 16 * i.length() * fs);
			if (ww <= curWid) {
				if (fs > maxH) maxH = fs;
				curWid-=ww + 10;
			} else {
				curH+=maxH;
				maxH=fs;
				curWid=w-ww-10;
			}
		}
		curH += maxH;
		cout << "CLOUD " << cloud << ": " << curH << endl;
	}
	return 0;
}
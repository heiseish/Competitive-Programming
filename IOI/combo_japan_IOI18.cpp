#include <bits/stdc++.h>
#define rl result.length()
using namespace std;
int press(string p) {
	int s;
	cout << "press(" << p << "): ";
	cin >> s;
	return s;
};

int main() {
	int n;
	cout << "Number of sequence to guess: ";
	cin >> n;
	cout << "executing guess_sequence(" << n << ")" << endl;
	vector<string> l;
	l.push_back("A");
	l.push_back("B");
	l.push_back("X");
	l.push_back("Y");
	string result = "";
	//guess first letter
	int tmp = press(l[0] + l[1]);
	if ( tmp >= 1) {
		if (tmp == 2) {
			result+= l[0] + l[1];
			l.erase(l.begin());
		}
		else {
			tmp = press(l[0]);
			if (tmp == 1) {
				result += l[0];
				l.erase(l.begin() + 0);
			} else {
				result += l[1];
				l.erase(l.begin() + 1);
			}
		}
	} else {
		tmp = press(l[2]);
		if (tmp == 1) {
			result += l[2];
			l.erase(l.begin() + 2);
		} else {
			result += l[3];
			l.erase(l.begin() + 3);
		}
	}
	//continue to guess each or two letter until done
	while (rl != n) {
		if (n - rl == 1) {
			tmp = press(result + l[0] + result + l[1]);
			if (tmp == rl) {
				result += l[2];
				break;
			} else {
				tmp = press(result + l[0]);
				if (tmp == rl) {
					result += l[1];
				} else result += l[0];
				break;
			}
		}
		tmp = press(result + l[0] + l[0] + result + l[0] + l[1] + result + l[1] + l[0]);
		if (tmp == rl) {
			result += l[2];
		} else if (tmp == rl + 1) {
			tmp = press(result + l[1] + l[2]);
			if (tmp == rl + 2) {
				result += l[1] + l[2];
			} else if (tmp == rl + 1) {
				result += l[1] + l[1];
			} else {
				result += l[0] + l[2];
			}
		} else if (tmp == rl + 2) {
			tmp = press(result + l[0] + l[0]);
			if (tmp == rl + 2) {
				result += l[0] + l[0];
			} else if (tmp == rl + 1) {
				result += l[0] + l[1];
			} else {
				result += l[1] + l[0];
			}
		}
	}
	cout << "The sequence is " << result << endl;

	return 0;
}
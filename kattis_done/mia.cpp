#include <bits/stdc++.h>
using namespace std;
bool mia(int a, int b) {
	return (a == 1 && b == 2) || (a == 2 && b == 1);
}

bool doubles(int a, int b) {
	return a == b;
}

int create(int a, int b) {
	return (a > b) ? a * 10 + b : b * 10 + a;
}
int main() {
	int s0, s1, r0, r1;
	while(scanf("%d %d %d %d", &s0, &s1, &r0, &r1), s0 || s1 || r0 || r1) {
		if (mia(s0, s1) && !mia(r0, r1)) cout << "Player 1 wins." << endl;
		else if (!mia(s0, s1) && mia(r0, r1)) cout << "Player 2 wins." << endl;
		else if (mia(s0, s1) && mia(r0, r1)) cout << "Tie." << endl;
		else if (doubles(s0, s1) && !doubles(r0, r1)) cout << "Player 1 wins." << endl;
		else if (!doubles(s0, s1) && doubles(r0, r1)) cout << "Player 2 wins." << endl;
		else if (create(s0, s1) > create(r0, r1)) cout << "Player 1 wins." << endl;
		else if (create(s0, s1) < create(r0, r1)) cout << "Player 2 wins." << endl;
		else cout << "Tie." << endl;
	}
	
	return 0;
}
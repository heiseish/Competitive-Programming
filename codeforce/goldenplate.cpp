#include <bits/stdc++.h>
using namespace std;
int main( ) {
	int w, h, k;
	cin >> w >> h >> k;
	int a = w, b = h;
	int glided = 0;
	for (int i = 1; i<= k;i++) {
		a=w - 4 * (i- 1);
		b=h - 4 * (i - 1);
		glided+= (2 * a + 2 * b - 4);
		
	}
	cout << glided << endl;
	return 0;
}
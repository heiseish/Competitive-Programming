#include <bits/stdc++.h>
using namespace std;
int main() {
	time_t rawtime;
	int d, m;
	cin >> d >> m;
	vector<string> dd { "Sunday", "Monday",
                             "Tuesday", "Wednesday",
                             "Thursday", "Friday", "Saturday"};
	struct tm *  t;
	time ( &rawtime );
  	t = localtime ( &rawtime );
	t->tm_year = 2009 - 1900;
  	t->tm_mon = m - 1;
  	t->tm_mday = d;
	mktime(t);
	cout << dd[t->tm_wday] << endl;
	return 0;
}
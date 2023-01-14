#include <bits/stdc++.h>
using namespace std;
int main() {
	int sh, sm, ss, eh, em , es;
	scanf("%d:%d:%d", &sh, &sm, &ss);
	scanf("%d:%d:%d", &eh, &em, &es);
	if (ss > es) {
		em--;
		es+= 60;
	}
	if (sm > em) {
		eh--;
		em+= 60;
	}
	if (sh > eh) {
		eh += 24 - sh;
		sh = 0;
	}
	if (sh == eh && sm == em && ss == es) printf("24:00:00\n");
	else printf("%02d:%02d:%02d\n", (eh - sh), em - sm, es - ss);
	return 0;
}
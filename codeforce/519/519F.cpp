#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 7;
const int MX = 1e9 + 7;

int n;
int cnt[N];
int sil[N];
int odw[N];
int dp[20][N];

int fast(int a, int b){
	int ret = 1;
	while(b){
		if(b & 1)
			ret = (1LL * ret * a)%MX;
		
		b >>= 1;
		a = (1LL * a * a)%MX;
	}
	
	return ret;
}

int newton(int a, int b){
	if(b < 0 || a < b)	return 0;
	return (((1LL * sil[a] * odw[b])%MX) * odw[a - b])%MX;
}

void sub(int &a, int b){
	a -= b;
	if(a < 0)
		a += MX;
}

int main(){
	sil[0] = 1;
	for(int i = 1; i < N; ++i)
		sil[i] = (1LL * sil[i - 1] * i)%MX;
	
	odw[N - 1] = fast(sil[N - 1], MX - 2);
	for(int i = N - 1; i >= 1; --i)
		odw[i - 1] = (1LL * odw[i] * i)%MX;

	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int a;
		scanf("%d", &a);
		cnt[a]++;
	}
	
	for(int i = 1; i < N; ++i)
		for(int j = i + i; j < N; j += i)
			cnt[i] += cnt[j];
	
	for(int i = 1; i < 20; ++i){
		for(int j = N - 1; j >= 1; --j){
			dp[i][j] = newton(cnt[j], i);
			for(int k = j + j; k < N; k += j)
				sub(dp[i][j], dp[i][k]);
		}
		
		if(dp[i][1] > 0){
			printf("%d\n", i);
			return 0;
		}
	}
	
	puts("-1");
	return 0;
}
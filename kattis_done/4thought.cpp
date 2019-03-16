#include <bits/stdc++.h>
using namespace std;

int inf = 1 << 30;
int getNearestFirstOperatant(vector<int>& v, int i) {
	for (int j=i-1; j>= 0; j--){
		if (v[j]==inf) continue;
		else return j;
	}
	return 0;
}
int getNearestSecondOperant(vector<int>& v, int i) {
	for (int j=i+1; j<7; j++){
		if (v[j]==inf) continue;
		else return j;
	}
	return 0;
}
int main() {
	unordered_map<int, string> graph;
	for (int i=0;i<4;i++){
		for (int j=0;j<4;j++){
			for(int z=0;z<4;z++){
				vector<int> tmp(7, 4);
				tmp[1] = i;
				tmp[3] = j;
				tmp[5] = z;
				vector<int> res = tmp;
				string real = "";
				for (int tt = 0;tt<7;tt++) {
					switch(tmp[tt]){
						case 0:
						real+="*";
						break;
						case 1:
						real+="+";
						break;
						case 2:
						real+="-";
						break;
						case 3:
						real+="/";
						break;
						case 4:
						real+="4";
						break;
					}
					real+=" ";

				}
				for (int a = 1; a <= 5; a=a+2) {
					if (tmp[a] == 0) {
						int f = getNearestFirstOperatant(res, a);
						int s = getNearestSecondOperant(res, a);
						res[a] = res[f]*res[s];
						res[f] = inf;
						res[s] = inf;
					}

					if (tmp[a] == 3) {
						int f = getNearestFirstOperatant(res, a);
						int s = getNearestSecondOperant(res, a);
						res[a] = res[f]/res[s];
						res[f] = inf;
						res[s] = inf;
					}
				}

				for (int a = 1; a <= 5; a=a+2) {
					if (tmp[a] == 1) {
						int f = getNearestFirstOperatant(res, a);
						int s = getNearestSecondOperant(res, a);
						res[a] = res[f]+res[s];
						res[f] = inf;
						res[s] = inf;
					}

					if (tmp[a] == 2) {
						int f = getNearestFirstOperatant(res, a);
						int s = getNearestSecondOperant(res, a);
						res[a] = res[f]-res[s];
						res[f] = inf;
						res[s] = inf;
					}
				}
				for (int a = 0; a < 7; a++) {
					if (res[a] != inf) {
						graph[res[a]] = real;
					}
				}
			}
		}
	}
	int n;
	cin >> n;
	
	for (int i =0; i<n;i++) {
		int temp;
		cin >> temp;
		if (graph.find(temp) != graph.end()) cout << graph[temp] << "= " << temp << endl;
		else cout << "no solution" << endl;
	}
	return 0;
}
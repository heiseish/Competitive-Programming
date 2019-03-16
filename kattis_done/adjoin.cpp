#include <bits/stdc++.h>
#define M 100000
using namespace std;

vector<int> groupings(M, -1);
vector<vector<int> > vertices;
unordered_map<int, int> longestPath;

//Breadth-first search: Return the index of the furthest verte away from index
int BFS(int index) {
	unordered_map<int, int> localRecordMap;
	queue<int> q;
	if (longestPath.count(groupings[index]) == 0) longestPath[groupings[index]] = 0;
	localRecordMap[index] = 0;
	q.push(index);
	int max = 0;
	int indexMax = 0;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		for (auto i : vertices[temp]) {
			if (groupings[i] == -1) groupings[i] = groupings[index];
			if (localRecordMap.count(i) == 0) {
				localRecordMap[i] = localRecordMap[temp] + 1;
				if (localRecordMap[i] > max) {
					max = localRecordMap[i];
					indexMax = i;
				}
				q.push(i);
			}
		}
	}
	if (max > longestPath[groupings[index]]) longestPath[groupings[index]] = max;
	return indexMax;
}
int main() {
	int numVer;
	int numEdge;
	cin >> numVer >> numEdge;
	for (int i = 0; i < numVer; i++) {
		vector<int> temp;
		vertices.push_back(temp);
	}
	
	int first, second;
	for (int i = 0; i < numEdge; i++) {
		cin >> first >> second;
		vertices[first].push_back(second);
		vertices[second].push_back(first);
		
	}
	int group = 0;

	//Loop through, group nodes tgt and find max diamater for each group
	for (int index = 0; index < vertices.size(); index++) {
		if (groupings[index] == -1) {
			groupings[index] = group;
			group++;
			//Run BFS twice to get the longest path
			int end = BFS(index);
			BFS(end);
		}	
	}

	//print answer
	if (longestPath.size() == 1) {
		cout << longestPath.begin()->second << endl;
		return 0;
	}
	if (longestPath.size() == 2) {
		vector<int> res;
		for (auto i : longestPath) res.push_back(i.second);
		int path1 = res[0];
		int path2 = res[1];
		int path1Big = res[0] % 2 == 1 ? res[0] / 2 + 1: res[0] / 2;
		int path1Small = res[0] - path1Big;
		int path2Big = res[1] % 2 == 1 ? res[1] / 2 + 1 : res[1] / 2;
		int path2Small = res[1] - path2Big;
		cout << max({path1Big + path1Small, path2Big + path2Small, path1Big + path2Big + 1}) << endl;
		return 0;
	}
	
	int firstMax = 0, nextMax = 0, nextNextMax = 0;
	int maxNum = 0;
	int idx;
	for (auto i : longestPath) {
		if (i.second >= maxNum) {
			maxNum = i.second;
			idx = i.first;
		}
	}
	longestPath.erase(idx);
	firstMax = maxNum;
	maxNum = 0;
	for (auto i : longestPath) {
		if (i.second >= maxNum) {
			maxNum = i.second;
			idx = i.first;
		}
	}
	nextMax = maxNum;
	longestPath.erase(idx);
	maxNum = 0;
	for (auto i : longestPath) {
		if (i.second >= maxNum) {
			maxNum = i.second;
			idx = i.first;
		}
	}
	nextNextMax = maxNum;
	int path1Big = firstMax % 2 == 1 ? firstMax / 2 + 1 : firstMax / 2;
	int path1Small = firstMax - path1Big;
	int path2Big = nextMax % 2 == 1 ? nextMax / 2 + 1 : nextMax / 2;
	int path3Big = nextNextMax % 2 == 1 ? nextNextMax / 2 + 1 : nextNextMax / 2;
	cout << max({path1Big + path1Small, path1Big + path2Big + 1, path2Big + path3Big + 2}) << endl;
	return 0;
}
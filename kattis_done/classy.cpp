#include <iostream>
#include <set>
#include <vector>
#include <stack>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

stack<string> split(const string &s, char delim) {
    stringstream ss(s);
    string item;
    stack<string> tokens;
    while (getline(ss, item, delim)) {
        tokens.push(item);
    }
    return tokens;
}

bool isLowerThan(string s1, string s2) {
	stack<string> temp1 = split(s1, '-');
	stack<string> temp2 = split(s2, '-');
	while (!(temp1.empty() && temp2.empty())) {
		string t1;
		if (temp1.empty()) t1 = "middle";
		else {
			t1 = temp1.top();
			temp1.pop();
		}
		string t2;
		if (temp2.empty()) t2 = "middle";
		else {
			t2 = temp2.top();
			temp2.pop();
		}

		if (t1 == t2) continue;
		else if (t1 == "lower") {
			return true;
		} else if (t1 == "middle") {
			if (t2 == "lower") return false;
			else return true;
		} else return false;

	}
	return false;
}

struct Person {
	string title;
	string classRank;
	bool operator <(const Person & other) const {
		stack<string> temp1 = split(classRank, '-');
		stack<string> temp2 = split(other.classRank, '-');
		while (!(temp1.empty() && temp2.empty())) {
			string t1;
			if (temp1.empty()) t1 = "middle";
			else {
				t1 = temp1.top();
				temp1.pop();
			}
			string t2;
			if (temp2.empty()) t2 = "middle";
			else {
				t2 = temp2.top();
				temp2.pop();
			}

			if (t1 == t2) continue;
			else if (t1 == "lower") {
				return true;
			} else if (t1 == "middle") {
				if (t2 == "lower") return false;
				else return true;
			} else return false;

		}
		return title.compare(other.title) > 0;
	}
};
int main() {
	int numCase;
	int numPeople;
	vector<Person> people;
	string person, rank, useless;
	cin >> numCase;
	for (int i = 0; i < numCase; i++){
		people.clear();
		cin >> numPeople;
		for (int j = 0; j < numPeople; j++) {
			cin >> person >> rank >> useless;
			Person temp = { person.substr(0, person.size()-1), rank };
			people.push_back(temp);
			
		}

		sort(people.begin(), people.end());
		for (int i = people.size() - 1; i >= 0; i--){
			cout << people[i].title << endl;
		}
		cout << "==============================" << endl;
	}
	return 0;
}
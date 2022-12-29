#include <iostream>
#define R 1000
#define C 1000
struct land {
	int value;
	int group;
};

void explore(land arr[][C], int r, int c, int val, int group, int row, int cow);

int main() {
	int r, c, q, j;
	std::string type;
	std::string temp;
	land arr[R][C];
	bool ans;
	int r1, c1, r2, c2;
	std::cin >> r >> c;
	
	for (int i = 0; i < r; i++) {
		std::cin >> temp;
		j = 0;
		for (char& ch : temp) {
			arr[i][j].value = ch - '0';
			arr[i][j].group = 0;
			j++;
		}
	}
	int group = 1;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j].group == 0) {
				explore(arr, i, j, arr[i][j].value, group, r, c);
				group++;
			}
		}
	}
	
	std::cin >> q;
	for (int i = 0; i < q; i++) {
		std::cin >> r1 >> c1 >> r2 >> c2;
		if (arr[r1 - 1][c1 - 1].value != arr[r2 - 1][c2 - 1].value) { 
			std::cout << "neither" << std::endl;
		} else {
			type = arr[r1 - 1][c1 - 1].value == 1 ? "decimal" : "binary";
			if (arr[r1 - 1][c1 - 1].group == arr[r2 - 1][c2 - 1].group) {
				std::cout << type << std::endl;
			} else {
				std::cout << "neither" << std::endl;
			}
		}
	}
	return 0;
}

void explore(land arr[][C], int r, int c,  int val, int group, int row, int col) {
	if (r < 0 
		|| c < 0 
		|| r >= row
		|| c >= col
		|| arr[r][c].group != 0
		|| arr[r][c].value != val) {
		return;
	}
	arr[r][c].group = group;
	explore(arr, r - 1, c, val, group, row, col);
	explore(arr, r + 1, c, val, group, row, col);
	explore(arr, r, c - 1, val, group, row, col);
	explore(arr, r, c + 1, val, group, row, col);
}

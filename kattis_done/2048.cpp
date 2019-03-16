#include <bits/stdc++.h>
#define loopI for (int i = 0; i < 4; i++)
#define loopJ for (int j = 0; j < 4; j++)

using namespace std;
int board[4][4], state[4][4];
void shiftState(int i, int j, int dir) {
	if (dir == 0) {
		if (board[i][j - 1] == 0) {
			board[i][j - 1] = board[i][j];
			board[i][j] = 0;
			state[i][j - 1] = state[i][j];
			state[i][j] = 0;
			return;
		}
		board[i][j - 1] *= 2;
		state[i][j - 1] = 1;
		board[i][j] = 0;
		return;
	}

	if (dir == 1) {
		if (board[i - 1][j] == 0) {
			board[i - 1][j] = board[i][j];
			board[i][j] = 0;
			state[i][j - 1] = state[i][j];
			state[i][j] = 0;
			return;
		}
		board[i - 1][j] *= 2;
		state[i - 1][j] = 1;
		board[i][j] = 0;
		return;
	}

	if (dir == 2) {
		if (board[i][j+1]  == 0) {
			board[i][j+1] = board[i][j];
			board[i][j] = 0;
			state[i][j+1] = state[i][j];
			state[i][j] = 0;
			return;
		}
		board[i][j+1] *= 2;
		state[i][j+1] = 1;
		board[i][j] = 0;
		return;
	}

	if (dir == 3) {
		if (board[i+1][j]  == 0) {
			board[i+1][j] = board[i][j];
			board[i][j] = 0;
			state[i+1][j] = state[i][j];
			state[i][j] = 0;
			return;
		}
		board[i+1][j] *= 2;
		state[i+1][j] = 1;
		board[i][j] = 0;
		return;
	}
}

int main() {
	int direction;
	loopI {
		loopJ {
			cin >> board[i][j];
			state[i][j] = 0;
		}
	}
	cin >> direction;
	if (direction == 0) {
		loopI {
			loopJ {
				if (j == 0 || board[i][j] == 0) continue;
				int current = j;
				while(current - 1 >= 0 && (board[i][current - 1] == 0 || (board[i][current] == board[i][current - 1] 
					&& state[i][current]==0&&state[i][current-1]==0))) {
					shiftState(i, current, direction);
					current--;
				}
			}
		}
	}
	if (direction == 2) {
		loopI {
			for(int j=2;j>=0;j--) {
				if (board[i][j]==0) continue;
				int current = j;
				while(current+1<=3 && (board[i][current+1] == 0 || (board[i][current] == board[i][current+1] 
					&& state[i][current]==0&&state[i][current+1]==0))) {
					shiftState(i, current, direction);
					current++;
				}
			}
		}
	}
	if (direction == 1) {
		for(int i=1;i<4;i++) {
			loopJ {
				if (board[i][j]==0) continue;
				int current = i;
				while(current-1>=0 && (board[current-1][j] == 0 || (board[current][j] == board[current-1][j] 
					&& state[current][j]==0&&state[current-1][j]==0))) {
					shiftState(current, j, direction);
					current--;
				}
			}
		}
	}
	if (direction == 3) {
		for(int i=2;i>=0;i--) {
			loopJ {
				if (board[i][j]==0) continue;
				int current = i;
				while(current+1<=3 && (board[current+1][j] == 0 || (board[current][j] == board[current+1][j] 
					&& state[current][j]==0&&state[current+1][j]==0))) {
					shiftState(current, j, direction);
					current++;
				}
			}
		}
	}
	loopI {
		loopJ {
			if (j != 3) cout << board[i][j] << " ";
			else cout << board[i][j] << endl;
		}
	}
	return 0;
}
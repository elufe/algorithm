#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


int n;
int answer = -1;

void dfs(vector<vector<int>> board, vector<vector<int>> temp, int count) {
	int i, j, check, num, index;
	for (i = 1; i <= n; i++) {
		temp[i] = board[i];
	}

	if (count == 5)
		return;

	//©Л
	

	for (i = 1; i <= n; i++) {
		j = n;
		check = 0;
		num = 0;
		index = n;
		while (j > 0) {
			
			if (board[i][j] == 0) {
				j--;
			}
			else {
				if (check == 0) {
					num = board[i][j];
					board[i][j] = 0;
					check = 1;
				}
				else {
					if (num == board[i][j]) {
						num *= 2;
						if (answer < num) {
							answer = num;
						}
						board[i][j] = 0;
						board[i][index] = num;
						index--;
						check = 0;
						num = 0;
					}
					else {
						board[i][index] = num;
						num = board[i][j];
						board[i][j] = 0;
						index--;						
					}
				}
				j--;
			}
		}
		if (num) {
			board[i][index] = num;
			if (answer < num) {
				answer = num;
			}
		}
	}

	dfs(board, temp, count + 1);

	for (i = 1; i <= n; i++) {
		board[i] = temp[i];
	}
	//аб

	for (i = 1; i <= n; i++) {
		j = 1;
		check = 0;
		num = 0;
		index = 1;
		while (j < n+1) {
			
			if (board[i][j] == 0) {
				j++;
			}
			else {
				if (check == 0) {
					num = board[i][j];
					board[i][j] = 0;
					check = 1;
				}
				else {
					if (num == board[i][j]) {
						num *= 2;
						if (answer < num) {
							answer = num;
						}
						board[i][j] = 0;
						board[i][index] = num;
						index++;
						check = 0;
						num = 0;
					}
					else {
						board[i][index] = num;
						num = board[i][j];
						board[i][j] = 0;
						index++;
					}
				}
				j++;
			}
		}
		if (num) {
			board[i][index] = num;
			if (answer < num) {
				answer = num;
			}
		}
	}

	dfs(board, temp, count + 1);

	for (i = 1; i <= n; i++) {
		board[i] = temp[i];
	}

	//го

	for (j = 1; j <= n; j++) {
		i = n;
		check = 0;
		num = 0;
		index = n;
		while (i > 0) {
			
			if (board[i][j] == 0) {
				i--;
			}
			else {
				if (check == 0) {
					num = board[i][j];
					board[i][j] = 0;
					check = 1;
				}
				else {
					if (num == board[i][j]) {
						num *= 2;
						if (answer < num) {
							answer = num;
						}
						board[i][j] = 0;
						board[index][j] = num;
						index--;
						check = 0;
						num = 0;
					}
					else {
						board[index][j] = num;
						num = board[i][j];
						board[i][j] = 0;
						index--;
					}
				}
				i--;
			}
		}
		if (num) {
			board[index][j] = num;
			if (answer < num) {
				answer = num;
			}
		}
	}

	dfs(board, temp, count + 1);

	for (i = 1; i <= n; i++) {
		board[i] = temp[i];
	}

	//╩С

	for (j = 1; j <= n; j++) {
		
		i = 1;
		check = 0;
		num = 0;
		index = 1;
		while (i < n+1) {
			
			if (board[i][j] == 0) {
				i++;
			}
			else {
				if (check == 0) {
					num = board[i][j];
					board[i][j] = 0;
					check = 1;
				}
				else {
					if (num == board[i][j]) {
						num *= 2;
						if (answer < num) {
							answer = num;
						}
						board[i][j] = 0;
						board[index][j] = num;
						index++;
						check = 0;
						num = 0;
					}
					else {
						board[index][j] = num;
						num = board[i][j];
						board[i][j] = 0;
						index++;
					}
				}
				i++;
			}
		}
		if (num) {
			board[index][j] = num;
			if (answer < num) {
				answer = num;
			}
		}
	}

	dfs(board, temp, count + 1);

	for (i = 1; i <= n; i++) {
		board[i] = temp[i];
	}
}

int main() {
	vector <vector<int>> board(21,vector<int>(21,0));
	vector <vector<int>> temp(21, vector<int>(21, 0));
	int input;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> input;
			board[i][j] = input;
		}
	}
	dfs(board, temp, 0);
	cout << answer;
}
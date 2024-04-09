#include <iostream>
#include <vector>
using namespace std;
//가로, 세로, 대각선 3경우

vector<int> board[19];
int tmp;
int col, row;

int getWinner() {
	for (col = 0; col < 19; col++) {
		for (row = 0; row < 19; row++) {
			if (board[col][row] != 0) {
				if (board[col+1][row] == board[col][row] && board[col + 2][row] == board[col][row] && board[col + 3][row] == board[col][row] && board[col + 4][row] == board[col][row]) {
					return board[col][row];
				}
				else if (board[col + 1][row + 1] == board[col][row] && board[col + 2][row+2] == board[col][row] && board[col + 3][row+3] == board[col][row] && board[col + 4][row+4] == board[col][row]) {
					return board[col][row];
				}
				else if (board[col][row+1] == board[col][row] && board[col][row+2] == board[col][row] && board[col][row+3] == board[col][row] && board[col][row+4] == board[col][row]) {
					return board[col][row];
				}
			}
		}
	}
}


int main() {
	//입력 - 오목판 완성
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			cin >> tmp;
			board[i].push_back(tmp);
		}
	}
	//연산
	int win = getWinner();
	//출력
	cout << win << "\n";
	cout << col + 1 << " " << row + 1;
	return 0;
}
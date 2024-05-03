#include <iostream>
#include <vector>
using namespace std;

const int N = 19;
const int dx[] = {-1, 0, 1, 1}; // ����, ����, �밢�� ����
const int dy[] = {1, 1, 1, 0};

char board[N][N];

bool is_valid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

bool check_win(int x, int y, char player) {
    for (int i = 0; i < 4; ++i) {
        int count = 1;
        int nx = x + dx[i], ny = y + dy[i];
        while (is_valid(nx, ny) && board[nx][ny] == player) {
            count++;
            nx += dx[i];
            ny += dy[i];
        }
        nx = x - dx[i], ny = y - dy[i];
        while (is_valid(nx, ny) && board[nx][ny] == player) {
            count++;
            nx -= dx[i];
            ny -= dy[i];
        }
        if (count >= 5) return true;
    }
    return false;
}

int main() {
    // ���� �ʱ�ȭ
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
        }
    }

    // �� ĭ�� ���� �˻�
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board[i][j] != '.') {
                if (check_win(i, j, board[i][j])) {
                    cout << board[i][j] << endl;
                    cout << i + 1 << ' ' << j + 1 << endl;
                    return 0;
                }
            }
        }
    }

    cout << "0" << endl; // �ºΰ� ���� �ʾ��� ���
    return 0;
}

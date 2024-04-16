#include <iostream>
#include <string>
using namespace std;

// 체스판의 경계를 벗어나는지 확인하는 함수
bool isOut(int x, int y) {
    return x < 0 || x > 7 || y < 0 || y > 7;
}

// 킹과 돌의 이동을 처리하는 함수
void moveKingStone(int& kingX, int& kingY, int& stoneX, int& stoneY, string move) {
    int dx[8] = { 0, 0, -1, 1, 1, 1, -1, -1 };
    int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

    int index = 0;
    if (move == "R") index = 0;
    else if (move == "L") index = 1;
    else if (move == "B") index = 2;
    else if (move == "T") index = 3;
    else if (move == "RT") index = 4;
    else if (move == "LT") index = 5;
    else if (move == "RB") index = 6;
    else if (move == "LB") index = 7;

    int nextKingX = kingX + dx[index];
    int nextKingY = kingY + dy[index];

    // 킹이 체스판을 벗어나는 경우 이동 무시
    if (isOut(nextKingX, nextKingY)) {
        return; 
    }
    else{
        // 킹이 돌과 겹치는 경우
        if (nextKingX == stoneX && nextKingY == stoneY) {
            int nextStoneX = stoneX + dx[index];
            int nextStoneY = stoneY + dy[index];

            // 돌이 체스판을 벗어나는 경우 이동 무시
            if (isOut(nextStoneX, nextStoneY)) {
                return;
            }
            else {
                kingX = nextKingX;
                kingY = nextKingY;
                stoneX = nextStoneX;
                stoneY = nextStoneY;
            }
        }
        else {
        
            kingX = nextKingX;
            kingY = nextKingY;

        }

    }   
}

int main() {
    //입력
    string kingPos, stonePos;
    cin >> kingPos >> stonePos;

    int kingX = kingPos[0] - 'A';
    int kingY = kingPos[1] - '1';
    int stoneX = stonePos[0] - 'A';
    int stoneY = stonePos[1] - '1';

    int N;
    cin >> N;

    // 계산
    for (int i = 0; i < N; i++) {
        string move;
        cin >> move;

        moveKingStone(kingX, kingY, stoneX, stoneY, move);
    }

    //출력
    cout << (char)('A' + kingY) << kingX + 1 << endl;
    cout << (char)('A' + stoneY) << stoneX + 1 << endl;

    return 0;
}

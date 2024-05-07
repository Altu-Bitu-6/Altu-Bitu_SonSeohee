#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//톱니바퀴 상태를 저장하는 클래스
class Gear {
private:
    vector<int> teeth;

public:
    Gear(const string& state) {
        for (char c : state) {
            teeth.push_back(c - '0');
        }
    }

    //시계 방향으로 회전
    void rotateClockwise() {
        int last = teeth.back();
        teeth.pop_back();
        teeth.insert(teeth.begin(), last);
    }

    //반시계 방향으로 회전
    void rotateCounterClockwise() {
        int first = teeth.front();
        teeth.erase(teeth.begin());
        teeth.push_back(first);
    }

    //해당 위치의 톱니값 반환
    int getTooth(int position) const {
        return teeth[position];
    }
};

//톱니바퀴 배열을 관리하고 회전하는 함수
void rotateGears(vector<Gear>& gears, int gearIndex, int direction) {
    //현재 톱니바퀴 회전 방향 설정
    vector<int> rotationDirection(gears.size(), 0);
    rotationDirection[gearIndex] = direction;

    //왼쪽 톱니바퀴 확인
    for (int i = gearIndex - 1; i >= 0; --i) {
        if (gears[i].getTooth(2) != gears[i + 1].getTooth(6)) {
            rotationDirection[i] = -rotationDirection[i + 1];
        }
        else {
            break;
        }
    }

    //오른쪽 톱니바퀴 확인
    for (int i = gearIndex + 1; i < gears.size(); ++i) {
        if (gears[i].getTooth(6) != gears[i - 1].getTooth(2)) {
            rotationDirection[i] = -rotationDirection[i - 1];
        }
        else {
            break;
        }
    }

    //톱니바퀴 회전
    for (size_t i = 0; i < gears.size(); ++i) {
        if (rotationDirection[i] == 1) {
            gears[i].rotateClockwise();
        }
        else if (rotationDirection[i] == -1) {
            gears[i].rotateCounterClockwise();
        }
    }
}

int main() {
    //입력
    int N;
    cin >> N;

    vector<Gear> gears;

    for (int i = 0; i < N; ++i) {
        string state;
        cin >> state;
        gears.emplace_back(state);
    }

    int K;
    cin >> K;

    //연산
    for (int i = 0; i < K; ++i) {
        int gearIndex, direction;
        cin >> gearIndex >> direction;
        rotateGears(gears, gearIndex - 1, direction);
    }

    //출력
    int score = 0;
    for (const auto& gear : gears) {
        score += gear.getTooth(0);
    }
    cout << score << endl;

    return 0;
}

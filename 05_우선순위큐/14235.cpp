#include <iostream>
#include <queue>
using namespace std;

void givePresent(int n) {
	priority_queue<int> present;
	queue<int> outp;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;

		if (temp == 0) { //아이의 경우
			if (present.empty()) { //선물 없는 경우
				outp.push(-1);
			}
			else { //선물 있는 경우
				outp.push(present.top());
				present.pop();
			}
		}
		else { //거점지의 경우
			for (int j = 0; j < temp; j++) {
				int value;
				cin >> value;
				present.push(value);
			}
		}
	}
	while (!outp.empty()) {
		cout << outp.front() << endl;
		outp.pop();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;
	//연산, 출력
	givePresent(n);
}
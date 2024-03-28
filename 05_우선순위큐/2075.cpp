#include <iostream>
#include <queue>
using namespace std;

void getNum(int n) {
	priority_queue<int> nth_max;
	int input;
	for (int i = 0; i < n*n; i++) {
		cin >> input;
		nth_max.push(input);
	}
	for (int i = 1; i < n; i++) {
		nth_max.pop();
	}
	cout << nth_max.top();
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//입력
	int n;
	cin >> n;

	//연산, 출력
	getNum(n);

	return 0;
}
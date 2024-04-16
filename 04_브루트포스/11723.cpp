#include <iostream>
#include <queue>
using namespace std;

int total, num;
int s = 0;
string order;
queue<int> outp;

void getOrder(string order, int num) {

	if (order == "add") {
		s |= (1 << num);
	}
	else if (order == "remove") {
		s &= ~(1 << num);
	}
	else if (order == "check") {
		if (s & (1 << num)) {
			outp.push(1);
		}
		else {
			outp.push(0);
		}
	}
	else if (order == "toggle") {
		if (s & (1 << num)) {
			s &= ~(1 << num);
		}
		else {
			s |= (1 << num);
		}
	}
	else if (order == "all") {
		s |= (1 << 8) - 1;
	}
	else if (order == "empty") {
		s = 0;
	}

}

int main() {
	//입력
	cin >> total;
	for (int i = 0; i < total; i++) {
		cin >> order >> num;
		getOrder(order, num);
	}
	while (!outp.empty()) {
		cout << outp.front() << endl;
		outp.pop();
	}
	return 0;

}
#include <iostream>
using namespace std;

pair<int, int> len[12];
int k, d, l;
int big, small;

void getNum() {

	for (int i = 3; i < 12; i++) {
		if (len[i].first == len[i - 2].first
			&& len[i - 1].first == len[i - 3].first) {

			big = len[i + 1].second * len[i + 2].second;
			small = len[i - 1].second * len[i - 2].second;

			break;
		}
	}

}

int main(void) {
	//입력
	cin >> k;
	for (int i = 0; i < 6; i++) {
		cin >> d >> l;
		len[i] = len[i + 6] = { d,l };
	}
	//연산
	getNum();

	//출력
	cout << k * (big - small);

	return 0;
}
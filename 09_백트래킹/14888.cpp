#include <iostream>
using namespace std;

int N;
int num[11];
int op[4];
int Min = -1000000001;
int Max = 1000000001;

void getNum(int result, int idx) {

	if (idx == N) {
		if (result < Max) {
			Max = result;
		}
		if (result > Min) {
			Min = result;
		}
		return;
	}
	
	for (int i = 0; i < 4; i++) {
		if (op[i] > 0) {
			op[i]--;
			if (i == 0) {
				getNum(result + num[idx], idx + 1);
			}
			else if(i==1){
				getNum(result - num[idx], idx + 1);
			}
			else if (i == 2) {
				getNum(result * num[idx], idx + 1);
			}
			else if (i == 3) {
				getNum(result / num[idx], idx + 1);
			}
			op[i]++;
		}
	}

	return;

}

int main() {
	//입력
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}
	//연산
	getNum(num[0], 1);
	cout << Max << '\n' << Min;

	return 0;
}
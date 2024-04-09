#include <iostream>
#include <string>
using namespace std;

void getNum(int n) {

	int index = 0;
	string title;

	for (int i = 665; ; i++) {
		title = to_string(i);

		if (title.find("666") != -1) {
			index++;
		}
		
		if (index == n) { //index가 n과 같으면 출력, 반복 종료
			cout << i << endl;
			break;
		}
	}

}

int main() {
	//입력
	int n;
	cin >> n;

	//계산, 출력
	getNum(n);
	return 0;
}
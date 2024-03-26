#include <iostream>
#include <string>
using namespace std;

int alpha[26];

//팰린드롬 가능 여부
bool isPalin() {
	int cnt = 0;
	for (int i = 0; i < 26; i++) {
		if (alpha[i] % 2 == 1) {
			cnt++;
		}
	}
	if (cnt > 1) { return false; }
	else {return true;}

}


//팰린드롬 가능 시, 결과 출력
void canPalin(string name) {
	for (int i = 0; i < name.size(); i++) {
		alpha[name[i] - 'A']++;
	}
	if (!isPalin()) {
		cout << "I'm Sorry Hansoo";
	}
	else {
		string pal;
		//첫 문자 ~ 중간
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < alpha[i] / 2; j++) {
				pal += i + 'A';
			}
		}
		//중간(홀수 있을시)
		for (int i = 0; i < 26; i++) {
			if (alpha[i] % 2) {
				pal += i + 'A';
			}
		}
		//중간 ~ 마지막 문자
		for (int i = 25; i >= 0; i--) {
			for (int j = 0; j < alpha[i] / 2; j++)
				pal += i + 'A';
		}

		cout << pal;
	}
}

int main() {
	//입력
	string name;
	cin >> name;
	//계산, 출력
	canPalin(name);

	return 0;
}

//전체 홀수 : 홀수 문자 1개까지, 중앙
//작은 문자부터
#include <iostream>
#include <deque>
using namespace std;

int N, M;
int tmp1, tmp2;
bool dodo = false;
bool su = false; //도도와 수연 승패, true가 승
deque<int> dodo_deck, su_deck, dodo_ground, su_ground, dp; //deque에서 front는 덱, 그라운드에서 위, back은 아래

//2인 2덱
//종 치는 조건 : 카드 숫자 합이 5일 때 수연(빈 그라운드 없음)/ 카드 숫자 중 5(그라운드 상관x)
//종 치면 : 상대 그라운드를 뒤집어 덱 아래로, 그 후 자신의 그라운드도 반복 - 게임 진행 순서 유지
// 승패 조건 : 덱 카드 수 0개 / M판 진행 후 덱 카드 수가 많은 사람 승리
// 카드의 숫자 : 1 ~ 5 자연수

//게임 종료 후 승자를 출력하는 함수
void getWinner(bool &dodo, bool &su) {

	if (!dodo && !su) {
		if (dodo_deck.size() == su_deck.size()) {
			dodo = true;
			su = true;
		}
		else if (dodo_deck.size() > su_deck.size()) {
			dodo = true;
		}
		else {
			su = true;
		}
	}
	if (dodo && su) {
		cout << "dosu";
	}
	else if (dodo) {
		cout << "do";
	}
	else {
		cout << "su";
	}

	exit(0);
}


//게임 한 판 후 결과를 도출 / 덱 카드 수가 0개인 경우 멈추는 함수
void stage() {

	while (true) {
		if (!dodo_deck.empty() && !su_deck.empty()) {
			dodo_ground.push_front(dodo_deck.front());
			dodo_deck.pop_front();
			su_ground.push_front(su_deck.front());
			su_deck.pop_front();
		}
		if (dodo_deck.empty() || su_deck.empty() || dodo_ground.front() + su_ground.front() == 5 || dodo_ground.front() == 5 || su_ground.front() == 5) {
			break;
		}
	}

	if (dodo_deck.empty()) {
		su = true;
		getWinner(dodo, su);
	}
	else if (su_deck.empty()) {
		dodo = true;
		getWinner(dodo, su);
	}
	else {

		//수연 승
		if (dodo_ground.front() + su_ground.front() == 5 && dodo_ground.front() != 5 && su_ground.front() != 5) {
			while (!dodo_ground.empty()) {

				su_deck.push_back(dodo_ground.front());
				dodo_ground.pop_front();
			}
			while (!su_ground.empty()) {
				su_deck.push_back(su_ground.front());
				su_ground.pop_front();
			}
		}
		//도도 승
		if (dodo_ground.front() == 5 || su_ground.front() == 5) {
			while (!su_ground.empty()) {
				dodo_deck.push_back(su_ground.front());
				su_ground.pop_front();
			}
			while (!dodo_ground.empty()) {
				dodo_deck.push_back(dodo_ground.front());
				dodo_ground.pop_front();
			}
		}
	
	}

}

int main() {
	//입력
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> tmp1 >> tmp2;
		dodo_deck.push_front(tmp1);
		su_deck.push_front(tmp2);
	}

	for (int i = 0; i < M; i++) {
		stage();
	}

	return 0;
}
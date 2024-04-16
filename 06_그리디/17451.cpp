#include <iostream>
#include <vector>
using namespace std;

//지구 0에서 시작, 행성 n까지
//속도는 줄어들기만
//속도가 거리의 양의 정수 배 시 ok

void velocity(vector<int> planet_dis, int num) {
	int velo = planet_dis[num - 1];
	for (int i = num- 2; i >= 0; i--) {
		if (velo < planet_dis[i]) {
			velo = planet_dis[i];
		}
		else {
			for (int j = 2; ; j++) {
				if (planet_dis[i] * j >= velo) {
					velo = planet_dis[i] * j;
					break;
				}
			}
		}
	}
	cout << velo;
}

int main() {
	//입력
	int num;
	cin >> num;
	vector<int> planet_dis(num);
	for (int i = 0; i < num; i++) {
		cin >> planet_dis[i];
	}
	//연산, 출력
	velocity(planet_dis, num);

	return 0;
}
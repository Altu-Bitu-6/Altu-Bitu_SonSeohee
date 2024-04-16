#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> vec;
int N;
int M;
int tmp;
int result[8];

void getList(int idx) {

	if (idx == M) {
		for (int i = 0; i < M; i++) {
			cout << result[i] << ' ';
		}
		cout << "\n";
	}
	else {
		for (int i = 0; i < vec.size() ; i++) {
			result[idx] = vec[i];
			getList(idx + 1);
		}
	}

}

int main() {
	//입력
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		vec.push_back(tmp);
	}
	//수열 정렬, 중복값 삭제
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	//연산
	getList(0);
	return 0;
}
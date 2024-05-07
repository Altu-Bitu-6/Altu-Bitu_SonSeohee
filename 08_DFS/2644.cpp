#include <iostream>
#include <vector>
using namespace std;

int n, m;
int ans;
vector<int> list[101];
int visited[101];

void getNum(int tmp, int fin, int num) {
	int next;
	visited[tmp] = 1;
	if (tmp == fin) {
		ans = num;
	}
	for (int i = 0; i < list[tmp].size(); i++) {
		next = list[tmp][i];
		if (!visited[next]) {
			getNum(next, fin, num + 1);
		}
	}
}

void print() {
	if (ans == 0) {
		cout << "-1";
	}
	else {
		cout << ans;
	}
}

int main() {
	//입력
	int a, b;
	int tmp1, tmp2;
	cin >> n >> a >> b >> m;

	for (int i = 0; i < m; i++) {
		cin >> tmp1 >> tmp2;
		list[tmp1].push_back(tmp2);
		list[tmp2].push_back(tmp1);
	}
	//연산
	getNum(a, b, 0);
	//출력
	print();

	return 0;
}
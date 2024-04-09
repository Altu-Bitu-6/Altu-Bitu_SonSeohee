#include <iostream>
#include <vector>
using namespace std;

vector<int> comp[101];
bool inf[101];
int cnt = 0;

void isInfected(int vir) {
	int tmp = 0;
	inf[vir] = true;
	for (int i = 0; i < comp[vir].size(); i++) {
		tmp = comp[vir][i];
		if (!inf[tmp]) {
			isInfected(tmp);
			cnt++;
		}
	}
}

int main() {
	//입력
	int num, con;
	cin >> num >> con;
	for (int i = 0; i < con; i++) {
		int a, b;
		cin >> a >> b;
		comp[a].push_back(b);
		comp[b].push_back(a);
	}
	//연산
	isInfected(1);
	//출력
	cout << cnt;

	return 0;
}
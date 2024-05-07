#include <iostream>
#include <set>

using namespace std;

set<string> s;
int cnt;
string in;

void  getNum() {
	cin >> in;
	if (s.find(in) != s.end()) {
		cnt++;
	}
}

int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> in;
		s.insert(in);
	}

	for (int i = 0; i < m; i++) {  // s�� in ������ cnt++
		getNum();
	}

	cout << cnt;

	return 0;
}
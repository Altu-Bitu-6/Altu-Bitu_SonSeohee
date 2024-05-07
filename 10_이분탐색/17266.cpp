#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
//처음과 끝에 가로등 있음 : 모든 거리 2분의1
//처음과 끝에 가로등 모두 없음 : 사이 거리 2분의1, 끝거리 그대로

int n, m;

int getPos(int n, int m, vector<int> pos) {// 4, 2, pos
	int tmp;
	vector<int> dist;
	dist.push_back(pos[0]); //첫값은 그대로 넣기
	for (int i = 0; i < m ; i++) {
		tmp = ceil((double)(pos[i + 1] - pos[i])/2);
		dist.push_back(tmp); //사이값은 2분의1
	}
	tmp = n - pos[m];
	dist.push_back(tmp);//끝값 그대로 넣기

	//for (int i = 0; i < dist.size(); i++) {cout <<"dist : " << dist[i] << "\n";}

	sort(dist.begin(), dist.end());
	reverse(dist.begin(), dist.end());

	return dist[0];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tmp;

	//입력
	cin >> n >> m;
	int m1 = m -1;
	vector<int> pos;
	while (m--) {
		cin >> tmp;
		pos.push_back(tmp);
	}

	//연산, 출력
	cout << getPos(n, m1, pos);

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 길이 짧은 게 먼저
// 길이 같을 때 : 숫자 합이 작은 거 먼저
// 길이 같고 숫자 합 같을 때 : 알파벳 순

int n;
vector<string> v;
string tmp;

int getSum(string s) {
	int sum = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			sum += s[i] - '0';
		}
	}
	return sum;
}

bool getOrder(string s1, string s2) {
	if (s1.size() != s2.size()) {
		return s1.size() < s2.size();
	}
	else if(getSum(s1) == getSum(s2)){
		return s1 < s2;
	}
	else {
		return getSum(s1) < getSum(s2);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end(), getOrder);

	for (int i = 0; i < n; i++) {
		cout << v[i] << "\n";
	}
	return 0;

}
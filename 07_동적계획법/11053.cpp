#include <iostream>
#include <vector>
using namespace std;

int a[1001], dp[1001];

void getLength(int n) {
	int length = 0;
	int idx = 0;
	dp[idx] = a[0];
	for (int i = 1; i < n; i++) {
		if (dp[idx] < a[i]) {
			idx++;
			dp[idx] = a[i];
			length++;
		}
	}
	cout << length+1;
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	getLength(n);

	return 0;
}
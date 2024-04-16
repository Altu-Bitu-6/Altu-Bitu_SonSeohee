#include <iostream>
#include <vector>

using namespace std;

void getRoulette(int n, int k) {
	char arr[25];
	int index = 0;

	for (int i = 0; i < n; i++) {arr[i] = '?';}
	for (int i = 0; i < k; i++) {
		int num;
		char alph;
		cin >> num >> alph;
		if ((index + num) > n-1) {
			index = index + num - n;
		}
		else { index += num; }

		if (arr[index] != '?' && arr[index] != alph) {
			arr[0] = NULL;
		}
		else {
			arr[index] = alph;
		}

	}

	if (arr[0] == NULL) {
		cout << "!";
	}
	else {
		for (int i = n - 1; i >= 0; i--) {
			cout << arr[i];
		}
	}
	
}

int main() {
	int N, K;
	cin >> N >> K;
	
	getRoulette(N, K);

	return 0;
}
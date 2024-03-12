#include <iostream>
#include <vector>

using namespace std;

//에라토스테네스의 체로 소수 구하는 함수
vector<int> getPrime(int a) {
	vector<bool> isPrime(a + 1, true);
	vector<int> prime;
	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i <= a; ++i) {
		if (isPrime[i]) {
			prime.push_back(i);
			for (int j = i * 2; j <= a; j += i) {
				isPrime[j] = false;
			}
		}
	}
	return prime;
}

//골드바흐의 추측 검증
void goldbachConj(int a, const vector<int> prime) {
	int x, y;
	for (int i = 0; i < prime.size(); ++i) {
		if (prime[i] > a / 2) { break; }
		int complement = a - prime[i];
		bool isComplementPrime = true;
		for (int j = 2; j * j <= complement; ++j) {
			if (complement % j == 0) {
				isComplementPrime = false;
				break;
			}
		}
		if (isComplementPrime) {
			x = prime[i];
			y = complement;
		}
	}
	cout << a << " = " << x << " + " << y << endl;
}

int main() {
	vector<int> prime = getPrime(1000000);//백만 이하 소수 구함

	vector<int> input;
	while (true) {
		int n;
		cin >> n;
		if (n == 0) { break; }
		input.push_back(n);
	}

	for(int n : input){
		goldbachConj(n, prime);
	}

	return 0;
}
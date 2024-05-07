#include <iostream>
#include <vector>

using namespace std;

//�����佺�׳׽��� ü�� �Ҽ� ���ϴ� �Լ�
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

//�������� ���� ����
void goldbachConj(int a, const vector<int> prime) {
	int x = 0;
	int y = 0;
	for (int i = 1; i < prime.size(); i++) {
		if (prime[i] > a / 2) { break; }
		int complement = a - prime[i];
		bool isComplementPrime = true;
		/*for (int j = 2; j * j <= complement; ++j) {
			if (complement % j == 0) {
				isComplementPrime = false;
				break;
			}
		}*/

		for (int j = 0; j < prime.size(); j++) {
			if (prime[j] == complement) {
				break;
			}
			else if (prime[j] > complement) {
				isComplementPrime = false;
			}
		}

		if (isComplementPrime) {
			x = prime[i];
			y = complement;
			break;
		}
	}
	cout << a << " = " << x << " + " << y << "\n";
}

int main() {
	vector<int> prime = getPrime(1000000);//�鸸 ���� �Ҽ� ����
	vector<int> input;

	while (true) {
		int n;
		cin >> n;
		if (n == 0) { break; }
		input.push_back(n);
	}

	for (int z : input) {
		goldbachConj(z, prime);
	}

	return 0;
}
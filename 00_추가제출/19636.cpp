#include <iostream>
#include <cmath>
using namespace std;

int w, b, t, day, d_in, d_out;

void getDiet() {
	int w1 = w;
	int w2 = w;
	int b1 = b;
	int b2 = b;

	for (int i = 0; i < day; i++) {
		w1 += d_in - (b1 + d_out);
		w2 += d_in - (b2 + d_out);

		if (abs(d_in - (b2 + d_out)) > t) {
			b2 += float((d_in - (b2 + d_out)) / 2.0);
		}
	}

	if (w1 <= 0) {
		// m1�� i0���� ��ȭ���� �ʰ�, i0�� 0���� ũ�Ƿ� ���ʴ�緮�� 0kcal ���ϰ� ���� ����
		cout << "Danger Diet\n";
	}
	else {
		cout << w1 << " " << b << "\n";
	}

	if (w2 <= 0 || b2 <= 0) {
		cout << "Danger Diet";
	}
	else {
		cout << w2 << " " << b2 << " ";
		if (b2 < b) {
			cout << "YOYO";
		}
		else {
			cout << "NO";
		}
	}
}

int main() {

	cin >> w >> b >> t;
	cin >> day >> d_in >> d_out;

	getDiet();

	return 0;
}
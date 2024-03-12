#include <iostream>
#include <algorithm>
using namespace std;

//분모의 최대공약수를 구하는 함수
int gcd(int a, int b) {
    if (a < b) { swap(a, b); }
    if (b == 0) { return a; }
    return gcd(b, a % b);
}

//더한 분수를 약분하는 함수
void simplifyFrac(int a, int b) {
    int div = gcd(a, b);
    a /= div;
    b /= div;
}

int main() {

    int num1, den1, num2, den2;
    cin >> num1 >> den1;
    cin >> num2 >> den2;

    int newnum, newden;
    newnum = num1 * den2 + num2 * den1; //일단 더함
    newden = den1 * den2;

    simplifyFrac(newnum, newden);

    cout << newnum << " " << newden;

}
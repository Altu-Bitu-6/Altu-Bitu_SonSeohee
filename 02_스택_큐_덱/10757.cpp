#include <iostream>
#include <vector>

using namespace std;

vector<int> add(vector<int>& num1, vector<int>& num2) {
    vector<int> result;
    int carry = 0;

    int i = num1.size() - 1;
    int j = num2.size() - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0) {
            sum += num1[i];
            i--;
        }
        if (j >= 0) {
            sum += num2[j];
            j--;
        }
        result.insert(result.begin(), sum % 10);
        carry = sum / 10;
    }

    return result;
}

int main() {
    string A_str, B_str;
    cin >> A_str >> B_str;

    vector<int> A, B;
    for (char c : A_str) {
        A.push_back(c - '0');
    }
    for (char c : B_str) {
        B.push_back(c - '0');
    }

    vector<int> sum = add(A, B);

    for (int digit : sum) {
        cout << digit;
    }
    cout << endl;

    return 0;
}
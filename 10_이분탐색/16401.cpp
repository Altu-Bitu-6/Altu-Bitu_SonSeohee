#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n, input;
vector<int> snack;

int isMax(int min, int max, vector<int>& arr) {
    int length= 0;
    while (min <= max) {
        int mid = (min + max) / 2;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += arr[i] / mid;
        }

        if (cnt >= m) {
            length = mid;
            min = mid + 1;
        }
        else {
            max = mid - 1;
        }
    }

    return length;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력
    cin >> m >> n; //조카, 과자
    for (int i = 0; i < n; i++) {
        cin >> input;
        snack.push_back(input);
    }

    sort(snack.begin(), snack.end());

    //출력
    cout << isMax(1, snack[n-1], snack);

    return 0;
}
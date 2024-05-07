#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isHave(int left, int right, int target, vector<int>& arr) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) {
            return 1;
        }
        else if (arr[mid] > target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, input;

    //입력
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    //입력
    cin >> m;
    while (m--) {
        cin >> input;
        //연산 & 출력
        cout << isHave(0, n - 1, input, arr) << ' ';
    }

    return 0;
}
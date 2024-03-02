#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> josephusPermutation(int N, int K) {
    vector<int> result;
    queue<int> q;

    for (int i = 1; i <= N; ++i) {
        q.push(i);
    }

    while (!q.empty()) {
        for (int i = 0; i < K - 1; ++i) {
            int front = q.front();
            q.pop();
            q.push(front);
        }
        result.push_back(q.front());
        q.pop();
    }

    return result;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> permutation = josephusPermutation(N, K);

    cout << "< ";
    for (int i = 0; i < permutation.size(); ++i) {
        if (i < permutation.size() - 1) cout << permutation[i] << ", ";
        else cout << permutation[i];
    }
    cout << ">";
    cout << endl;


    return 0;
}
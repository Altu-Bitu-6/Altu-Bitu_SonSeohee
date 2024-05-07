#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isSimilar(const string& word1, const string& word2) {
    // 각 알파벳의 등장 횟수를 세는 배열
    vector<int> count1(26, 0), count2(26, 0);

    // 첫 번째 단어의 알파벳 등장 횟수를 센다
    for (char c : word1) {
        count1[c - 'A']++;
    }

    // 두 번째 단어의 알파벳 등장 횟수를 센다
    for (char c : word2) {
        count2[c - 'A']++;
    }

    // 등장 횟수가 같은지 확인
    if (count1 == count2) return true;

    // 한 문자를 더하거나 빼는 경우 확인
    int diff_count = 0;
    for (int i = 0; i < 26; ++i) {
        if (count1[i] != count2[i]) {
            if (count1[i] - count2[i] == 1 || count1[i] - count2[i] == -1) {
                diff_count++;
            }
            else {
                return false;
            }
        }
    }
    return diff_count == 1;
}

int main() {
    //입력
    int n;
    cin >> n;

    string first_word;
    cin >> first_word;

    int similar_count = 0;

    for (int i = 1; i < n; ++i) {
        string word;
        cin >> word;

        //연산
        if (isSimilar(first_word, word))
            similar_count++;
    }

    //출력
    cout << similar_count << endl;

    return 0;
}


//1. 같은 구성을 같는 경우, 모든 알파벳의 등장 횟수가 같다
//2. 한 문자를 더하거나 빼면 같은 구성을 갖는 경우, 한 알파벳만 등장 횟수가 1 차이
//3. 한 문자를 다른 문자로 바꾸면 같은 구성을 갖는 경우, 두 알파벳의 등장 횟수가 각각 1, -1 차이
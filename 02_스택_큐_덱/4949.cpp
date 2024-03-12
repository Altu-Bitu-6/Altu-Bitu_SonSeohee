#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isBalanced(string s) {
    stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '[') {
            st.push(c);
        } else if (c == ')' || c == ']') {
            if (st.empty()) {
                return false;
            } else if ((c == ')' && st.top() == '(') || (c == ']' && st.top() == '[')) {
                st.pop();
            } else {
                return false;
            }
        }
    }

    return st.empty();
}

int main() {
    string input;
    stack<string> str;

    while (true) {
        getline(cin, input);
        
        if (input == ".")
            break;

        if (isBalanced(input)) {
            str.push("yes");
        } else {
            str.push("no");
        }

    }

    while (!str.empty()) {
        cout << str.top() << endl;
            str.pop();
    }

    return 0;
}
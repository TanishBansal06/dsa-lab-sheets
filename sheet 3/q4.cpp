#include <iostream>
#include <stack>
using namespace std;
int prec(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return -1;
}
string infixtopostfix(string s) {
    stack<char> st;
    string ans = "";
    for (char c : s) {
        if (isalnum(c)) ans += c;
        else if (c == '(') st.push(c);
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && prec(st.top()) >= prec(c)) {
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    return ans;
}
int main() {
    string s;
    cin >> s;
    cout << infixtopostfix(s);
}

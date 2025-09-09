#include <iostream>
#include <stack>
using namespace std;
bool isBalanced(string exp) {
    stack<char> st;
    for (char ch : exp) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (st.empty()) return false;
            char top = st.top();
            st.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }
    return st.empty();
}
int main() {
    string exp;
    cout << "enter expression";
    cin >> exp;

    if (isBalanced(exp))
        cout << "balanced\n";
    else
        cout << "not balanced\n";

    return 0;
}

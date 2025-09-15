#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main() {
    queue<int> q;
    q.push(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    stack<int> st;
    int need = 1;
    int n = q.size();
    while (!q.empty()) {
        if (q.front() == need) {
            need++;
            q.pop();
        }
        else if (!st.empty() && st.top() == need) {
            st.pop();
            need++;
        }
        else {
            st.push(q.front());
            q.pop();
        }
    }
    while (!st.empty() && st.top() == need) {
        st.pop();
        need++;
    }

    if (need == n + 1) cout << "Yes";
    else cout << "No";
}

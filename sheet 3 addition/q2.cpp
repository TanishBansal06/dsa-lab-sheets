#include <iostream>
#include <stack>
#include <climits>
using namespace std;
class Stackk {
    stack<int> st;
public:
    void push(int x) {
        st.push(x);
    }
    void pop() {
        if (!st.empty()) {
            st.pop();
        }
    }
    int top() {
        if (st.empty()) return -1;
        return st.top();
    }
    int getMin() {
        if (st.empty()) return -1;
        int m = INT_MAX;
        stack<int> temp = st;
        while (!temp.empty()) {
            m = min(m, temp.top());
            temp.pop();
        }
        return m;
    }
    bool empty() {
        return st.empty();
    }
};
int main() {
    Stackk s;
    s.push(5);
    s.push(3);
    s.push(7);
    s.push(2);
    cout << s.getMin() << endl; 
    s.pop();
    cout << s.getMin() << endl;
    s.pop();
    cout << s.getMin() << endl;
    return 0;
}

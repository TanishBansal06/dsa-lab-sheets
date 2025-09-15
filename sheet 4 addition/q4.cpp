#include <iostream>
#include <queue>
using namespace std;
int main() {
    queue<int> q;
    q.push(11);
    q.push(5);
    q.push(4);
    q.push(21);
    int n = q.size();
    for (int i = 0; i < n; i++) {
        int sz = q.size();
        int first = q.front();
        q.pop();
        q.push(first);
        int minVal = first;
        for (int j = 1; j < sz; j++) {
            int x = q.front();
            q.pop();
            if (x < minVal) minVal = x;
            q.push(x);
        }
        for (int j = 0; j < sz; j++) {
            int x = q.front();
            q.pop();
            if (x == minVal) continue;
            q.push(x);
        }
        q.push(minVal);
    }
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
    vector<int> students = {1,1,0,0};
    vector<int> sandwiches = {0,1,0,1};
    queue<int> q;
    for (int x : students) 
    {
        q.push(x);
    }
    int n = sandwiches.size();
    int i = 0;
    int count = 0;
    while (!q.empty() && count < q.size()) {
        if (q.front() == sandwiches[i]) {
            q.pop();
            i++;
            count = 0;
        } else {
            q.push(q.front());
            q.pop();
            count++;
        }
    }
    cout << q.size();
}

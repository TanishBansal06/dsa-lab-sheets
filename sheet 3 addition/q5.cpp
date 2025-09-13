#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) 
      {
        cin >> A[i];
      }
    stack<int> S;
    vector<int> B;
    int need = 1;
    for (int i = 0; i < n; i++) {
        S.push(A[i]);
        while (!S.empty() && S.top() == need) {
            B.push_back(S.top());
            S.pop();
            need++;
        }
    }
    if (B.size() == n) 
    {
      cout << "yes";
    }
    else {
      cout << "no";
    }
    return 0;
}

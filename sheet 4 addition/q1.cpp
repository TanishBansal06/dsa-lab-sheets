#include <iostream>
using namespace std;
string tobinary(int x) {
    string s = "";
    while (x > 0) {
        s = char('0' + (x % 2)) + s;
        x /= 2;
    }
    return s;
}
int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << tobinary(i) << " ";
    }
    return 0;
}

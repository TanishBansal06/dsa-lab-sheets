#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
bool canSplit(string s) {
    unordered_set<char> seen;
    for (char c : s) {
        if (seen.count(c)) 
            return true;
        seen.insert(c);
    }
    return false;
}
int main() {
    string s;
    cin >> s;
    if (canSplit(s))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
bool areArraysEqual(vector<int>& a, vector<int>& b) {
    if (a.size() != b.size())
        return false;
    unordered_map<int, int> freq;
    for (int x : a)
        freq[x]++;
    for (int x : b) {
        if (freq.find(x) == freq.end())  
            return false;
        freq[x]--;

        if (freq[x] < 0)        
            return false;
    }
    return true;
}
int main() {
    vector<int> a = {1, 2, 5, 4, 0};
    vector<int> b = {2, 4, 5, 0, 1};
    cout << (areArraysEqual(a, b) ? "true" : "false");
    return 0;
}

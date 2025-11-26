#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
bool hasPairWithSum(vector<int>& arr, int target) {
    unordered_set<int> seen;
    for (int x : arr) {
        int needed = target - x;
        if (seen.count(needed)) {
            return true;
        }
        seen.insert(x);
    }
    return false; 
}
int main() {
    vector<int> arr = {0, -1, 2, -3, 1};
    int target = -2;
    cout << (hasPairWithSum(arr, target) ? "true" : "false");
    return 0;
}

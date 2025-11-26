#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
bool containsduplicate(vector<int>& nums) {
    unordered_set<int> seen;
    for (int n : nums) {
        if (seen.count(n)) {
            return true;  
        }
        seen.insert(n);
    }
    return false;   
}
int main() {
    vector<int> nums = {1, 2, 3, 1};
    if (containsduplicate(nums))
        cout << "true";
    else
        cout << "false";
    return 0;
}

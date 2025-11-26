#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main() {
    vector<int> nums = {2, 3, 2, 4, 3, 2};
    unordered_map<int, int> freq;  
    for (int n : nums) {
        freq[n]++;  
    }
    for (auto it : freq) {
        cout << it.first << " → " << it.second << " times" << endl;
    }
    return 0;
}

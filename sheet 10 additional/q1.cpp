#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int mostFrequentLargest(vector<int>& arr) {
    unordered_map<int, int> freq;
    for (int x : arr) {
        freq[x]++;
    }
    int maxFreq = 0;
    int result = -1;
    for (auto &p : freq) {
        int value = p.first;
        int count = p.second;
        if (count > maxFreq) {
            maxFreq = count;
            result = value;
        }
        else if (count == maxFreq && value > result) {
            result = value; 
        }
    }
    return result;
}
int main() {
    vector<int> arr = {1, 2, 2, 4, 1};
    cout << mostFrequentLargest(arr);
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;
void improvedSelectionSort(vector<int>& arr) {
    int n = arr.size();
    int start = 0, end = n - 1;

    while (start < end) {
        int minIndex = start, maxIndex = start;

        for (int i = start; i <= end; i++) {
            if (arr[i] < arr[minIndex])
                minIndex = i;
            if (arr[i] > arr[maxIndex])
                maxIndex = i;
        }
        swap(arr[start], arr[minIndex]);
        if (maxIndex == start)
            maxIndex = minIndex;
        swap(arr[end], arr[maxIndex]);
        start++;
        end--;
    }
}
int main() {
    vector<int> arr = {29, 10, 14, 37, 13, 5, 42};
    cout << "Original Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    improvedSelectionSort(arr);
    cout << "Sorted Array:   ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    return 0;
}

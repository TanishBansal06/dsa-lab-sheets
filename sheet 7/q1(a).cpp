#include <iostream>
#include <algorithm> 
using namespace std;
int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int n = 5;
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[min], arr[i]);
    }
    cout << "sorted array ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

#include <iostream>
using namespace std;
int main() {
    int arr[5] = {5, 4, 3, 2, 1};
    int n = 5;
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i;
        while (j > 0 && arr[j-1] > temp) {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = temp;
    }
    cout << "sorted array ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

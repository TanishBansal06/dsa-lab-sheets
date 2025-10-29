#include <iostream>
using namespace std;
int partition(int arr[], int st, int end) {
    int pivot = arr[end];
    int idx = st - 1;         
    for (int j = st; j < end; j++) {
        if (arr[j] <= pivot) { 
            idx++;
            swap(arr[idx], arr[j]);
        }
    }
    idx++;
    swap(arr[idx], arr[end]);
    return idx; 
}
void quickSort(int arr[], int st, int end) {
    if (st < end) {
        int pivIdx = partition(arr, st, end);
        quickSort(arr, st, pivIdx - 1);  
        quickSort(arr, pivIdx + 1, end); 
    }
}
int main() {
    int arr[] = {2, 1, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

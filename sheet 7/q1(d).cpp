#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &A, int st, int mid, int end) {
    vector<int> temp;
    int i = st, j = mid + 1;
    while (i <= mid && j <= end) {
        if (A[i] <= A[j]) {
            temp.push_back(A[i]);
            i++;
        } else {
            temp.push_back(A[j]);
            j++;
        }
    }
    while (i <= mid) {
        temp.push_back(A[i]);
        i++;
    }
    while (j <= end) {
        temp.push_back(A[j]);
        j++;
    }
    for (int idx = 0; idx < temp.size(); idx++) {
        A[st + idx] = temp[idx];
    }
}
void mergeSort(vector<int> &A, int st, int end) {
    if (st < end) {
        int mid = st + (end - st) / 2;
        mergeSort(A, st, mid);
        mergeSort(A, mid + 1, end);
        merge(A, st, mid, end);
    }
}
int main() {
    vector<int> arr = {5, 4, 3, 2, 1};
    int n = arr.size();
    mergeSort(arr, 0, n - 1);
    cout << "sorted array ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

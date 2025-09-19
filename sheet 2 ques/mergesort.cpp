#include <iostream>
using namespace std;
int mergeAndCount(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int left[n1], right[n2];
    for (int i = 0; i < n1; i++) left[i] = arr[l+i];
    for (int j = 0; j < n2; j++) right[j] = arr[m+1+j];

    int i=0, j=0, k=l, invCount=0;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
            invCount += (n1 - i);  
        }
    }
    while (i < n1) arr[k++] = left[i++];
    while (j < n2) arr[k++] = right[j++];

    return invCount;
}
int countInversionsUtil(int arr[], int l, int r) {
    int invCount = 0;
    if (l < r) {
        int m = (l+r)/2;
        invCount += countInversionsUtil(arr, l, m);
        invCount += countInversionsUtil(arr, m+1, r);
        invCount += mergeAndCount(arr, l, m, r);
    }
    return invCount;
}
int main() {
    int arr[] = {2, 4, 1, 3, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    int invCount = countInversionsUtil(arr, 0, n-1);

    cout << "Number of inversions = " << invCount << endl;
    return 0;
}

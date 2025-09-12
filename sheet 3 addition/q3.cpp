#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) 
      {
        cin >> arr[i];
      }
    for (int i = 0; i < n; i++) {
        int ans = -1;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                ans = arr[j];
                break;
            }
        }
        cout << ans << " ";
    }
    return 0;
}

#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int temp[n];
    for (int i = 0; i < n; i++) 
      {
        cin >> temp[i];
      }
    int ans[n];
    for (int i = 0; i < n; i++) {
        ans[i] = 0;
        for (int j = i + 1; j < n; j++) {
            if (temp[j] > temp[i]) {
                ans[i] = j - i;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) 
      {
        cout << ans[i] << " ";
      }
    return 0;
}

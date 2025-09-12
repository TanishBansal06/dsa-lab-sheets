#include <iostream>
#include <vector>
using namespace std;
int count(vector<int> &arr, int k)
{
    int n = arr.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (abs(arr[i] - arr[j]) == k)
            {
                cnt += 1;
            }
        }
    }
    return cnt;
}
int main()
{
    vector<int> arr = {1, 3, 2, 4, 3};
    int k;
    cout<<"enter value of k"<<endl;
    cin>>k;

    cout << count(arr, k);
    return 0;
}

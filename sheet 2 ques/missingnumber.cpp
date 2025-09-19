// BY LINEAR SEARCH
#include <iostream>
using namespace std;

int findMissingLinear(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] != i + 1)
        {
            return i + 1; 
        }
    }
    return n; 
}
int main()
{
    int n = 7;
    int arr[n] = {1, 2, 3, 5, 6, 7};

    cout << "Missing number : " << findMissingLinear(arr, n) << endl;

    return 0;
}
// BY BINARY SEARCH
#include <iostream>
using namespace std;
int findMissingBinary(int arr[], int n)
{
    int left = 0, right = n - 2;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == mid + 1)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return left + 1;
}
int main()
{
    int arr[] = {1, 2, 3, 5, 6, 7};
    int n = 7;

    cout << "Missing number (Binary Search): " << findMissingBinary(arr, n) << endl;

    return 0;
}

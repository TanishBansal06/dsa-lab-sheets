
#include <iostream>
#include <vector>
using namespace std;
int binarySearch(vector<int> arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}
int main()
{
    vector<int> numbers = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int target;
    cout << "enter a target:";
    cin >> target;

    int index = binarySearch(numbers, target);

    if (index != -1)
    {
        cout << "Element " << target << " found at index " << index << endl;
    }
    else
    {
        cout << "Element not found." << endl;
    }
    return 0;
}
